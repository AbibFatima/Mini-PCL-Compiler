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
s: 	IDF '{' VAR '{' declar '}' CODE '{' instructions '}' '}' ;

declar : 	vardeclar ';' declar {printf ("reduction vardeclar\n"); } 
			| structdeclar ';' declar {printf ("reduction struct declar\n"); }
			| structelemdeclar ';' declar {printf ("reduction struct elem declar\n"); }
			| constdeclar ';' declar {printf ("reduction const declar\n"); }
			| COMMENT declar {printf ("reduction comment declar\n"); }
			|;

vardeclar : type listidf ;

structdeclar : 	STRUCT '{' vardeclar '}' IDF ;

structelemdeclar : STRUCT IDF listidf  ;

constdeclar : 	CONST IDF AFF literal ;

type : 	INTEGER {printf ("reduction mot cle INTEGER dans type\n");}
		| FLOAT {printf ("reduction mot cle FLOAT dans type\n");}
		;

listidf:	IDF ',' listidf {printf ("reduction : IDF,listidf dans listidf\n");}
			| tabdeclar ',' listidf {printf ("reduction : tabdeclar,listidf dans listidf\n");}
			| tabdeclar {printf ("reduction : tabdeclar dans listidf\n");}
        	| IDF {printf ("reduction : IDF dans listidf  \n");}
        	;

tabdeclar :  IDF '[' ENTIER ']' {printf ("reduction tabdeclar\n");};

literal : 	ENTIER | REEL ;

instructions : 	inst instructions
				| ;

inst:   instaff ';' {printf ("reduction affectation\n"); } 
		| instif  {printf ("reduction condition if\n"); } 
		| instwhile  {printf ("reduction boucle while\n"); } 
		| instfor {printf ("reduction boucle for\n"); } 
		| COMMENT inst {printf ("reduction comment dans inst\n"); } 
	    ;

instaff : IDF AFF exp ;

instif:	IF '(' conditionexp ')' '{' instructions '}' ELSE '{' instructions '}' {printf ("reduction IF ELSE\n");} 
		|  IF '(' conditionexp ')' '{' instructions '}' {printf ("reduction IF\n");}
        ;

instwhile:  WHILE '(' conditionexp ')' '{' instructions '}'
			;

instfor : 	FOR '(' initfor ':' pasfor ':' conditionarret ')' '{' instructions '}' 
			;

initfor : 	IDF ':' literal
			;

pasfor : 	literal
			;

conditionarret : IDF  
				 ;

conditionexp :  condition  AND conditionexp
				| condition  OR conditionexp
				| condition
				;

condition:	exp opcomparaison exp 
			| NOT exp
            ;

opcomparaison : GREATER {printf ("reduction sup\n");}
				| LESS {printf ("reduction inf\n");}
				| EQUAL {printf ("reduction egale\n");}
				| GREATEREQUAL {printf ("reduction sup egale\n");}
				| LESSEQUAL {printf ("reduction inf egale\n");}
				| NOTEQUAL {printf ("reduction pas egale\n");}
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
%%
int yyerror (char* msg){
    printf ("%s : ligne %d, colonne %d \n",msg,ligne,col); exit (0);return 1;
}

int main (){ 
    yyin = fopen("test.txt", "r");
    yyparse();
    fclose (yyin);
}