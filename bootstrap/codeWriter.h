#ifndef CODEWRITER_H
#define CODEWRITER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "parser.h"

using namespace std;

class codeWriter
{
    public:
        codeWriter();
        codeWriter(string);
        void setFileName(string);
        void writeArithmetic(string);
        void writePushPop(string, string, int);
        void writeInit();
        void writeLabel(string);
        void writeGoto(string);
        void writeIf(string);
        void writeCall(string, int);
        void writeReturn();
        void writeFunction(string, int);
        void setCurFunction(string);
        void close();
    private:
        ofstream outFile;
        string fileName;
        string segMnemonic;
        string tempSegment;
        string tempLabel;
        string curFunction;
        string currentClass;
        int numLT;
        int numEQ;
        int numGT;
        int numFrames;
        int numReturns;
        int numCalls;

};

#endif