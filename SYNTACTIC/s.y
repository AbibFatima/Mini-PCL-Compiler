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
%token IDF AFF ENTIER REEL CODE VAR CONST STRUCT ';' INTEGER FLOAT '(' ')' ',' '{' '}' AND OR NOT GREATER LESS GREATEREQUAL LESSEQUAL EQUAL NOTEQUAL IF ELSE WHILE  FOR COMMENT
%left ADD SUB
%left MUL DIV

%%
s: 	IDF '{' VAR '{' declar '}' CODE '{' inst '}' '}'
	;

declar: INTEGER  listidf ';' declar {printf ("reduction declar integer\n");}
	    | FLOAT listidf ';' declar {printf ("reduction declar float\n");}
	    | CONST declarConst ';' declar {printf ("reduction declar const\n");}
		| STRUCT '{' declarStruct '}' IDF ';' declar {printf ("reduction declar structure\n");}
		| IDF listidf ';' declar {printf ("reduction declar idf structure\n");}
		|
	    ;

listidf:	IDF ',' listidf 
        	| IDF 
        	;

declarStruct : 	INTEGER IDF ',' declarStruct
				| FLOAT IDF ',' declarStruct
				|
				;

declarConst : 	IDF AFF ENTIER
				| IDF AFF REEL 
				;

inst:   instaff ';' inst {printf ("reduction affectation\n"); } 
		| instif ';' inst {printf ("reduction condition if\n"); } 
		| instwhile ';' inst {printf ("reduction boucle while\n"); } 
		|
	    ;

instaff : IDF AFF exp
		;

exp: exp ADD exp {printf ("reduction addition\n");}
	| exp SUB exp {printf ("reduction soustraction\n");}	
	| exp DIV exp {printf ("reduction div\n");}
	| exp MUL exp {printf ("reduction mul\n");}
	| IDF {printf ("reduction terminal idf dans exp\n"); }
	| ENTIER {printf ("reduction terminal entier dans exp\n");}
	| REEL {printf ("reduction terminal reel dans exp\n");}
	|'('exp')' {printf ("reduction exp parentheses dans exp\n");}
	;

instif:	IF '(' conditionexp ')' '{' inst '}'
        ;

instwhile:  WHILE '(' conditionexp ')' '{' inst '}'
            ;

conditionexp :  condition  AND conditionexp
				|  condition  OR conditionexp
				| condition
				;
condition:	exp GREATER exp
			| exp LESS exp
			| exp EQUAL exp
			| exp GREATEREQUAL exp
			| exp LESSEQUAL exp 
			| exp NOTEQUAL exp 
			| NOT exp
            ;
%%
int yyerror (char* msg){
    printf (" %s ligne %d  \n",msg,ligne,col); exit (0);return 1;}

int main (){ 
    yyin = fopen("test.txt", "r");
    yyparse();
    fclose (yyin);
}