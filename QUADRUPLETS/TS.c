#include <stdio.h>
#include <string.h>
#include "TS.h"

int indexTS =0;

int recherche (char * el)
{
	int i=0;
	while (i<indexTS && strcmp(TS[i].nom,el)!=0) {	
		i++;
	}

	if (i==indexTS) return -1;
	return i;
}

void inserer (char *el, int typ, int natur,int siz,float value)
{
	TS[indexTS].nom=el;
	TS[indexTS].type=typ;
	TS[indexTS].nature=natur;
	TS[indexTS].size=siz;
	TS[indexTS].val=value;
	indexTS ++;
}

void afficherTS ()
{
	int i=0; 
	printf("\n/***************Table des symboles *************/\n");
    printf("____________________________________________________________________\n");
    printf("\t|\t Nom \t|\t Type \t|\t Nature \t|\t Taille  \t|\n");
    printf("____________________________________________________________________\n");
	
	for (i=0;i<indexTS;i++)
		printf ("\t\t %s \t\t  %d \t\t %d \t\t %d \n",TS[i].nom, TS[i].type,TS[i].nature,TS[i].size);			  
}

int typeIdf(char* el)
{ 
	return TS[recherche(el)].type;
}

int natureIdf(char* el){
	return TS[recherche(el)].nature;
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

void GenerationTS (char* entite, int type ,int nature,int size, float val)
{	int i;
	int trouve = 0;

	while (i<indexTS){
		if (strcmp(TS[i].nom,entite)==0) trouve = 1;
		i++;
	}
	if (trouve == 0) {
		inserer(entite,type,nature,size,val);
	} else{
		printf("entite existe deja\n");
	}
}