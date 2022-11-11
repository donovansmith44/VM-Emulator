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
(Class1.set) //function
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
@SP //pop
AM=M-1
D=M
@.vmvar$0
M=D
@1 //push
D=A
@ARG
A=D+M
D=M
@SP //push the value to the top of the stack
A=M
M=D
@SP //SP++
M=M+1
@SP //pop
AM=M-1
D=M
@.vmvar$1
M=D
@0 //push
D=A
@SP
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
(Class1.get) //function
@.vmvar$0 //push
D=M
@SP
A=M
M=D
@SP //SP++
M=M+1
@.vmvar$1 //push
D=M
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
@6 //push
D=A
@SP
A=M
M=D
@SP //SP++
M=M+1
@8 //push
D=A
@SP
A=M
M=D
@SP //SP++
M=M+1
@Class1.set$RETURN$1//push return address
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
@2
D=D-A
@5
D=D-A
@ARG
M=D
@SP //LCL = SP
D=M
@LCL
M=D
@Class1.set //goto f
0;JMP
(Class1.set$RETURN$1)
@SP //pop
AM=M-1
D=M
@R5
M=D
@23 //push
D=A
@SP
A=M
M=D
@SP //SP++
M=M+1
@15 //push
D=A
@SP
A=M
M=D
@SP //SP++
M=M+1
@Class2.set$RETURN$2//push return address
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
@2
D=D-A
@5
D=D-A
@ARG
M=D
@SP //LCL = SP
D=M
@LCL
M=D
@Class2.set //goto f
0;JMP
(Class2.set$RETURN$2)
@SP //pop
AM=M-1
D=M
@R5
M=D
@Class1.get$RETURN$3//push return address
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
@Class1.get //goto f
0;JMP
(Class1.get$RETURN$3)
@Class2.get$RETURN$4//push return address
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
@Class2.get //goto f
0;JMP
(Class2.get$RETURN$4)
(null$WHILE) //write label
@null$WHILE
0;JMP
(Class2.set) //function
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
@SP //pop
AM=M-1
D=M
@.vmvar$0
M=D
@1 //push
D=A
@ARG
A=D+M
D=M
@SP //push the value to the top of the stack
A=M
M=D
@SP //SP++
M=M+1
@SP //pop
AM=M-1
D=M
@.vmvar$1
M=D
@0 //push
D=A
@SP
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
(Class2.get) //function
@.vmvar$0 //push
D=M
@SP
A=M
M=D
@SP //SP++
M=M+1
@.vmvar$1 //push
D=M
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
