/*
* Title: Heaps
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 3
* Description: simulator.h
*/

#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "PriorityQueue.h"
#include "Printer.h"
#include <iostream>
#include <string>
using namespace std;
class simulator
{
    public:
        simulator();
        simulator(string file);
        string intToString(int i);
        void simulate(int AvgWaitingTime);
        virtual ~simulator();

    protected:

    private:
        int numOfRequests;
        Request requests[1000];
};

#endif // SIMULATOR_H
