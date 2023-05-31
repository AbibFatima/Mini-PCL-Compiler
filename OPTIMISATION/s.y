%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TS.h"
#include "RS.h"
#include "RS.c"
#include "Quad.h"
#include "Quad.c"
#include "optimisation.h"
#include "optimisation.c"
#include "codeobjet.h"
#include "codeobjet.c"

int yylex();
int yyerror(char *);

extern FILE* yyin;
extern int ligne, col;

/** RS **/ 
int sauv_size;


/* La table des symboles */
int size=0 ;
char sauvVal[20];
char sauvType[20];
char sauvNature[20];

/*****/
char  *sauv_idf;
int nTemp=1;
char tempC[12]="";
char val[12]="";

/** IF ELSE BOUCLE WHILE FOR **/
int fin_pos , else_pos, sauv_debut_while, sauv_deb_for;


%}
%start s
%union {
	char* nom;
	int ent;
	float reel;
	struct {	int type;
				char* res;
				float  val;
			}NT;
}
%token<ent> ENTIER
%token<reel> REEL
%token<nom> IDF AFF CODE VAR CONST STRUCT ':' ';' '.' INTEGER FLOAT '(' ')' ','  '{' '}' '[' ']' AND OR NOT GREATER LESS GREATEREQUAL LESSEQUAL EQUAL NOTEQUAL IF ELSE WHILE FOR COMMENT

%left ADD SUB
%left MUL DIV
%left AND
%left OR


%type<NT> expression Condition EXP_AR DEBUT_WHILE INIT 
%type<ent> DECLARATION_Tableau DECLARATION_Const

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

liste_idf:	IDF ',' liste_idf { 
								empiler_Str(&sauv_var,strdup($1));
								if(doubleDec($1)==1){
									yyerror("Erreur semantique Double declaration");
								} else { inserer($1,sauvType,"Variable",size," "); }
							}
        	| IDF  { 	
						empiler_Str(&sauv_var,strdup($1));
						if(doubleDec($1)==1){
								yyerror("Erreur semantique Double declaration");
						} else { inserer($1,sauvType,"Variable",size," ");}
					}
        	;			

DECLARATION_Struct : STRUCT '{' declarStructFields '}' IDF { 
																if(doubleDec($5)==1){
																	yyerror("Double declaration");
																} else {
																	strcpy(sauvType," ");
																	inserer($5,sauvType,"Structure",0," ");
																}
					}
					;

DECLARATION_Struct_Var : STRUCT IDF {strcpy(sauvType,$2); strcpy(sauvNature,"Structure"); } liste_idf ;

DECLARATION_Const : CONST IDF AFF ENTIER {
											if(doubleDec($2)==1){
												yyerror("Double declaration");
											} else { 	
												sprintf(sauvVal,"%d",$4);
												inserer($2,"INTEGER","Constante",0,sauvVal);
											}
					} 
					| CONST IDF AFF REEL {
											if(doubleDec($2)==1){
												yyerror("Double declaration");
											} else { 	
												sprintf(sauvVal,"%f",$4);
												inserer($2,"FLOAT","Constante",0, sauvVal);
											}
					}
					;

DECLARATION_Tableau : 	TYPE IDF '[' ENTIER ']' {
													if(doubleDec($2)==1){
														yyerror("Double declaration");
													} else {
														inserer ($2,sauvType,"Tableau",$4," ");
														sauv_size = $4;
													}
					}
					;


declarStructFields : 	TYPE IDF ',' declarStructFields { 	if(doubleDec($2)==1){
																	yyerror("Double declaration");
															} else {
																	inserer($2,sauvType,"Variable",0," ");
															}
														}
					|
					;

