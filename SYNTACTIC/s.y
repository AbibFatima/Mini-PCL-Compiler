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
%token IDF AFF ENTIER REEL CODE VAR CONST STRUCT ';' INTEGER FLOAT '(' ')' ',' '{' '}' AND OR NOT GREATER LESS GREATEREQUAL LESSEQUAL EQUAL NOTEQUAL IF ELSE WHILE FOR COMMENT
%left ADD SUB
%left MUL DIV

%%
s: 	IDF '{' VAR '{' declar '}' CODE '{' instructions '}' '}' ;

declar : 	vardeclar ';' declar
			| structdeclar ';' declar
			| constdeclar ';' declar
			| COMMENT declar
			|;

vardeclar : type listidf;

structdeclar : 	STRUCT '{' declarStructFields '}' IDF ;

constdeclar : 	CONST IDF AFF literal ;

declarStructFields : 	type IDF ',' declarStructFields
						|;

type : 	INTEGER | FLOAT | IDF
		;

listidf:	IDF ',' listidf 
        	| IDF 
        	;

literal : 	ENTIER | REEL ;

instructions : 	inst instructions
				| ;

inst:   instaff ';' {printf ("reduction affectation\n"); } 
		| instif  {printf ("reduction condition if\n"); } 
		| instwhile  {printf ("reduction boucle while\n"); } 
		| instfor {printf ("reduction boucle for\n"); } 
		| COMMENT inst
	    ;

instaff : IDF AFF exp ;

instif:	IF '(' conditionexp ')' '{' instructions '}' ELSE '{' instructions '}' {printf ("reduction IF ELSE\n");} 
		|  IF '(' conditionexp ')' '{' instructions '}' {printf ("reduction IF\n");}
        ;

instwhile:  WHILE '(' conditionexp ')' '{' instructions '}'

instfor : 	FOR '(' initfor ':' literal ':' conditionarret ')' '{' instructions '}' ;

initfor : 	IDF ':' literal
			;

conditionarret : IDF | literal ;

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
    printf (" %s ligne %d  \n",msg,ligne,col); exit (0);return 1;
}

int main (){ 
    yyin = fopen("test.txt", "r");
    yyparse();
    fclose (yyin);
}