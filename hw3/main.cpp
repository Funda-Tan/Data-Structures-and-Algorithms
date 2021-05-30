/*
* Title: Heaps
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 3
* Description: main.cpp
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "simulator.h"

using namespace std;

int main(int argc, char *argv[]) {

    simulator* sim = new simulator(argv[1]);
    stringstream c(argv[2]);
    int avgWaitingTime = 0;
    c >> avgWaitingTime;
    sim->simulate(avgWaitingTime);

    return 0;
 }
