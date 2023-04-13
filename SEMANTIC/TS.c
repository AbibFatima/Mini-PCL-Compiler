#include <stdio.h>
#include <string.h>
#include "TS.h"

int indexTS =0;

int recherche (char * el)
{
	int i=0;
	while (i<indexTS && strcmp(TS[i].nom,el)) i++;
	if (i==indexTS) return -1;
	return i;
}

void inserer (char* el, int typ, int natur)
{
	TS[indexTS].nom=el;
	TS[indexTS].type=typ;
	TS[indexTS].nature=natur;
	indexTS ++;
}


void afficherTS ()
{
	int i=0; 
	printf("\n/***************Table des symboles *************/\n");
    printf("____________________________________________________________________\n");
    printf("\t|\t Nom \t|\t Type \t|\t Nature \t| \n");
    printf("____________________________________________________________________\n");
	
	for (i=0;i<indexTS;i++)
		printf ("\t\t %s \t\t  %d \t\t %d \n",TS[i].nom, TS[i].type,TS[i].nature);			  
}


int typeIdf(char* el)
{ 
	return TS[recherche(el)].type;
}

/*
double getvaleur(char* nom) {
    int i = recherche(nom);
    if (i == -1) {
        printf("Erreur : la variable %s n'a pas été déclarée\n", nom);
        exit(1);
    }
    return TS[i].valeur;
}


*/
