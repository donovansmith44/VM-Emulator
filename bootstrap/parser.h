#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "codeWriter.h"

using namespace std;

class parser
{
    public:
        void setCommandType(string);
        string getCommandType();
        string arg1(string);
        int arg2(string);
    private:
        string curCommand;
        string comType;
        string firstArg;
        int secondArg;
        int arg1pos;
        int arg2pos;
};

#endif