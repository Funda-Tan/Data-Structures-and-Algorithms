/*
* Title: Heaps
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 3
* Description: simulator.cpp
*/

#include "simulator.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

simulator::simulator(){
}

simulator::simulator(string file){
    string line = "";
    int lineNo = 0;
    ifstream inFile;
    inFile.open(file.c_str());

    //Initialize requests
    bool flag = false;
    while(getline(inFile, line)) {
        stringstream s;
        s << line;

        int reqData;
        int data[4];
        int count = 0;

        while(!s.eof()){
            s >> reqData;
            data[count++] = reqData;
        }

        if(flag == false){
            numOfRequests = data[0];
            flag = true;
        }

        else{
            requests[lineNo - 1] = Request(data[0], data[1], data[2], data[3]);
        }
        lineNo++;
    }
}

void simulator::simulate(int avgWaitingTime) {
    int numOfPrinters = 1;
    string out = "";
    double simAvg = 0;
    Printer printers[numOfPrinters];
    double totalWaitingTime = 0;
    int temp = numOfRequests;
    PriorityQueue requestList;

    for(int time = 0; temp != 0; time++){
        for(int i = 0; i < numOfRequests; i++){
            if(time == requests[i].getLogTime()){
                requestList.pqInsert(requests[i]);
            }
        }

        for(int i = 0; i < numOfPrinters; i++){
            if( !printers[i].checkAvailable() ) {
                printers[i].decreaseUseTime();
            }
        }

        int availablePrinterNo = -1;
        for(int i = 0; i < numOfPrinters; i++){
            if( printers[i].checkAvailable()) {
                availablePrinterNo = i;
            }
        }
        while(!requestList.pqIsEmpty() && availablePrinterNo != -1){
                Request r;
                requestList.pqDelete((Request&) r);
                totalWaitingTime += time - r.getLogTime();
                printers[availablePrinterNo].use(r.getProcessTime());

                out = out + "Printer " + intToString(availablePrinterNo) + " takes request "
                + intToString(r.getRequestId()) + " at minute " + intToString(time)
                + " (wait: " + intToString(time - r.getLogTime()) + " mins)\n";

                temp--;

                availablePrinterNo = -1;
                for(int i = 0; i < numOfPrinters; i++){
                    if(printers[i].checkAvailable()) {
                        availablePrinterNo = i;
                    }
                }
        }
    }

    simAvg = (double)totalWaitingTime / numOfRequests;

    if(simAvg <= avgWaitingTime){
        cout << endl;
        cout << "Minimum number of printers required: " + intToString(numOfPrinters) << endl;
        cout << endl;
        cout << "Simulation with " << numOfPrinters << " printers: " << endl;
        cout << endl;
        cout << out << endl;
        cout << "Average waiting time: " << simAvg << " minutes" << endl;
    }

    while(simAvg > avgWaitingTime){
        out = "";
        Printer printers[numOfPrinters];
        double totalWaitingTime = 0;
        int temp = numOfRequests;
        PriorityQueue requestList;

        for(int currTime = 0; temp != 0; currTime++){
            for(int i = 0; i < numOfRequests; i++){
                if(currTime == requests[i].getLogTime()){
                    requestList.pqInsert(requests[i]);
                }
            }

            for(int i = 0; i < numOfPrinters; i++){
                if(!printers[i].checkAvailable() ) {
                    printers[i].decreaseUseTime();
                }
            }

            int availablePrinterNo = -1;
            for(int i = 0; i < numOfPrinters; i++){
                if(printers[i].checkAvailable()) {
                    availablePrinterNo = i;
                }
            }
            while(!requestList.pqIsEmpty() && availablePrinterNo != -1){
                Request r;
                requestList.pqDelete((Request&) r);
                totalWaitingTime += currTime - r.getLogTime();
                printers[availablePrinterNo].use(r.getProcessTime());

                out = out + "Printer " + intToString(availablePrinterNo) + " takes request "
                + intToString(r.getRequestId()) + " at minute " + intToString(currTime)
                + " (wait: " + intToString(currTime - r.getLogTime()) + " mins)\n";

                temp--;

                availablePrinterNo = -1;
                for(int i = 0; i < numOfPrinters; i++){
                    if(printers[i].checkAvailable()) {
                        availablePrinterNo = i;
                    }
                }
            }
        }

        simAvg = (double)totalWaitingTime / numOfRequests;
        if(simAvg <= avgWaitingTime) {
            cout << endl;
            cout << "Minimum number of printers required: " + intToString(numOfPrinters) << endl;
            cout << endl;
            cout << "Simulation with " << numOfPrinters << " printers: " << endl;
            cout << endl;
            cout << out << endl;
            cout << "Average waiting time: " << simAvg << " minutes" << endl;
        }
        numOfPrinters++;
    }
}

string simulator::intToString(int i){
    stringstream newI;
    newI << i;
    return newI.str();
}

simulator::~simulator(){//dtor
}
