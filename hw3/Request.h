/*
* Title: Heaps
* Author: Funda Tan
* ID: 21801861
* Section: 3
* Assignment: 3
* Description: Request.h
*/

#ifndef REQUEST_H
#define REQUEST_H

class Request {

public:
    Request();
    Request(int requestId, int requestPriority, int logTime, int processTime);
    int getRequestId();
    int getRequestPriority();
    int getLogTime();
    int getProcessTime();

private:
    int requestId;
    int requestPriority;
    int logTime;
    int processTime;
};
#endif // REQUEST_H
