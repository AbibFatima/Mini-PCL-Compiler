%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylex();
int yyerror(char *);

extern FILE* yyin;
extern int ligne, col;
%}

%union {char* nom;}
%token IDF AFF ENTIER REEL CODE VAR CONST STRUCT ';' INTEGER FLOAT '(' ')' ',' ':' '{' '}' '[' ']' AND OR NOT GREATER LESS GREATEREQUAL LESSEQUAL EQUAL NOTEQUAL IF ELSE WHILE FOR COMMENT
%left ADD SUB
%left MUL DIV

%%
s: 	IDF '{' VAR '{' DECLARATION '}' CODE '{' Instructions '}' '}' ;

DECLARATION : DECLARATION_Variables ';' DECLARATION 
			| DECLARATION_Struct ';' DECLARATION 
			| DECLARATION_Struct_Var ';' DECLARATION 
			| DECLARATION_Tableau ';' DECLARATION
			| DECLARATION_Const ';' DECLARATION
			| COMMENT DECLARATION 
			|;

DECLARATION_Variables : TYPE liste_idf ;

DECLARATION_Struct : STRUCT '{' declarStructFields '}' IDF ;

DECLARATION_Struct_Var : STRUCT IDF liste_idf  ;

DECLARATION_Const :  CONST IDF AFF literal ;

DECLARATION_Tableau : 	TYPE IDF '[' literal ']' 
						;
TYPE : 	INTEGER 
		| FLOAT 
		;

liste_idf:	IDF ',' liste_idf 
        	| IDF 
        	;

declarStructFields : 	TYPE IDF ',' declarStructFields
						|;

literal : 	ENTIER | REEL ;

Instructions : 	Inst Instructions
				|;

Inst:   Inst_AFF ';'
		| Inst_IF  
		| Inst_WHILE  
		| Inst_FOR
		| COMMENT Inst
	    ;

Inst_AFF : IDF AFF expression ;

Inst_IF:	IF '(' Expression_Condition ')' '{' Instructions '}' ELSE '{' Instructions '}' 
			|  IF '(' Expression_Condition ')' '{' Instructions '}' 
        	;

Inst_WHILE: WHILE '(' Expression_Condition ')' '{' Instructions '}'
			;

Inst_FOR : 	FOR '(' Expression_FOR ')'  '{' Instructions '}' 
			;

Expression_FOR : Init_FOR ':' Pas_FOR ':' Cond_arret ; 
Init_FOR : IDF ':' literal ;
Pas_FOR : literal ;
Cond_arret : IDF | literal;

Expression_Condition :  Condition  AND Expression_Condition
						| Condition  OR Expression_Condition
						| Condition
						;

Condition:	expression OP_expression expression 
			| NOT expression
            ;

OP_expression : GREATER {printf ("reduction sup\n");}
				| LESS {printf ("reduction inf\n");}
				| EQUAL {printf ("reduction egale\n");}
				| GREATEREQUAL {printf ("reduction sup egale\n");}
				| LESSEQUAL {printf ("reduction inf egale\n");}
				| NOTEQUAL {printf ("reduction pas egale\n");}
				;

expression: expression ADD expression {printf ("reduction addition\n");}
	| expression SUB expression {printf ("reduction soustraction\n");}	
	| expression DIV expression {printf ("reduction div\n");}
	| expression MUL expression {printf ("reduction mul\n");}
	| IDF {printf ("reduction terminal idf dans exp\n"); }
	| ENTIER {printf ("reduction terminal entier dans exp\n");}
	| REEL {printf ("reduction terminal reel dans exp\n");}
	|'(' expression ')' {printf ("reduction exp parentheses dans exp\n");}
	;
%%
int yyerror (char* msg){
    printf ("%s : ligne %d, colonne %d \n",msg,ligne,col); exit (0);return 1;
}

int main (){ 
    yyin = fopen("test.txt", "r");
    yyparse();
	printf("good");
    fclose (yyin);
}