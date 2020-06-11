//
// Created by wilmot on 10/6/2019.
//

#ifndef MARCH_MADNESS_SIMULATOR_SIMULATOR_H
#define MARCH_MADNESS_SIMULATOR_SIMULATOR_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "./eigen/Eigen/Core"
#include "./eigen/Eigen/Dense"
#include "Team.h"
#include <bits/stdc++.h>
#include <iterator>
#include <algorithm>

class Team;
class Game;
using namespace std;
using namespace Eigen;

/**
 * Collection holding all teams.
 */
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

/**
 * Method responsible for converting team text file into team objests
 * @param teamData
 */
void createTeams(string teamData);

void loadGames(string gameData, int flag, bool apply_scaling);

void run(int flag, bool apply_scaling);

void populateMatrix(int team_1_Id, int team_2_Id, int team_1_score, int team_2_score, bool apply_scaling);

void constructCorrectVector(string filename);

void printVector(std::vector<int> vect);

void printVector(std::vector<Team> vect);

double constructAxes();

double computeSSE(std::vector<int> vect1, std::vector<Team> vect2);

void createLabels();

#endif //MARCH_MADNESS_SIMULATOR_SIMULATOR_H
