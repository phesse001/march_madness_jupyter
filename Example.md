---
layout: default
title: March Madness Example
nav_order: 3
---
# March Madness Simulation

This example is a sports ranking simulation based on the 1998 undergraduate thesis of Kenneth Massey. The application uses historical game data and linear algebra to predict the placement of teams in the NCAA basketball tournament. The application takes 2 parameters, the additional points added to teams playing home and weighting games based on margin of points. The experiment will vary these parameters and assess its effect on the accuracy of the simulated team ranking.

## Repository

My GitHub repository contains two Jupyter Notebooks, my environment.yml file, a Data folder that has all the data my project needs, and an includes directory which stores libraries and files my project uses.

![](https://github.com/phesse001/march_madness_jupyter/blob/gh-pages/images/sample-repo.PNG?raw=true)

### Evironment.yml

Here is a look at the environment.yml file I used to create the environment for programming C++ in Jupyter Notebooks

![](https://github.com/phesse001/march_madness_jupyter/blob/gh-pages/images/my_yml.PNG?raw=true)

## Building the Image at mybinder.org

With the repository set up, now we just have to give binder the url to our GitHub repository.

![](https://github.com/phesse001/march_madness_jupyter/blob/gh-pages/images/binder-step1.PNG?raw=true)

## What You See Post Build

Once Binder finishes building your image you will eventually be redirected to a page that looks like this

![](https://github.com/phesse001/march_madness_jupyter/blob/gh-pages/images/post_build.PNG?raw=true)

As you can see, everything from the GitHub repository is now in this running Docker image created by Binder

## Test for Notbook

```c++
cout << "hello world!" << endl;
```



