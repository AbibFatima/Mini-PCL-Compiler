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
ADD AX, 5
MOV SI,1
ADD SI,SI
MOV t[SI],AX 
MOV SI,1
ADD SI,SI
MOV AX, t[SI]
DIV AX, 2
MOV SI,2
ADD SI,SI
MOV t[SI],AX 
MOV AX, b
MUL AX, 9
MOV SI,3
ADD SI,SI
MOV t[SI],AX 
MOV SI,2
ADD SI,SI
MOV AX, t[SI] 
ADD AX,t[3]
 MOV SI,4
ADD SI,SI
MOV t[SI],AX 
MOV SI,4
ADD SI,SI
MOV AX, t[SI]
ADD AX, 1
MOV SI,5
ADD SI,SI
MOV t[SI],AX 
MOV SI,5
ADD SI,SI
MOV AX, t[SI]
SUB AX, 7
MOV SI,6
ADD SI,SI
MOV t[SI],AX 
MOV SI,6
ADD SI,SI
MOV AX,t[SI] 
MOV n,AX 
MOV AX, maria
MUL AX, a
MOV SI,7
ADD SI,SI
MOV t[SI],AX 
MOV SI,7
ADD SI,SI
MOV AX,t[SI] 
MOV sarra,AX 
MOV AX, a
CMP AX,b 
JE etiquette 13
MOV t[8],0  
MOV AX, 
CMP AX, 
JMP etiquette 14
MOV t[8],1  
etiquette13:MOV SI,8
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 18
etiquette14:MOV AX, a
DIV AX, 2
MOV SI,9
ADD SI,SI
MOV t[SI],AX 
MOV AX, 
CMP AX, 
JMP etiquette 
MOV AX, a
CMP AX,b 
JE etiquette 21
MOV t[1],0  
etiquette18:MOV AX, 
CMP AX, 
JMP etiquette 22
MOV t[1],1  
MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 26
etiquette21:MOV SI,9
ADD SI,SI
MOV AX, t[SI]
DIV AX, 2
MOV SI,1
ADD SI,SI
MOV t[SI],AX 
etiquette22:MOV SI,1
ADD SI,SI
MOV AX,t[SI] 
MOV a,AX 
MOV AX, 
CMP AX, 
JMP etiquette 28
MOV AX, b
ADD AX, 1
MOV SI,1
ADD SI,SI
MOV t[SI],AX 
MOV SI,1
ADD SI,SI
MOV AX,t[SI] 
MOV b,AX 
etiquette26:MOV AX, a
CMP AX,555 
JB etiquette 31
MOV t[1],0  
etiquette28:MOV AX, 
CMP AX, 
JMP etiquette 32
MOV t[1],1  
MOV AX, b
CMP AX,0 
JNE etiquette 35
etiquette31:MOV t[1],0  
etiquette32:MOV AX, 
CMP AX, 
JMP etiquette 36
MOV t[1],1  
MOV AX, b
CMP AX,5 
JG etiquette 39
etiquette35:MOV t[1],0  
etiquette36:MOV AX, 
CMP AX, 
JMP etiquette 40
MOV t[1],1  
MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JNZ etiquette 44
etiquette39:MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JNZ etiquette 44
etiquette40:MOV t[1],0  
MOV AX, 
CMP AX, 
JMP etiquette 45
MOV t[1],1  
MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 49
etiquette44:etiquette44:MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 49
etiquette45:MOV t[1],1  
MOV AX, 
CMP AX, 
JMP etiquette 50
MOV t[1],0  
MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 53
etiquette49:etiquette49:MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV n,AX 
etiquette50:MOV AX, 
CMP AX, 
JMP etiquette 61
MOV AX, a
CMP AX,555 
JB etiquette 56
MOV t[1],0  
etiquette53:MOV AX, 
CMP AX, 
JMP etiquette 57
MOV t[1],1  
MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 60
etiquette56:MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV b,AX 
etiquette57:MOV AX, 
CMP AX, 
JMP etiquette 61
MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV n,AX 
MOV i,0 
etiquette60:MOV AX, i
CMP AX,n 
JG etiquette 66
etiquette61:etiquette61:MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV x,AX 
MOV AX, i
ADD AX, 5
MOV i,AX 
MOV AX, 
CMP AX, 
JMP etiquette 62
MOV i,33 
MOV AX, i
CMP AX,n 
JG etiquette 75
etiquette66:MOV j,3 
MOV AX, j
CMP AX,i 
JG etiquette 73
MOV AX, j
ADD AX, 2
MOV j,AX 
MOV AX, 
CMP AX, 
JMP etiquette 69
MOV AX, i
ADD AX, 2
MOV i,AX 
MOV AX, 
CMP AX, 
JMP etiquette 67
MOV AX, y
CMP AX,x 
JBE etiquette 78
etiquette73:MOV t[1],0  
MOV AX, 
CMP AX, 
JMP etiquette 79
etiquette75:MOV t[1],1  
MOV SI,1
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 82
MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV x,AX 
etiquette78:MOV AX, 
CMP AX, 
JMP etiquette 75
etiquette79:MOV AX, a
CMP AX,555 
JB etiquette 85
MOV t[2],0  
MOV AX, 
CMP AX, 
JMP etiquette 86
etiquette82:MOV t[2],1  
MOV AX, idf1
CMP AX,idf2 
JE etiquette 89
MOV t[2],0  
etiquette85:MOV AX, 
CMP AX, 
JMP etiquette 90
etiquette86:MOV t[2],1  
MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 94
MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 94
etiquette89:MOV t[2],1  
etiquette90:MOV AX, 
CMP AX, 
JMP etiquette 95
MOV t[2],0  
MOV AX, b
CMP AX,0 
JE etiquette 98
MOV t[2],0  
etiquette94:etiquette94:MOV AX, 
CMP AX, 
JMP etiquette 99
etiquette95:MOV t[2],1  
MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 103
MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 103
etiquette98:MOV t[2],1  
etiquette99:MOV AX, 
CMP AX, 
JMP etiquette 104
MOV t[2],0  
MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 110
MOV AX, b
ADD AX, 2
MOV SI,2
ADD SI,SI
MOV t[SI],AX 
etiquette103:etiquette103:MOV AX, b
ADD AX, 2
MOV SI,2
ADD SI,SI
MOV t[SI],AX 
etiquette104:MOV AX, 
CMP AX, 
JMP etiquette 82
MOV AX, a
CMP AX,555 
JB etiquette 113
MOV t[2],0  
MOV AX, 
CMP AX, 
JMP etiquette 114
MOV t[2],1  
MOV AX, idf1
CMP AX,idf2 
JE etiquette 117
etiquette110:MOV t[2],0  
MOV AX, 
CMP AX, 
JMP etiquette 118
MOV t[2],1  
etiquette113:MOV AX, b
CMP AX,0 
JBE etiquette 121
etiquette114:MOV t[2],0  
MOV AX, 
CMP AX, 
JMP etiquette 122
MOV t[2],1  
etiquette117:MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JNZ etiquette 125
etiquette118:MOV t[3],1  
MOV AX, 
CMP AX, 
JMP etiquette 126
MOV t[3],0  
etiquette121:MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JNZ etiquette 130
etiquette122:MOV SI,3
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JNZ etiquette 130
MOV t[3],0  
MOV AX, 
CMP AX, 
JMP etiquette 131
etiquette125:MOV t[3],1  
etiquette126:MOV SI,2
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 135
MOV SI,3
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 135
MOV t[3],1  
MOV AX, 
CMP AX, 
JMP etiquette 136
etiquette130:etiquette130:MOV t[3],0  
etiquette131:MOV SI,3
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 164
MOV AX, a
CMP AX,2 
JG etiquette 140
MOV t[3],0  
MOV AX, 
CMP AX, 
JMP etiquette 141
etiquette135:etiquette135:MOV t[3],1  
etiquette136:MOV AX, b
CMP AX,j 
JBE etiquette 144
MOV t[3],0  
MOV AX, 
CMP AX, 
JMP etiquette 145
MOV t[3],1  
etiquette140:MOV SI,3
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JNZ etiquette 149
etiquette141:MOV SI,3
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JNZ etiquette 149
MOV t[3],0  
MOV AX, 
CMP AX, 
JMP etiquette 150
etiquette144:MOV t[3],1  
etiquette145:MOV SI,3
ADD SI,SI
MOV AX, t[SI]
CMP AX, 
JZ etiquette 158
MOV SI,2
ADD SI,SI
MOV AX, t[SI]
DIV AX, 2
MOV SI,3
ADD SI,SI
MOV t[SI],AX 
MOV SI,2
ADD SI,SI
MOV AX, t[SI]
MUL AX, 9
MOV SI,3
ADD SI,SI
MOV t[SI],AX 
MOV SI,3
ADD SI,SI
MOV AX, t[SI] 
ADD AX,t[3]
 MOV SI,3
ADD SI,SI
MOV t[SI],AX 
etiquette149:etiquette149:MOV SI,3
ADD SI,SI
MOV AX, t[SI]
ADD AX, 1
MOV SI,3
ADD SI,SI
MOV t[SI],AX 
etiquette150:MOV SI,3
ADD SI,SI
MOV AX, t[SI]
SUB AX, 7
MOV SI,4
ADD SI,SI
MOV t[SI],AX 
MOV SI,4
ADD SI,SI
MOV AX,t[SI] 
MOV n,AX 
MOV AX, 
CMP AX, 
JMP etiquette 163
MOV i,0 
MOV AX, i
CMP AX,n 
JG etiquette 163
MOV SI, 
ADD SI,SI
MOV AX,t[SI] 
MOV x,AX 
MOV AX, i
ADD AX, 5
MOV i,AX 
MOV AX, 
CMP AX, 
JMP etiquette 159
etiquette158:MOV AX, 
CMP AX, 
JMP etiquette 110
FIN :
MOV AH,4CH
INT 21h
CODE ENDS
END MAIN
