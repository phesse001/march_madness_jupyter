#include "Simulator.h"

vector<string> labels;
vector<Team*> teamCollection;
vector<Team> resultVector;
vector<int> x_axis;
vector<int> y_axis;
map<int, Team*> teamMap;
Matrix<double, Dynamic, Dynamic> gameMatrix;
VectorXd scores;
VectorXd solutionVector;
vector<int> correct;
int numGamesPlayed;
int numTeams;
const int HIGH_MARGIN = 21;
const double HIGH_MARGIN_SCALE = .8;

void run(int home_field_advantage, bool apply_scaling){
    createTeams(string("/home/patrick/march_madness_jupyter/Data/NCAABasketballTeams.txt"));
    loadGames(string("/home/patrick/march_madness_jupyter/Data/NCAABasketballGames.txt"), home_field_advantage, apply_scaling);
    solutionVector = gameMatrix.lu().solve(scores);

    map<int, Team*>::iterator itr;
    for(itr = teamMap.begin(); itr != teamMap.end(); ++itr){
        itr->second->addRank(solutionVector.row(itr->second->getId() -1).value());
        resultVector.push_back(*(itr->second));
    }

     sort(resultVector.begin(), resultVector.end());
     vector<Team>::iterator itr2;
     for(itr2 = resultVector.end() - 1; itr2 != resultVector.begin() - 1 ; --itr2){
        cout << itr2->getId() << itr2->getName() << endl;
     }
}
void createTeams(string teamData) {
    string id, name;
    ifstream teams (teamData);
    if(teams.is_open()){
        while (getline(teams, id, ',')){
            getline(teams, name, '\n');
            int idNum = stoi(id);
            Team* tempTeam = new Team(name, idNum);
            teamCollection.push_back(tempTeam);
            teamMap.insert(pair<int, Team*>(idNum, tempTeam));
            numTeams++;
        }
        teams.close();
    }
    else cout << "Unable to open file";
}

void loadGames(string gameData, int home_field_advantage, bool apply_scaling) {
    gameMatrix = Matrix<double, Dynamic, Dynamic>::Zero(numTeams , numTeams);
    scores = VectorXd::Zero(numTeams);

    string days, date, team1, field1, score1, team2, field2, score2;
    fstream games(gameData);
    if(games.is_open()){
        while(getline(games, days, ',')){
            getline(games, date, ',');
            getline(games, team1, ',');
            getline(games, field1, ',');
            getline(games, score1, ',');
            getline(games, team2, ',');
            getline(games, field2, ',');
            getline(games, score2, ' ');
            getline(games, score2, ' ');

            int daysInt = stoi(days);
            int team_1_Id = stoi(team1);
            int team_2_Id = stoi(team2);
            int team_1_score = stoi(score1);
            int team_2_score = stoi(score2);
            Game tempGame(daysInt, teamMap.at(team_1_Id), teamMap.at(team_2_Id), team_1_score, team_2_score);
            teamMap.at(team_1_Id)->addGame(&tempGame);
            teamMap.at(team_2_Id)->addGame(&tempGame);
            numGamesPlayed++;

            /*
             * Edit game score based on flag.
             * flag = 1: 4 is added to home team score
             */
            if(stoi(field1) == 1){
                team_1_score += home_field_advantage;
            }
            if(stoi(field2) == 1){
                team_2_score += home_field_advantage;
            }

            populateMatrix(team_1_Id, team_2_Id, team_1_score, team_2_score, apply_scaling);
            for(int i = 0; i < numTeams; i++){
                gameMatrix.row(numTeams - 1).col(i) << 1;
            }
            scores.row(numTeams - 1) << 0;
        }
    }
    else cout << "Unable to open file";
}

void populateMatrix(int team1Index, int team2Index, int team_1_score, int team_2_score, bool apply_scaling) {
    gameMatrix.row(team1Index - 1 ).col(team2Index - 1) << -1;
    gameMatrix.row(team2Index -1 ).col(team1Index -1) <<  -1;
    gameMatrix.row(team1Index -1 ).col(team1Index -1) <<  teamMap.at(team1Index)->getNumGamesPlayed();
    gameMatrix.row(team2Index -1 ).col(team2Index -1) <<  teamMap.at(team2Index)->getNumGamesPlayed();
    //implementation of scaling if predicted margin is greater then 21
    if(abs(team_1_score - team_2_score) < HIGH_MARGIN || apply_scaling == false) {
        if (team_1_score > team_2_score) {
            int temp = scores.row(team1Index - 1).value();
            scores.row(team1Index - 1) << temp + (team_1_score - team_2_score);
            temp = scores.row(team2Index - 1).value();
            scores.row(team2Index - 1) << temp + (team_2_score - team_1_score);
        } else {
            int temp = scores.row(team2Index - 1).value();
            scores.row(team2Index - 1) << temp + (team_2_score - team_1_score);
            temp = scores.row(team1Index - 1).value();
            scores.row(team1Index - 1) << temp + (team_1_score - team_2_score);
        }
    }
    else{

        if(team_1_score > team_2_score)
        {
            int pre_margin = team_1_score - team_2_score;
            int post_margin = HIGH_MARGIN + (1/HIGH_MARGIN_SCALE) * (pow((pre_margin - 20),HIGH_MARGIN_SCALE)-1);
            int temp = scores.row(team1Index - 1).value();
            scores.row(team1Index - 1) << temp + post_margin;
            temp = scores.row(team2Index - 1).value();
            scores.row(team2Index - 1) << temp - post_margin;
        } else{
            int pre_margin = team_2_score - team_1_score;
            int post_margin = HIGH_MARGIN + (1/HIGH_MARGIN_SCALE) * (pow((pre_margin - 20),HIGH_MARGIN_SCALE)-1);
            int temp = scores.row(team2Index - 1).value();
            scores.row(team2Index - 1) << temp + post_margin;
            temp = scores.row(team1Index - 1).value();
            scores.row(team1Index - 1) << temp - post_margin;
        }

    }
}

void constructCorrectVector(string filename)
{
string id;
fstream rankings(filename);
    if(rankings.is_open()){
        while(getline(rankings,id,'\n')){
            int id_num = stoi(id);
            correct.push_back(id_num);
        }
    }
}

void printVect(std::vector<int> vect)
{
    for(int i = 0; i < vect.size(); i++)
	{
	    cout << vect.at(i) << '\n';
	}
}

void printVect(std::vector<Team> vect)
{
    for(int i = 0; i < vect.size(); i++)
	{
	    cout << vect.at(i).getId() << '\n';
	}
}

void createLabels()
{
for(int i = resultVector.size()-1; i >= 288; i--)
{
    labels.push_back(resultVector.at(i).getName());
}
}

double constructAxes()
{
x_axis.clear();
y_axis.clear();
int count = 0;
double sum = 0;
bool found = false;
for(int i = 1; i < 65; i++)
{
    x_axis.push_back(i);
}
for(int i = resultVector.size()-1; i >= 0; i--)
{
    found = false;
    //cout << resultVector.at(i).getId() << endl;
    int current_value = resultVector.at(i).getId();
    for(int j = 1; j<65; j++)
    {
        if(current_value == correct.at(j-1))
        {
            found = true;
            y_axis.push_back(j);
            sum += pow(j - x_axis.at(count),2);
            count += 1;
        }
    }
}
    return sum;
}

