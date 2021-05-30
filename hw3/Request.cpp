/*
* Title: Heaps
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 3
* Description: Request.cpp
*/
#include "Request.h"

Request::Request(){
}

Request::Request(int requestId, int requestPriority, int logTime, int processTime){
    this->requestId = requestId;
    this->requestPriority = requestPriority;
    this->logTime = logTime;
    this->processTime = processTime;
}

int Request::getRequestId(){
    return requestId;
}

int Request::getRequestPriority(){
    return requestPriority;
}

int Request::getLogTime(){
    return logTime;
}

int Request::getProcessTime(){
    return processTime;
}
