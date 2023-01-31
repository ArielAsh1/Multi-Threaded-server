//
// Created by orrbb on 15/01/2023.
//

#ifndef ADVANCED_PROGRAMMING_1_EX4_CLI_H
#define ADVANCED_PROGRAMMING_1_EX4_CLI_H

#include <vector>
#include <thread>
#include <chrono>
#include "io.h"
#include "command.h"
#include "function.h"

class CLI {
    DefaultIO* dio;
    vector<Command*> commands;
    CommandData commandData;
    int sock;
public:
CLI(DefaultIO* dio, int sock, int port);
void start();
void printMenu();
virtual ~CLI();
};


#endif //ADVANCED_PROGRAMMING_1_EX4_CLI_H
