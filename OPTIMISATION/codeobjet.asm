DATA SEGMENT 
sarra DW ?
maria DW ?
soumia DW ?
b DW ?
a DW ?
x DW ?
i DW ?
j DW ?
n DW ?
y DD ?
tableau DW 7 dup (?) 
matricul DW ?
moyenne DW ?
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

MOV AX, 5
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
MOV t[7],0  
etiquette12:MOV SI,7
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 17
etiquette13:MOV AX, a
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
MOV AX, b
ADD AX, 1
MOV SI,9
ADD SI,SI
MOV t[SI],AX 
etiquette17:MOV SI,9
ADD SI,SI
MOV AX,t[SI] 
MOV b,AX 
MOV AX, a
CMP AX,555 
JB etiquette 22
etiquette19:MOV t[1],1  
MOV AX, 
CMP AX, 
JMP etiquette 23
MOV t[1],0  
etiquette22:MOV AX, b
CMP AX,0 
JNE etiquette 26
etiquette23:MOV t[1],1  
MOV AX, 
CMP AX, 
JMP etiquette 27
MOV t[1],0  
etiquette26:MOV AX, b
CMP AX,5 
JG etiquette 30
etiquette27:MOV t[1],1  
MOV AX, 
CMP AX, 
JMP etiquette 31
MOV t[1],0  
etiquette30:MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JNZ etiquette 35
etiquette31:MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JNZ etiquette 35
MOV t[1],0  
MOV AX, 
CMP AX, 
JMP etiquette 36
MOV t[1],1  
etiquette35:etiquette35:MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 40
etiquette36:MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 40
MOV t[1],1  
MOV AX, 
CMP AX, 
JMP etiquette 41
MOV t[1],0  
etiquette40:etiquette40:MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 44
etiquette41:MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV n,AX 
MOV AX, 
CMP AX, 
JMP etiquette 52
MOV AX, a
CMP AX,555 
JB etiquette 47
etiquette44:MOV t[1],1  
MOV AX, 
CMP AX, 
JMP etiquette 48
MOV t[1],0  
etiquette47:MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 51
etiquette48:MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV b,AX 
MOV AX, 
CMP AX, 
JMP etiquette 52
MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV n,AX 
etiquette51:MOV i,0 
etiquette52:etiquette52:MOV AX, i
CMP AX,n 
JG etiquette 57
MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV x,AX 
MOV AX, i
ADD AX, 5
MOV i,AX 
MOV AX, 
CMP AX, 
JMP etiquette 53
MOV i,33 
etiquette57:MOV AX, i
CMP AX,n 
JG etiquette 66
MOV j,3 
MOV AX, j
CMP AX,i 
JG etiquette 64
MOV AX, j
ADD AX, 2
MOV j,AX 
MOV AX, 
CMP AX, 
JMP etiquette 60
MOV AX, i
ADD AX, 2
MOV i,AX 
MOV AX, 
CMP AX, 
JMP etiquette 58
etiquette64:MOV AX, y
CMP AX,x 
JBE etiquette 69
MOV t[1],1  
etiquette66:MOV AX, 
CMP AX, 
JMP etiquette 70
MOV t[1],0  
MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 73
etiquette69:MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV x,AX 
etiquette70:MOV AX, 
CMP AX, 
JMP etiquette 70
MOV AX, a
CMP AX,555 
JB etiquette 76
MOV t[1],1  
etiquette73:MOV AX, 
CMP AX, 
JMP etiquette 77
MOV t[1],0  
MOV AX, idf1
CMP AX,idf2 
JE etiquette 80
etiquette76:MOV t[1],1  
etiquette77:MOV AX, 
CMP AX, 
JMP etiquette 81
MOV t[1],0  
MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 85
etiquette80:MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 85
etiquette81:MOV t[1],1  
MOV AX, 
CMP AX, 
JMP etiquette 86
MOV t[1],0  
MOV AX, b
CMP AX,0 
JE etiquette 89
etiquette85:etiquette85:MOV t[2],1  
etiquette86:MOV AX, 
CMP AX, 
JMP etiquette 90
MOV t[2],0  
MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 94
etiquette89:MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 94
etiquette90:MOV t[2],1  
MOV AX, 
CMP AX, 
JMP etiquette 95
MOV t[2],0  
MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 101
etiquette94:etiquette94:MOV AX, b
ADD AX, 2
MOV SI,2
ADD SI,SI
MOV t[SI],AX 
etiquette95:MOV SI,2
ADD SI,SI
MOV AX,t[SI] 
MOV a,AX 
MOV AX, b
ADD AX, 2
MOV SI,2
ADD SI,SI
MOV t[SI],AX 
MOV SI,2
ADD SI,SI
MOV AX,t[SI] 
MOV b,AX 
MOV AX, 
CMP AX, 
JMP etiquette 95
FIN :
MOV AH,4CH
INT 21h
CODE ENDS
END MAIN
