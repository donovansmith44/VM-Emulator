#include "parser.h"
#include "codeWriter.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

    void parser::setCommandType(string command)
    {  
        curCommand = command;

        if (command[0] == '/' && command[1] == '/' )
        {
            comType = "";
        }
        else
        {
            if (command.find("push") != string::npos)
            {
                comType = "C_PUSH";
            }
            else if(command.find("pop") != string::npos)
            {
                comType = "C_POP";
            }
            
            else if (command.find("label") != string::npos)
            {
                comType = "C_LABEL";
            }
            else if (command.find("if-goto") != string::npos)
            {
                comType = "C_IF";
            }
            else if (command.find("call") != string::npos)
            {
                comType = "C_CALL";
            }
            else if (command.find("function") != string::npos)
            {
                comType = "C_FUNCTION";
            }
            else if (command.find("return") != string::npos)
            {
                comType = "C_RETURN";
            }
            else if (command.find("goto") != string::npos)
            {
                comType = "C_GOTO";
            }
            else if (command.find("add") != string::npos)
            {
                comType = "C_ARITHMETIC";
            }
            else if (command.find("sub") != string::npos)
            {
                comType = "C_ARITHMETIC";
            }
            else if (command.find("not") != string::npos)
            {
                comType = "C_ARITHMETIC";
            }
            else if (command.find("or") != string::npos)
            {
                comType = "C_ARITHMETIC";
            }
            else if (command.find("and") != string::npos)
            {
                comType = "C_ARITHMETIC";
            }
            else if (command.find("neg") != string::npos)
            {
                comType = "C_ARITHMETIC";
            }
            else if (command.find("lt") != string::npos)
            {
                comType = "C_ARITHMETIC";
            }
            else if (command.find("gt") != string::npos)
            {
                comType = "C_ARITHMETIC";
            }
            else if (command.find("eq") != string::npos)
            {
                comType = "C_ARITHMETIC";
            }
            else
            {
                comType = "";
            }
        }
    }
    
    string parser::getCommandType()
    {
        return comType;
    }
    
    string parser::arg1(string command)
    {
        firstArg = "";
        arg1pos = 0;
        arg2pos = 0;

        if (comType == "C_ARITHMETIC")
        {
            firstArg = command;
        }
        else
        {
            for (int i = 0; i < command.length(); i++)
            {
                if (command[i] == ' ')
                {
                    arg1pos = i;
                    break;
                }

            }

            for (int i = arg1pos+1; i < command.length(); i++)
            {
                if (command[i] == ' ')
                {
                    arg2pos = i;
                    break;
                }
                else
                {
                    firstArg += command[i];
                }
                
            }        
            
        }
        
        return firstArg;
    }
    
    int parser::arg2(string command)
    {
        secondArg = 0;
        string arg2string = "";

        for (int i = arg2pos+1; i < command.length(); i++)
        {
            arg2string += command[i];
            
        }

        if (arg2string != "")
        {
            secondArg = stoi(arg2string);
            return secondArg;
        }
        else
        {
            return 0;
        }
        
    }