DATA SEGMENT 
n DW ?
i DW ?
x DW ?
b DW ?
a DW ?
soumia DW ?
maria DW ?
sarra DW ?
y DD ?
tableau DW 7 dup (?) 
moyenne DW ?
matricul DW ?
h DW ?
Pi DD ?
temp DW 100 dup (?) 
DATA ENDS

CODE SEGEMENT
ASSUME CS:CODE, DS:DATA
MAIN :
MOV AX,DATA
MOV DS,AX

MOV AX, maria
MUL AX, soumia
MOV SI,1
ADD SI,SI
MOV t[SI],AX 
MOV SI,1
ADD SI,SI
MOV AX,t[SI] 
MOV sarra,AX 
MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV a,AX 
MOV AX, a
CMP AX,b 
JE etiquette 6
MOV t[2],1  
MOV AX, 
CMP AX, 
JMP etiquette 7
etiquette6:MOV t[2],0  
etiquette7:MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 11
MOV AX, a
DIV AX, 2
MOV SI,3
ADD SI,SI
MOV t[SI],AX 
MOV SI,3
ADD SI,SI
MOV AX,t[SI] 
MOV a,AX 
MOV AX, 
CMP AX, 
JMP etiquette 13
etiquette11:MOV AX, b
ADD AX, 1
MOV SI,4
ADD SI,SI
MOV t[SI],AX 
MOV SI,4
ADD SI,SI
MOV AX,t[SI] 
MOV b,AX 
etiquette13:MOV AX, y
CMP AX,x 
JB etiquette 16
MOV t[5],1  
MOV AX, 
CMP AX, 
JMP etiquette 17
etiquette16:MOV t[5],0  
etiquette17:MOV SI,5
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 20
MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV x,AX 
MOV AX, 
CMP AX, 
JMP etiquette 17
etiquette20:MOV i,0 
MOV AX, i
CMP AX,n 
JG etiquette 25
MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV x,AX 
MOV AX, i
ADD AX, 1
MOV i,AX 
MOV AX, 
CMP AX, 
JMP etiquette 21
FIN :
MOV AH,4CH
INT 21h
CODE ENDS
END MAIN
DATA SEGMENT 
n DW ?
i DW ?
x DW ?
b DW ?
a DW ?
soumia DW ?
maria DW ?
sarra DW ?
y DD ?
tableau DW 7 dup (?) 
moyenne DW ?
matricul DW ?
h DW ?
Pi DD ?
temp DW 100 dup (?) 
DATA ENDS

CODE SEGEMENT
ASSUME CS:CODE, DS:DATA
MAIN :
MOV AX,DATA
MOV DS,AX

MOV AX, maria
MUL AX, soumia
MOV SI,1
ADD SI,SI
MOV t[SI],AX 
MOV SI,1
ADD SI,SI
MOV AX,t[SI] 
MOV sarra,AX 
MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV a,AX 
MOV AX, a
CMP AX,b 
JE etiquette 6
MOV t[2],1  
MOV AX, 
CMP AX, 
JMP etiquette 7
etiquette6:MOV t[2],0  
etiquette7:MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 11
MOV AX, a
DIV AX, 2
MOV SI,3
ADD SI,SI
MOV t[SI],AX 
MOV SI,3
ADD SI,SI
MOV AX,t[SI] 
MOV a,AX 
MOV AX, 
CMP AX, 
JMP etiquette 13
etiquette11:MOV AX, b
ADD AX, 1
MOV SI,4
ADD SI,SI
MOV t[SI],AX 
MOV SI,4
ADD SI,SI
MOV AX,t[SI] 
MOV b,AX 
etiquette13:MOV AX, y
CMP AX,x 
JB etiquette 16
MOV t[5],1  
MOV AX, 
CMP AX, 
JMP etiquette 17
etiquette16:MOV t[5],0  
etiquette17:MOV SI,5
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 20
MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV x,AX 
MOV AX, 
CMP AX, 
JMP etiquette 17
etiquette20:MOV i,0 
MOV AX, i
CMP AX,n 
JG etiquette 25
MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV x,AX 
MOV AX, i
ADD AX, 1
MOV i,AX 
MOV AX, 
CMP AX, 
JMP etiquette 21
FIN :
MOV AH,4CH
INT 21h
CODE ENDS
END MAIN
