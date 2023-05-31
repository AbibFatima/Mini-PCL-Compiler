%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TS.h"
#include "RS.h"
#include "quad.h"
 
int indice_tab_expr = 0; 
float value;

int yylex();
int yyerror(char *);

extern FILE* yyin;
extern int ligne, col;

int type;
int nature;
int size=0 ;
char* Op;

/* QUAD IF */
int deb_else=0;
int qc=0;
int Fin_if=0;
char tmp[20];

%}

%start s
%union {
	char* nom;
	int ent;
	float reel;
}

%token<ent> ENTIER
%token<reel> REEL
%token<nom> IDF AFF CODE VAR CONST STRUCT ':' ';' INTEGER FLOAT '(' ')' ','  '{' '}' '[' ']' AND OR NOT GREATER LESS GREATEREQUAL LESSEQUAL EQUAL NOTEQUAL IF ELSE WHILE FOR COMMENT

%left ADD SUB
%left MUL DIV
%type<ent> expression
%type<ent> DECLARATION_Tableau
%%	
s: 	IDF '{' VAR '{' DECLARATION '}' CODE '{' Instructions '}' '}' { printf ("\nprogramme syntaxiquement juste.\n");YYACCEPT ;}
	;

DECLARATION : 	DECLARATION_Variables ';' DECLARATION 
				| DECLARATION_Struct ';' DECLARATION 
				| DECLARATION_Struct_Var ';' DECLARATION 
				| DECLARATION_Tableau ';' DECLARATION
				| DECLARATION_Const ';' DECLARATION 
				| COMMENT DECLARATION 
				|
				;

DECLARATION_Variables : TYPE liste_idf  
						;

liste_idf:	IDF ',' liste_idf { if(doubleDec($1)==1){
									yyerror("Double declaration");
								} else { inserer($1,type,nature,size,0); }
							}
        	| IDF  { 	if(doubleDec($1)==1){
								yyerror("Double declaration");
						} else { inserer($1,type,nature,size,0);}
					}
        	;			

DECLARATION_Struct : STRUCT '{' declarStructFields '}' IDF { 
																if(doubleDec($5)==1){
																	yyerror("Double declaration");
																} else {
																	type=0; 
																	nature=2; 
																	size=0; 
																	inserer($5,type,nature,size,0);
																}
					}
					;

DECLARATION_Struct_Var : STRUCT IDF {type=0; nature=2;} liste_idf ;

DECLARATION_Const : CONST IDF AFF literal {
											if(doubleDec($2)==1){
												yyerror("Double declaration");
											} else { 	
												nature=1; 
												size=0; 
												inserer($2,type,nature,size,0);
											}
					}
					;

DECLARATION_Tableau : 	TYPE IDF '[' ENTIER ']' {
													if(doubleDec($2)==1){
																	yyerror("Double declaration");
													} else {
														nature=3; 
														inserer ($2,type,nature,$4,0);
													}
					}
					;

declarStructFields : 	TYPE IDF ',' declarStructFields { 	if(doubleDec($2)==1){
																	yyerror("Double declaration");
															} else {
																	nature=0; 
																	size =0; 
																	inserer($2,type,nature,size,0);
															}
														}
					|
					;

TYPE : 	INTEGER { type=1; }
		| FLOAT { type=2; }
		;

literal : 	ENTIER { type=1; }
			| REEL { type=2; }
			;

Instructions : 	Inst Instructions
				|
				;

Inst:   Inst_AFF ';' 
		| Inst_IF  
		| Inst_WHILE  
		| Inst_FOR
		| COMMENT 
	    ;
		

Inst_AFF : 	IDF AFF expression {
									dec($1); 
									modifConstante($1);
									decTab($1);
									if (typeIdf($1)!=$3) 
										yyerror("erreur semantique incompatibilite des types affectation."); 
								}
			| IDF'[' ENTIER ']' AFF expression {
									decTab($1);
									modifConstante($1);
									if (typeIdf($1)!=$6) 
										yyerror("erreur semantique incompatibilite des types affectation."); 
								}
			;

Inst_IF:	B  ELSE '{' Instructions '}' {
						sprintf(tmp,"%d",qc);
						ajour_quad(Fin_if,1,tmp);
						printf("pgm juste");
			}
			| B {
					sprintf(tmp,"%d",qc);
					ajour_quad(Fin_if,1,tmp);
					printf("pgm juste");
			}
        	;

B :  A '{' Instructions '}' {
					Fin_if = qc;
					quadr("BR", " ","vide", "vide");
					sprintf(tmp,"%d",qc); 
					ajour_quad(deb_else,1,tmp);
			}

A : IF '(' Expression_Condition ')' {
						deb_else = qc;
						quadr("BZ", " ","temp_cond", "vide");
					}

Inst_WHILE: WHILE '(' Expression_Condition ')' '{' Instructions '}'
			;

Inst_FOR : 	FOR '(' Expression_FOR ')'  '{' Instructions '}' 
			;

Expression_FOR 	: Init_FOR ':' Pas_FOR ':' Cond_arret 
				; 
Init_FOR : 	IDF ':' literal {dec($1);} 
			;
Pas_FOR : literal 
		;
Cond_arret : 	IDF {dec($1);}
				| literal 
				;

Expression_Condition :  Condition  AND Expression_Condition
						| Condition  OR Expression_Condition
						| Condition
						;

Condition:	expression OP_expression expression | NOT expression
            ;

OP_expression : GREATER | LESS | EQUAL | GREATEREQUAL| LESSEQUAL | NOTEQUAL 
				;
	
expression: expression ADD expression { 
										if ($1!=$3) yyerror ("erreur semantique incompatibilite des types"); 
										$$=$1; 
									}
	| expression SUB expression { 
									if ($1!=$3) yyerror ("erreur semantique incompatibilite des types"); 
									$$=$1; 
								}	
	| expression DIV expression { 
									if ($1!=$3) yyerror ("erreur semantique incompatibilite des types"); 
									$$=$1; 
								}
	| expression MUL expression { 
									if ($1!=$3) yyerror ("erreur semantique incompatibilite des types"); 
									$$=$1; 
								}
	| IDF { 
			dec($1); 
			$$=typeIdf($1); 
			printf("IDF: %s\n", $1); 
		}
	| ENTIER { 
				$$=1; 
			}
	| REEL { 
				$$=2; 
			}
	|'(' expression ')' { 
							$$=$2; }
	;
%%
int yyerror (char* msg){
    printf ("%s : ligne %d, colonne %d \n",msg,ligne,col); 
	exit (0);
	return 1;
}

int main (){ 
    yyin = fopen("test.txt", "r");
    yyparse();
	//afficherTS();
	afficher_qdr();
	/*for (int i =0;i<indice_tab_expr;i++){
		printf(" %d \t| ",tab_expression[i]);
	}*/
    fclose (yyin);
}