
using namespace std;

#ifndef READ_FROM_FILE_H
#define READ_FROM_FILE_H
#include "function.h"

class readFromFile {
private:
    string fileName;
    vector<float> handleLine(string& lin, bool hasLabel = true);
public:
    // our 2d vector, containing all inputs
    vector<vector<float>> X_train;
    // the labels of the inputs (X_train)
    vector<string> y_train;
    int featuresPerLine;

    // constructor:
    readFromFile(string inputFile);
    // defualt constructor
    readFromFile();

    // setter
    void setFile(string inputFile);

    // the read function:
    int read(bool hasLabel = true);

    void clearVector ();
};

#endif

