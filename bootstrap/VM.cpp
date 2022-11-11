#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <filesystem>
#include "parser.h"
#include "codeWriter.h"

using namespace std;

vector<string> getVMFiles(string directory){
    vector<string> files;
    vector<string> vmFiles;
    
    for (const auto & file : std::filesystem::directory_iterator(directory)) //put all files in directory in a vector
        files.push_back(file.path());
    
    for (int i = 0; i < files.size(); i++) //remove files that aren't vm files
    {
        if (files[i].find(".vm") != string::npos)
        {
            vmFiles.push_back(files[i]);
        }    
    }

    return vmFiles;
}

string commandClean(string dirtyCommand){
    string cleanCommand;

    for (int i = 0; i < dirtyCommand.size(); i++)
    {
        cleanCommand += dirtyCommand[i]+32;
    }

    cleanCommand.erase(0,2);

    return cleanCommand;
}

int main(int argc, char* argv[]){

    string line = "";
    string directory = "/Users/donovan/Documents/opus/VMEmulator/bootstrap/Fibonaccielement";
    vector<string> vmFiles = getVMFiles(directory); //create a vector to hold all of the .vm files in a chosen directory
    ifstream vmFile;
    ofstream asmFile;
    parser parserObj;
    codeWriter codeObj("FibonacciElement.asm");
    vector<string> tempVmFiles;

    //get commands
    vector<string> commands;
    vector<string> commandType;
    vector<string> args1;
    vector<int> args2;
    
    string tempString = "";
    
    for (int i = 0; i < vmFiles.size(); i++) //store name of each class file into a vector to be used in the declaring of static variables
    {
        tempString = vmFiles[i];
        tempString = tempString.substr(69, tempString.length()-3);
        tempVmFiles.push_back(tempString);
    }

    codeObj.writeInit(); //bootstrap code

    for (int i = 0; i < 3; i++)
    {
        vmFile.open(vmFiles[i]);
        codeObj.setCurFunction(tempVmFiles[i]);

        while (getline(vmFile, line))
    {
        string tempArg1 = "";
        int tempArg2 = 0;
        parserObj.setCommandType(line);

        if (parserObj.getCommandType() != "")
        {
            commands.push_back(line);
            commandType.push_back(parserObj.getCommandType());
            
            if (parserObj.getCommandType() != "C_RETURN")
            {
                tempArg1 = parserObj.arg1(line);
                args1.push_back(tempArg1);
            }
            else
            {
                args1.push_back("-1");
            }
            
            if (parserObj.getCommandType() == "C_PUSH" || parserObj.getCommandType() == "C_POP" || parserObj.getCommandType() == "C_FUNCTION" || parserObj.getCommandType() == "C_CALL" )
            {
                tempArg2 = parserObj.arg2(line);
                args2.push_back(tempArg2);
            }
            else
            {
                args2.push_back(-1);
            }

            if (parserObj.getCommandType() == "C_ARITHMETIC")
            {
                line.erase(line.length()-1,1); //erase the last character from the arithmetic commands. they have an additional character, for some reason.
                codeObj.writeArithmetic(line);                   
            }
            else if(parserObj.getCommandType() == "C_POP" || parserObj.getCommandType() == "C_PUSH")
            {
                codeObj.writePushPop(commandClean(parserObj.getCommandType()), parserObj.arg1(line), parserObj.arg2(line)); //push constant i
            }
            else if (parserObj.getCommandType() == "C_IF")
            {
                codeObj.writeIf(tempArg1);
            }
            else if (parserObj.getCommandType() == "C_GOTO")
            {
                codeObj.writeGoto(tempArg1);
            }
            else if (parserObj.getCommandType() == "C_LABEL")
            {
                codeObj.writeLabel(tempArg1);
            }
            else if (parserObj.getCommandType() == "C_FUNCTION")
            {
                codeObj.writeFunction(tempArg1, tempArg2);
            }
            else if (parserObj.getCommandType() == "C_RETURN")
            {
                codeObj.writeReturn();
            }
            else if(parserObj.getCommandType() == "C_CALL")
            {
                codeObj.writeCall(tempArg1, tempArg2);
            }
        }
    }
    
    vmFile.close();
    }

    codeObj.close();

    return 0;
}