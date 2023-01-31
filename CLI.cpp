
#include "CLI.h"

CLI::CLI(DefaultIO *dio, int sock, int port) {
    this->sock = sock;
    this->dio = dio;
    CommandData new_commandData;
    this->commandData = new_commandData;
    this->commandData.port = port;
    this->commandData.sock = sock;
    commands.push_back(new UploadCommand(dio));
    commands.push_back(new AlgorithmSettingsCommand(dio));
    commands.push_back(new ClassifyDataCommand(dio));
    commands.push_back(new DisplayResultCommand(dio));
    commands.push_back(new DownloadResultsCommand(dio));
    commands.push_back(new ExitCommand(dio));
}


/**
 * prints description of all commands.
 */
void CLI::printMenu() {
    string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for (int i = 0; i < commands.size(); i++) {
        menu += commands[i]->description + '\n';
    }
    dio->write(menu);
}

/**
 * main function for CLI. loops on menu, and handles it commands.
 */
void CLI::start() {
    CommandData new_commandData;
    int input = 0;
    string inputStr;
    int index;
    while (input != 8) {
        printMenu();
        this->dio->write("write");
        inputStr = dio->read();        
        if (!isPositiveInteger(inputStr.c_str())) {
            this->dio->write("invalid input");
            continue;
        }
        try {
            input = stoi(inputStr);
        } catch (const exception& e) {
            this->dio->write("invalid input");
            continue;
        }
        if (input < 1 || (input > 5 && input != 8)) {
            this->dio->write("invalid input");
            continue;
        }
        index = input - 1;
        if (input == 8) {
            index = 5;      // ensure command[index] works with all manu elements
        }
        commands[index]->execute(&new_commandData);
        // makes the program sleep for a short amount of time, and helps for proper communication between client
        // and server on PLANET. Prevents undefined behaviour due to communication lag.
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

/**
 * destructor for CLI class.
 */
CLI::~CLI() {
    for (auto & command : commands) {
        delete command;
    }
}

