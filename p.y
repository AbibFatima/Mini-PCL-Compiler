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
%token IDF AFF ENTIER REEL ';' INTEGER FLOAT '(' ')' ',' '{' '}' AND OR NOT GREATER LESS GREATEREQUAL LESSEQUAL EQUAL NOTEQUAL IF ELSE WHILE CODE VAR CONST STRUCT FOR COMMENT
%left ADD SUB
%left MUL DIV

%%
s: IDF '{' VAR '{' declar '}' CODE '{' inst '}' '}'

declar: INTEGER  listidf ';' declar {printf ("reduction declar integer\n");}
	    | FLOAT listidf ';' declar {printf ("reduction declar float\n");}
	    | 
	    ;

listidf:	IDF ',' listidf 
        	| IDF 
        	;


inst:   IDF AFF exp ';' inst {printf ("reduction affectation\n"); } 
		| instif ';' inst
		| instwhile ';' inst
		|
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

conditionexp : '(' condition ')' AND conditionexp
				| '(' condition ')' OR conditionexp
				| condition
				;
condition:	exp GREATER exp
			| exp LESS exp
			| exp EQUAL exp
			| exp GREATEREQUAL exp
			| exp LESSEQUAL exp 
			| exp NOTEQUAL exp 
			| NOT exp

%%
int yyerror (char* msg){
    printf (" %s ligne %d  \n",msg,ligne,col); exit (0);return 1;}

int main (){ 
    yyin = fopen("in.txt", "r");
    yyparse ();
    fclose (yyin);
}