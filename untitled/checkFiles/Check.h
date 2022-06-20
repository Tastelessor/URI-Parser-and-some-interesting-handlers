#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef UNTITLED_CHECK_H
#define UNTITLED_CHECK_H
class Check {
public:
    int offset;
    string line;
    string filename;
    ifstream fs;

    Check(string f){
        filename = f;
    }

    virtual bool checkFile() = 0;
};


#endif //UNTITLED_CHECK_H
