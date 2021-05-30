/*
* Title: Heaps
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 3
* Description: Printer.h
*/

#ifndef PRINTER_H
#define PRINTER_H
#include "PriorityQueue.h"
#include "Request.h"

class Printer {
public:
    Printer();
    bool checkAvailable();
    void use(int time);
    void decreaseUseTime();

private:
    bool available;
    int useTime;
};

#endif // PRINTER_H