TYPE : 	INTEGER { strcpy(sauvType,"INTEGER"); }
		| FLOAT { strcpy(sauvType,"FLOAT"); }
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
									if (typeIdf($1)!=$3.type) 
										{
											if (typeIdf($1) != 2)  yyerror("erreur semantique incompatibilite des types affectation."); 
										}				
									quad (":=",$3.res,"",$1);
								}
			| IDF'[' ENTIER ']' AFF expression {
									decTab($1);
									modifConstante($1);
									if (typeIdf($1)!=$6.type) 
										yyerror("erreur semantique incompatibilite des types affectation."); 
									if (($3) > sauv_size)
									    yyerror("erreur semantique depassement de la taille du tableau."); 
								}
			| IDF '.' IDF AFF expression { 
				                            if (decStruct($1) == 0) yyerror("erreur semantique structure n'existe pas ."); 
											else {
												dec($3);
												modifConstante($3);	 
                                                if (typeIdf($3)!=$5.type)  
												yyerror("erreur semantique incompatibilite des types affectation.");
											}							 
			}
			;


Inst_IF	:	A '}' {	
					indq--; 
					fin_pos = depiler_qc(&pile1);
				}
      		| A '}' ELSE '{' Instructions '}' {
											fin_pos = depiler_qc(&pile1); 
											q[fin_pos].op1= ToSTR(indq);
										}
			;

A	: B  Instructions { 
						else_pos = depiler_qc(&pile1); 
						q[else_pos].op1= ToSTR(indq+1); 
						empiler_qc(&pile1, indq); 
						quad("BR","","","");
					}
	;

B	: IF '(' Condition ')' '{' {
						empiler_qc(&pile1, indq); 
						quad("BZ","",strdup($3.res),"");
					} 
	;


Inst_WHILE	:  DEBUT_WHILE Instructions '}'  {
									quad("BR",ToSTR(sauv_debut_while),"",""); 
									q[sauv_debut_while].op1= ToSTR(indq); 
			}
			;

DEBUT_WHILE : WHILE '(' Condition ')' '{' {
									empiler_qc(&pile2,indq); 
									sauv_debut_while= depiler_qc(&pile2);  
									quad("BZ","",strdup($3.res),"")
			}
			;


Inst_FOR 	: DEBUT_FOR  '{'  Instructions '}' { 
           					sauv_idf = depiler(&sauv_var); 
							quad("+",strdup(sauv_idf),"1",strdup(sauv_idf)); 
           					sauv_deb_for = depiler_qc(&pileFOR); 
							quad("BR",ToSTR(sauv_deb_for),"",""); 
							q[sauv_deb_for].op1= ToSTR(indq); 
         	}
			;

DEBUT_FOR 	: FOR '(' IDF ':' INIT ':' ENTIER ':' INIT ')'{ 
            				dec($3); 
							quad("=",$5.res,"",$3); 
							empiler_qc(&pileFOR,indq); 
							quad("BG","",$3,$9.res); 
							empiler_Str(&sauv_var, $3);
        	}
			;

INIT 	: ENTIER { $$.res = ToSTR($1); }
      	| IDF { $$.res = strdup($1);  dec($1); }
		;


Condition: 	EXP_AR NOTEQUAL EXP_AR {
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								$$.res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(1,$1.res,$3.res,$$.res);
							}
         	| EXP_AR EQUAL EXP_AR {
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								$$.res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(2,$1.res,$3.res,$$.res);
							}
          	| EXP_AR LESS EXP_AR{
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								$$.res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(3,$1.res,$3.res,$$.res);
							}
          	| EXP_AR GREATER EXP_AR  { 
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								$$.res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(4,$1.res,$3.res,$$.res);
							}
         	| EXP_AR GREATEREQUAL EXP_AR {
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								$$.res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(5,$1.res,$3.res,$$.res);
							}
          	| EXP_AR LESSEQUAL EXP_AR {
								sprintf(tempC, "T%d",nTemp);
								nTemp++;
								$$.res=strdup(tempC);
								tempC[0]='\0'; 
								createQuadCompare(6,$1.res,$3.res,$$.res);
							}
			| NOT Condition {
							sprintf(tempC, "T%d",nTemp);
							nTemp++;
							$$.res=strdup(tempC);
							tempC[0]='\0'; 
							createQuadLogic(1,$2.res,NULL,$$.res);
						}
          	| Condition  OR  Condition {
										sprintf(tempC, "T%d",nTemp);
										nTemp++;
										$$.res=strdup(tempC);
										tempC[0]='\0'; 
										createQuadLogic(2,$1.res,$3.res,$$.res);
									}
          	| Condition AND Condition  {
											sprintf(tempC, "T%d",nTemp);
											nTemp++;
											$$.res=strdup(tempC);
											tempC[0]='\0'; 
											createQuadLogic (3,$1.res,$3.res,$$.res);
										}
			| EXP_AR
