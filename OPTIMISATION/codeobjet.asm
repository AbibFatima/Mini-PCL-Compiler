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
idf1 DW ?
idf2 DD ?
idf3 DW ?
idf4 DD ?
idf5 DD ?
temp DW 100 dup (?) 
DATA ENDS

CODE SEGEMENT
ASSUME CS:CODE, DS:DATA
MAIN :
MOV AX,DATA
MOV DS,AX

MOV AX, b
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
FIN :
MOV AH,4CH
INT 21h
CODE ENDS
END MAIN
