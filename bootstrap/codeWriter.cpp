#include "codeWriter.h"
#include "parser.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

    codeWriter::codeWriter(string asmFileName){
        fileName = asmFileName;
        outFile.open(fileName);
        curFunction = "null$";
        tempSegment = "";
        numGT = 0;
        numEQ = 0;
        numLT = 0;
        numFrames = 0;
        numReturns = 0;
        numCalls = 0;
    }
    void codeWriter::setFileName(string fName){
        fileName = fName;
    }
    
    void codeWriter::setCurFunction(string curClass){
         curFunction = curClass;
    }

    void codeWriter::writeArithmetic(string command){
        
        if(command == "add")
        {
            outFile << "@SP //add" << endl; //SP*=sum
            
            outFile << "A=M-1 //go to first operand" << endl; //get first operand
            outFile << "D=M" << endl;

            outFile << "A=A-1 //go to second operand" << endl; //get second operand

            outFile << "D=M+D //add operands and push onto top of the stack" << endl; //add operands, SP* = sum
            outFile << "M=D" << endl;

            outFile << "@SP //SP--" << endl; //SP--
            outFile << "M=M-1" << endl;
        }
        else if(command == "sub")
        {
            outFile << "@SP //sub" << endl; //SP*=difference
            
            outFile << "A=M-1 //go to first operand" << endl; //get first operand
            outFile << "D=M" << endl;

            outFile << "A=A-1 //go to second operand" << endl; //get second operand

            outFile << "D=M-D //sub operands and push onto top of the stack" << endl; //add operands, SP* = difference
            outFile << "M=D" << endl;

            outFile << "@SP //SP--" << endl; 
            outFile << "M=M-1" << endl;         
        }
        else if(command == "and")
        {
            outFile << "@SP //and" << endl; //SP*=AND
            
            outFile << "A=M-1 //go to first operand" << endl; //get first operand
            outFile << "D=M" << endl;

            outFile << "A=A-1 //go to second operand" << endl; //get second operand

            outFile << "D=M&D //and operands and push onto top of the stack" << endl; //add operands, SP* = and result
            outFile << "M=D" << endl;

            outFile << "@SP //SP--" << endl; //SP--
            outFile << "M=M-1" << endl;
        }
        else if(command == "or")
        {
            outFile << "@SP //or" << endl; //SP*=AND
            
            outFile << "A=M-1 //go to first operand" << endl; //get first operand
            outFile << "D=M" << endl;

            outFile << "A=A-1 //go to second operand" << endl; //get second operand

            outFile << "D=M|D //and operands and push onto top of the stack" << endl; //or operands, SP* = or result
            outFile << "M=D" << endl;

            outFile << "@SP //SP--" << endl; //SP--
            outFile << "M=M-1" << endl;
        }
        else if(command == "gt")
        {
            outFile << "@SP //gt" << endl; //SP * =EQ
            outFile << "A=M-1 //go to top value in stack" << endl; //get first operand
            outFile << "D=M" << endl;
            outFile << "A=A-1 //go to second value in stack" << endl; //get second operand
            outFile << "D=M-D" << endl; //GT operation
            
            outFile << "@SP //SP--" << endl; //SP--
            outFile << "M=M-1" << endl;

            outFile << "A=M-1" << endl; //SP * = true
            outFile << "M=-1" << endl;

            outFile << "@GT_" << to_string(numGT) << endl; //if a-b > 0            

            outFile << "D;JGT" << endl;
            
            outFile << "@SP" << endl; //else
            
            outFile << "A=M-1" << endl; //SP*=false
            outFile << "M=0" << endl;

            outFile << "(GT_" << to_string(numGT) << ")" << endl;
            numGT++;
        }
        else if(command == "lt")
        {
            outFile << "@SP //lt" << endl; //SP * =EQ
            outFile << "A=M-1 //go to top value in stack" << endl; //get first operand
            outFile << "D=M" << endl;
            outFile << "A=A-1 //go to second value in stack" << endl; //get second operand
            outFile << "D=M-D" << endl; //LT operation
            
            outFile << "@SP //SP--" << endl; //SP--
            outFile << "M=M-1" << endl;

            outFile << "A=M-1" << endl; //SP * = true
            outFile << "M=-1" << endl;

            outFile << "@LT_" << to_string(numLT) << endl; //if a-b > 0            

            outFile << "D;JLT" << endl;
            
            outFile << "@SP" << endl; //else
            
            outFile << "A=M-1" << endl; //SP*=false
            outFile << "M=0" << endl;

            outFile << "(LT_" << to_string(numLT) << ")" << endl;
            numLT++;
        }
        else if(command == "eq")
        {
            outFile << "@SP //eq" << endl; //SP * =EQ
            outFile << "A=M-1 //go to top value in stack" << endl; //get first operand
            outFile << "D=M" << endl;
            outFile << "A=A-1 //go to second value in stack" << endl; //get second operand
            outFile << "D=M-D" << endl; //EQ operation
            
            outFile << "@SP //SP--" << endl; //SP--
            outFile << "M=M-1" << endl;

            outFile << "A=M-1" << endl; //SP * = true
            outFile << "M=-1" << endl;

            outFile << "@EQ_" << to_string(numEQ) << endl; //if a-b > 0            

            outFile << "D;JEQ" << endl;
            
            outFile << "@SP" << endl; //else
            
            outFile << "A=M-1" << endl; //SP*=false
            outFile << "M=0" << endl;

            outFile << "(EQ_" << to_string(numEQ) << ")" << endl;
            numEQ++;
        }
        //unary commands
        else if(command == "not")
        {
            outFile << "@SP //not" << endl;
            outFile << "A=M-1" << endl;
            outFile << "M=!M" << endl;
        }
        else if(command == "neg")
        {
            outFile << "@SP //neg" << endl;
            outFile << "A=M-1" << endl;
            outFile << "M=-M" << endl;
        }
    }

    void codeWriter::writePushPop(string command, string segment, int index){
        parser Parser;
        segMnemonic = "";
        tempSegment = segment;
        
        if (segment == "local")
        {
            segMnemonic = "LCL";
        }
        else if (segment == "argument")
        {
            segMnemonic = "ARG";
        }
        else if (segment == "this")
        {
            segMnemonic = "THIS";
        }
        else if (segment == "that")
        {
            segMnemonic = "THAT";
        }
        else if(segment == "temp")
        {
            //temp refers to memory R5-R12
            segMnemonic = "R" + to_string(index+5);
        }
        else if(segment == "pointer")
        {
           if (index == 0)
           { 
                segMnemonic = "THIS";
           }
           else
           {
                segMnemonic = "THAT";
           }
        }
        else if(segment == "static")
        {
            
        }

            if (command == "push")
            {       
                    if (segment == "constant")
                    {
                        outFile << "@" + to_string(index) << " //push" << endl; //push
                        outFile << "D=A" << endl;
                        outFile << "@SP" << endl;
                        outFile << "A=M" << endl;
                        outFile << "M=D" << endl;
                        
                        outFile << "@SP //SP++" << endl; //SP++
                        outFile << "M=M+1" << endl;
                    }
                    else if(segment == "temp")
                    {
                        //push value from segment at i to top of stack
                        outFile << "@" + segMnemonic + " //push" << endl;
                        outFile << "D=M" << endl;
                        
                        outFile << "@SP" << endl;
                        outFile << "A=M" << endl;
                        outFile << "M=D" << endl;

                        outFile << "@SP //SP++" << endl;
                        outFile << "M=M+1" << endl;
                    }
                    else if(segment == "pointer")
                    {
                        //push base address of THIS/THAT to top of stack
                        outFile << "@" + segMnemonic + " //push" << endl;
                        outFile << "D=M" << endl;
                        
                        outFile << "@SP" << endl;
                        outFile << "A=M" << endl;
                        outFile << "M=D" << endl;

                        outFile << "@SP //SP++" << endl;
                        outFile << "M=M+1" << endl;
                    }
                    else if(segment == "static")
                    {
                        outFile << "@" + curFunction + "var$" + to_string(index) << " //push" << endl;
                        outFile << "D=M" << endl;
                        
                        outFile << "@SP" << endl;
                        outFile << "A=M" << endl;
                        outFile << "M=D" << endl;

                        outFile << "@SP //SP++" << endl;
                        outFile << "M=M+1" << endl;
                    }
                    else
                    {
                        //push local i : place the local[i] at the top of the stack
                        outFile << "@" << to_string(index) << " //push" << endl;
                        outFile << "D=A" << endl;
                        
                        outFile << "@" << segMnemonic << endl; //get tempSegment+i address
                        outFile << "A=D+M" << endl;
                        outFile << "D=M" << endl;

                        outFile << "@SP //push the value to the top of the stack" << endl;
                        outFile << "A=M" << endl;
                        outFile << "M=D" << endl;
                        
                        outFile << "@SP //SP++" << endl;
                        outFile << "M=M+1" << endl;                    
                    }
            }
            else if(command == "pop")
            {          
                    if (segment == "temp")
                    {
                        //place value from top of stack into temp[i]
                        outFile << "@SP //pop" << endl; //SP-- and get SP*
                        outFile << "AM=M-1" << endl;

                        outFile << "D=M" << endl;

                        outFile << "@" + segMnemonic << endl;
                        outFile << "M=D" << endl;
                    }
                    else if(segment == "pointer")
                    {
                        //make value from top of stack base address of THIS/THAT
                        outFile << "@SP //pop" << endl;
                        outFile << "AM=M-1" << endl;
                        
                        outFile << "D=M" << endl;

                        outFile << "@" + segMnemonic << endl;
                        outFile << "M=D" << endl;
                    }
                    else if (segment == "static")
                    {
                        outFile << "@SP //pop" << endl;
                        outFile << "AM=M-1" << endl;
                        outFile << "D=M" << endl;

                        outFile << "@" + curFunction + "var$" + to_string(index) << endl;
                        outFile << "M=D" << endl;
                    }
                    
                    else
                    {
                        //pop tempSegment i : place value at the top of the stack into tempSegment[i]
                        outFile << "@" + to_string(index) << " //pop" << endl;
                        outFile << "D=A" << endl;
                        
                        outFile << "@" + segMnemonic << endl; //get tempSegment+i address
                        outFile << "D=D+M" << endl;
                        
                        outFile << "@R13" << endl; //store tempSegment+i address into R13
                        outFile << "M=D" << endl;
                        
                        outFile << "@SP //SP--" << endl; //SP-- and get SP*
                        outFile << "AM=M-1" << endl;
                        outFile << "D=M" << endl;
                        
                        outFile << "@R13" << endl; //store SP* into tempSegment+i
                        outFile << "A=M" << endl;
                        outFile << "M=D" << endl;

                        outFile << "@R13" << endl; //Clear R13
                        outFile << "M=0" << endl;
                    }
            }
        }
    
    void codeWriter::writeInit()
    {
        outFile << "@256 //bootstrap" << endl;
        outFile << "D=A" << endl;
        outFile << "@SP" << endl;
        outFile << "M=D" << endl;
        outFile << "//CALL SYS.INIT" << endl;
        writeCall("Sys.init", 0);
    }

    void codeWriter::writeLabel(string label){
        label.erase(label.size() - 1); //erase the carriage return
        tempLabel = label;
        outFile << "(" << "null$" << label << ") //write label" << endl;
    }

    void codeWriter::writeIf(string label){
        outFile << "@SP" << endl;
        outFile << "AM=M-1" << endl; //we decrement the stack pointer because we pop the top value to evaluate in our if statement
        outFile << "D=M" << endl;
        outFile << "@null$" << label << endl;
        outFile << "D;JNE" << endl;
    }

    void codeWriter::writeGoto(string label)
    {
        outFile << "@null$" << label << endl;
        outFile << "0;JMP" << endl;
    }

    void codeWriter::writeReturn(){

        outFile << "@LCL //function return" << endl; //FRAME = LCL
        outFile << "D=M" << endl;
        outFile << "@FRAME" << endl;
        //outFile << "@endframe$" << to_string(numFrames)  << endl;
        outFile << "M=D" << endl;

        //restore previous pointer values
        outFile << "@5" << endl; //RET = (FRAME-5)*
        outFile << "D=A" << endl;
        outFile << "@FRAME" << endl;
        //outFile << "@endframe$" << to_string(numFrames) << endl;
        outFile << "AD=M-D" << endl;
        // outFile << "D=M-D" << endl;
        // outFile << "A=D" << endl;
        outFile << "D=M" << endl;
        outFile << "@RET" << endl;
        //outFile << "@retAddress." << to_string(numReturns)  << endl;
        outFile << "M=D" << endl;

        writePushPop("pop", "argument", 0); //ARG* = pop()

        outFile << "@ARG" << endl;
        outFile << "D=M+1" << endl;
        outFile << "@SP" << endl;
        outFile << "M=D" << endl;

        outFile << "@1" << endl; //THAT = (FRAME-1)*
        outFile << "D=A" << endl;
        outFile << "@FRAME" << endl;
        //outFile << "@endframe$" << to_string(numFrames)  << endl;
        outFile << "AD=M-D" << endl;
        // outFile << "D=M-D" << endl;
        // outFile << "A=D" << endl;
        outFile << "D=M" << endl;
        outFile << "@THAT" << endl;
        outFile << "M=D" << endl;

        outFile << "@2" << endl; //THIS = (FRAME-2)*
        outFile << "D=A" << endl;
        outFile << "@FRAME" << endl;
        //outFile << "@endframe$" << to_string(numFrames)  << endl;
        outFile << "AD=M-D" << endl;
        // outFile << "D=M-D" << endl;
        // outFile << "A=D" << endl;
        outFile << "D=M" << endl;
        outFile << "@THIS" << endl;
        outFile << "M=D" << endl;

        outFile << "@3" << endl; //ARG = (FRAME-3)*
        outFile << "D=A" << endl;
        outFile << "@FRAME" << endl;
        //outFile << "@endframe$" << to_string(numFrames)  << endl;
        outFile << "AD=M-D" << endl;
        // outFile << "D=M-D" << endl;
        // outFile << "A=D" << endl;
        outFile << "D=M" << endl;
        outFile << "@ARG" << endl;
        outFile << "M=D" << endl;

        outFile << "@4" << endl; //LCL = (FRAME-4)*
        outFile << "D=A" << endl;
        outFile << "@FRAME" << endl;
        //outFile << "@endframe$" << to_string(numFrames)  << endl;
        outFile << "AD=M-D" << endl;
        // outFile << "D=M-D" << endl;
        // outFile << "A=D" << endl;
        outFile << "D=M" << endl;
        outFile << "@LCL" << endl;
        outFile << "M=D" << endl;

        outFile << "@RET" << endl;
        //outFile << "@retAddress." << to_string(numReturns) << endl; //goto RET
        outFile << "A=M" << endl;
        outFile << "0;JMP" << endl;
        
        // numFrames++;
        // numReturns++;
    }

    void codeWriter::writeFunction(string functionName, int numLocals){
        /*
                declare function kVars (local vars)
                (f)
                    repeat k times:
                    PUSH 0
                
                this can easily be achieved by creating an assembly program loop that initializes all
                of the memory segments from LCL to LCL+k to 0
        */
               outFile << "(" << functionName << ") //function" << endl;
               
               for (int i = 0; i < numLocals; i++)
               {
                        writePushPop("push", "constant", 0);
                        writePushPop("pop", "local", i);
                        outFile << "@SP //SP++" << endl;
                        outFile << "M=M+1" << endl;
               }
    }

    void codeWriter::writeCall(string functionName, int numArgs)
    {
        /*
                call function nArgs (args)
                1. push return-address
                2. push LCL: meaning, push RAM[1]
                3. push ARG: meaning, push RAM[2]
                4. push THIS: meaning, push RAM[3]
                5. push THAT: meaning, push RAM[4]
                6. ARG = SP-n-5
                7. LCL = SP
                8. goto f
                9. (return-address)

            This is (seemingly) the most complex part of the entire VM implementation, but it's not as complicated as one (myself included) would think. Just follow the directions.
            The return-address is determined by the label in step 9. When pushing LCL, ARG, THIS, and THAT onto the stack, you're simply pushing the values of the segment pointers, 
            not the values that they point to.
        */
            
            string curReturnAddress = "";
            curReturnAddress = functionName + "$RETURN$" + to_string(numCalls);

            outFile << "@" << curReturnAddress << "//push return address" << endl;
            outFile << "D=A" << endl;
            outFile << "@SP" << endl;
            outFile << "A=M" << endl;
            outFile << "M=D" << endl;
            outFile << "@SP" << endl;
            outFile << "M=M+1" << endl;

            outFile << "@LCL //push LCL" << endl;
            outFile << "D=M" << endl;
            outFile << "@SP" << endl;
            outFile << "A=M" << endl;
            outFile << "M=D" << endl;
            outFile << "@SP" << endl;
            outFile << "M=M+1" << endl;

            outFile << "@ARG //push ARG" << endl;
            outFile << "D=M" << endl;
            outFile << "@SP" << endl;
            outFile << "A=M" << endl;
            outFile << "M=D" << endl;
            outFile << "@SP" << endl;
            outFile << "M=M+1" << endl;

            outFile << "@THIS //push THIS" << endl;
            outFile << "D=M" << endl;
            outFile << "@SP" << endl;
            outFile << "A=M" << endl;
            outFile << "M=D" << endl;
            outFile << "@SP" << endl;
            outFile << "M=M+1" << endl;

            outFile << "@THAT //push THAT" << endl;
            outFile << "D=M" << endl;
            outFile << "@SP" << endl;
            outFile << "A=M" << endl;
            outFile << "M=D" << endl;
            outFile << "@SP" << endl;
            outFile << "M=M+1" << endl;

            outFile << "@SP //ARG = SP-n-5" << endl;
            outFile << "D=M" << endl;
            outFile << "@" << to_string(numArgs) << endl;
            outFile << "D=D-A" << endl;
            outFile << "@5" << endl;
            outFile << "D=D-A" << endl;
            outFile << "@ARG" << endl;
            outFile << "M=D" << endl;

            outFile << "@SP //LCL = SP" << endl; 
            outFile << "D=M" << endl;
            outFile << "@LCL" << endl;
            outFile << "M=D" << endl;
            
            outFile << "@" << functionName << " //goto f" << endl; 
            outFile << "0;JMP" << endl;

            outFile << "(" << curReturnAddress << ")" << endl;
            numCalls++;
    }

    void codeWriter::close(){
        outFile.close();
    }
