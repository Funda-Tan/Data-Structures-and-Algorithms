/*
* Title: Heaps
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 3
* Description: Printer.cpp
*/

#include "Printer.h"
#include "PriorityQueue.h"
#include "Request.h"

Printer::Printer(){
    available = true;
}

bool Printer::checkAvailable(){
    return available;
}

void Printer::use(int time){
    this->useTime = time;
    available = false;
}

void Printer::decreaseUseTime(){
    useTime = useTime - 1;
    if(useTime == 0){
        available = true;
    }
}
