#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TS.h"
#include "RS.h"

int yyerror (char*);

int doubleDec (char* el)
{  
    if (recherche(el)!=-1){
        return 1;
    } else {
        return 0;
    }
}

void dec (char * el)
{ 
    if (recherche(el)==-1){
        yyerror(strdup("erreur semantique IDF  non declare "));
    }

}
/*
void divZero(int indice){
    
    /*if(strcmp(op,"/") == 0 & atoi(opd) == 0){
        yyerror(strdup("erreur semantique division par zero \n"));
    }
    *//*
    int i=0;
    for(i; i<indice; i++){ 
        if( strcmp(tab_expression[i],"/") == 0 && strcmp(tab_expression[i+1],"0")==0 ) {
            yyerror(strdup("erreur semantique division par zero \n"));
        }
    }
    
}
*/

void modifConstante(char * el){
    int k = recherche(el);
    if( k != -1 && strcmp(TS[k].nature,"Constante")==0 ){
        yyerror(strdup("erreur semantique modification de constante"));
    }

}

void decTab (char* el){
    if (recherche(el)==-1 && strcmp(natureIdf(el),"Tableau")==0){
        yyerror(strdup("erreur semantique IDF Tableau non declare"));
    }
}


int decStruct(char *el)
{
    if (recherche(el) == -1 && strcmp(natureIdf(el),"Structure")!=0)
    {
        return 0;
    }
    else
        return 1;
}