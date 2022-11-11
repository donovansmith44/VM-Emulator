@256 //bootstrap
D=A
@SP
M=D
//CALL SYS.INIT
@Sys.init$RETURN$0//push return address
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL //push LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG //push ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS //push THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT //push THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@SP //ARG = SP-n-5
D=M
@0
D=D-A
@5
D=D-A
@ARG
M=D
@SP //LCL = SP
D=M
@LCL
M=D
@Sys.init //goto f
0;JMP
(Sys.init$RETURN$0)
(Main.fibonacci) //function
@0 //push
D=A
@ARG
A=D+M
D=M
@SP //push the value to the top of the stack
A=M
M=D
@SP //SP++
M=M+1
@2 //push
D=A
@SP
A=M
M=D
@SP //SP++
M=M+1
@SP //lt
A=M-1 //go to top value in stack
D=M
A=A-1 //go to second value in stack
D=M-D
@SP //SP--
M=M-1
A=M-1
M=-1
@LT_0
D;JLT
@SP
A=M-1
M=0
(LT_0)
@SP
AM=M-1
D=M
@null$IF_TRUE
D;JNE
@null$IF_FALSE
0;JMP
(null$IF_TRUE) //write label
@0 //push
D=A
@ARG
A=D+M
D=M
@SP //push the value to the top of the stack
A=M
M=D
@SP //SP++
M=M+1
@LCL //function return
D=M
@FRAME
M=D
@5
D=A
@FRAME
AD=M-D
D=M
@RET
M=D
@0 //pop
D=A
@ARG
D=D+M
@R13
M=D
@SP //SP--
AM=M-1
D=M
@R13
A=M
M=D
@R13
M=0
@ARG
D=M+1
@SP
M=D
@1
D=A
@FRAME
AD=M-D
D=M
@THAT
M=D
@2
D=A
@FRAME
AD=M-D
D=M
@THIS
M=D
@3
D=A
@FRAME
AD=M-D
D=M
@ARG
M=D
@4
D=A
@FRAME
AD=M-D
D=M
@LCL
M=D
@RET
A=M
0;JMP
(null$IF_FALSE) //write label
@0 //push
D=A
@ARG
A=D+M
D=M
@SP //push the value to the top of the stack
A=M
M=D
@SP //SP++
M=M+1
@2 //push
D=A
@SP
A=M
M=D
@SP //SP++
M=M+1
@SP //sub
A=M-1 //go to first operand
D=M
A=A-1 //go to second operand
D=M-D //sub operands and push onto top of the stack
M=D
@SP //SP--
M=M-1
@Main.fibonacci$RETURN$1//push return address
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL //push LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG //push ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS //push THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT //push THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@SP //ARG = SP-n-5
D=M
@1
D=D-A
@5
D=D-A
@ARG
M=D
@SP //LCL = SP
D=M
@LCL
M=D
@Main.fibonacci //goto f
0;JMP
(Main.fibonacci$RETURN$1)
@0 //push
D=A
@ARG
A=D+M
D=M
@SP //push the value to the top of the stack
A=M
M=D
@SP //SP++
M=M+1
@1 //push
D=A
@SP
A=M
M=D
@SP //SP++
M=M+1
@SP //sub
A=M-1 //go to first operand
D=M
A=A-1 //go to second operand
D=M-D //sub operands and push onto top of the stack
M=D
@SP //SP--
M=M-1
@Main.fibonacci$RETURN$2//push return address
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL //push LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG //push ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS //push THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT //push THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@SP //ARG = SP-n-5
D=M
@1
D=D-A
@5
D=D-A
@ARG
M=D
@SP //LCL = SP
D=M
@LCL
M=D
@Main.fibonacci //goto f
0;JMP
(Main.fibonacci$RETURN$2)
@SP //add
A=M-1 //go to first operand
D=M
A=A-1 //go to second operand
D=M+D //add operands and push onto top of the stack
M=D
@SP //SP--
M=M-1
@LCL //function return
D=M
@FRAME
M=D
@5
D=A
@FRAME
AD=M-D
D=M
@RET
M=D
@0 //pop
D=A
@ARG
D=D+M
@R13
M=D
@SP //SP--
AM=M-1
D=M
@R13
A=M
M=D
@R13
M=0
@ARG
D=M+1
@SP
M=D
@1
D=A
@FRAME
AD=M-D
D=M
@THAT
M=D
@2
D=A
@FRAME
AD=M-D
D=M
@THIS
M=D
@3
D=A
@FRAME
AD=M-D
D=M
@ARG
M=D
@4
D=A
@FRAME
AD=M-D
D=M
@LCL
M=D
@RET
A=M
0;JMP
(Sys.init) //function
@4 //push
D=A
@SP
A=M
M=D
@SP //SP++
M=M+1
@Main.fibonacci$RETURN$3//push return address
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL //push LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG //push ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS //push THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT //push THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@SP //ARG = SP-n-5
D=M
@1
D=D-A
@5
D=D-A
@ARG
M=D
@SP //LCL = SP
D=M
@LCL
M=D
@Main.fibonacci //goto f
0;JMP
(Main.fibonacci$RETURN$3)
(null$WHILE) //write label
@null$WHILE
0;JMP