;
                   
EXP_AR 	: expression { $$.res = $1.res; }
		;    


expression: expression ADD expression { 
										if ($1.type!=$3.type) 
											yyerror ("erreur semantique incompatibilite des types"); 
										sprintf(tempC, "T%d",nTemp);
										nTemp++;
										
										$$.res=strdup(tempC);	
										tempC[0]='\0'; 
										quad ("+",$1.res,$3.res,$$.res);
										float resultat = $1.val + $3.val;
										$$.type = $1.type;
                                        $$.val = resultat;
										//printf("Resultat de l'addition : %.2f\n", resultat);
									}
	| expression SUB expression { 
									if ($1.type!=$3.type) 
										yyerror ("erreur semantique incompatibilite des types"); 
									sprintf(tempC, "T%d",nTemp);
									nTemp++;
									$$.res=strdup(tempC);	
									tempC[0]='\0'; 
									quad ("-",$1.res,$3.res,$$.res);
									float resultat = $1.val - $3.val;
									$$.type = $1.type;
                                    $$.val = resultat;
									//printf("Resultat de la soustraction : %.2f\n", resultat);
								}	
	| expression DIV expression {   if ($3.val==0) {yyerror("erreur semantique division sur 0") ;}
									if ($1.type!=$3.type) 
										yyerror ("erreur semantique incompatibilite des types"); 
									sprintf(tempC, "T%d",nTemp);
									nTemp++;
									$$.res=strdup(tempC);	
									tempC[0]='\0'; 
									quad ("/",$1.res,$3.res,$$.res);
									float resultat = $1.val / $3.val;
									$$.type = $1.type;
                                    $$.val = resultat;
									//printf("Resultat de la division : %.2f\n", resultat);
									
								}
	| expression MUL expression { 
									if ($1.type!=$3.type) 
										yyerror ("erreur semantique incompatibilite des types"); 
									sprintf(tempC, "T%d",nTemp);
									nTemp++;
									$$.res=strdup(tempC);	
									tempC[0]='\0'; 
									quad ("*",$1.res,$3.res,$$.res);
									float resultat = $1.val * $3.val;
									$$.type = $1.type;
                                    $$.val = resultat;
									//printf("Resultat de la multiplication : %.2f\n", resultat);

								}
	| IDF { 
			dec($1); 
			$$.type=typeIdf($1); 
			$$.res=strdup($1);      
			$$.val=1;
		}
	| ENTIER { 
				$$.type=1;
				sprintf(val, "%d",$1); $$.res=strdup(val); $$.val=$1; 
			}
	| REEL { 
				$$.type=2; 
				sprintf(val, "%f",$1); $$.res=strdup(val);  $$.val=$1;    
			}
	|'(' expression ')' { 
			$$.type=$2.type; 
			$$.res=$2.res; 
		}
	| IDF '.' IDF { 
			if (decStruct($1) == 0 ) yyerror ("erreur semantique structure n'existe pas"); 
			else dec($3); 	
		}
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
	
	//printf("\n------------------ LA TABLE DES SYMBOLES ----------------------\n");
	afficherTS();
	printf("\n------------------ LES QUADRUPLETS AVANT OPTIMISATION ----------------------\n");
	afficherQuad();
	//optimiser les quadruplets
	//optimisation();
	printf("\n------------------LES QUADRUPLETS APRES OPTIMISATION----------------------\n");
	//afficherQuad();
	printf("\n------------------ GENERATION DU CODE OBJET ----------------------\n");
	assembler();

    fclose (yyin);
}