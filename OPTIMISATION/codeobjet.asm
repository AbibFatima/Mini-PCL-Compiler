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
Ab3 DW ?
moyenne DW ?
matricul DW ?
idf1 DW ?
idf2 DD ?
idf3 DW ?
idf4 DD ?
idf5 DD ?
idf6 DW ?
idf7 DD ?
temp DW 100 dup (?) 
DATA ENDS

CODE SEGEMENT
ASSUME CS:CODE, DS:DATA
MAIN :
MOV AX,DATA
MOV DS,AX

MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV a,AX 
MOV AX, a
DIV AX, 2
MOV SI,1
ADD SI,SI
MOV t[SI],AX 
MOV AX, b
MUL AX, 9
MOV SI,2
ADD SI,SI
MOV t[SI],AX 
MOV SI,1
ADD SI,SI
MOV AX, t[SI] 
ADD AX,t[2]
 MOV SI,3
ADD SI,SI
MOV t[SI],AX 
MOV SI,3
ADD SI,SI
MOV AX, t[SI]
ADD AX, 1
MOV SI,4
ADD SI,SI
MOV t[SI],AX 
MOV SI,4
ADD SI,SI
MOV AX, t[SI]
SUB AX, 7
MOV SI,5
ADD SI,SI
MOV t[SI],AX 
MOV SI,5
ADD SI,SI
MOV AX,t[SI] 
MOV n,AX 
MOV AX, maria
MUL AX, a
MOV SI,6
ADD SI,SI
MOV t[SI],AX 
MOV SI,6
ADD SI,SI
MOV AX,t[SI] 
MOV sarra,AX 
MOV AX, a
CMP AX,b 
JE etiquette 12
MOV t[7],1  
MOV AX, 
CMP AX, 
JMP etiquette 13
etiquette12:MOV t[7],0  
etiquette13:MOV SI,7
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 17
MOV AX, a
DIV AX, 2
MOV SI,8
ADD SI,SI
MOV t[SI],AX 
MOV SI,8
ADD SI,SI
MOV AX,t[SI] 
MOV a,AX 
MOV AX, 
CMP AX, 
JMP etiquette 19
etiquette17:MOV AX, b
ADD AX, 1
MOV SI,9
ADD SI,SI
MOV t[SI],AX 
MOV SI,9
ADD SI,SI
MOV AX,t[SI] 
MOV b,AX 
FIN :
MOV AH,4CH
INT 21h
CODE ENDS
END MAIN
