#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TS.h"
#include "RS.h"

int yyerror (char*);

void doubleDec (char* el)
{  
if (recherche(el)!=-1){yyerror(strdup("erreur semantique double declaration d'un IDF \n"));}

}

void dec (char * el)
{ 
if (recherche(el)==-1){yyerror(strdup("erreur semantique IDF  non declare \n"));}

}

void divZero(int indice){
    
    /*if(strcmp(op,"/") == 0 & atoi(opd) == 0){
        yyerror(strdup("erreur semantique division par zero \n"));
    }
    */
    int i=0;
    for(i; i<indice; i++){ 
        if( strcmp(tab_expression[i],"/") == 0 && strcmp(tab_expression[i+1],"0")==0 ) {
            yyerror(strdup("erreur semantique division par zero \n"));
        }
    }
    
}

void incompType(char * el1, char* el2){
    if(typeIdf(el1) != typeIdf(el2)){
        yyerror(strdup("erreur semantique incompatibilité de type \n"));
    }
}

void modifConstante(char * el){
    int k = recherche(el);
    if( k != -1 && TS[k].nature == 1 ){
        yyerror(strdup("erreur semantique modification de constante \n"));
    }

}