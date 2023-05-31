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

void inserer (char *el, char typ[],char natur[],int siz,char value[])
{
	TS[indexTS].nom=el;
	strcpy(TS[indexTS].type,typ);
	strcpy(TS[indexTS].nature,natur);
	TS[indexTS].size=siz;
	strcpy(TS[indexTS].val,value);
	indexTS ++;
}

void afficherTS ()
{
	int i=0; 
	printf("\n/***************Table des symboles *************/\n");
    printf("______________________________________________________________________________________________\n");
    printf("|\t Nom \t|\t Type \t|\t Nature \t|\t Taille  \t|\t Valeur  \t|\n");
    printf("______________________________________________________________________________________________\n");
	
	for (i=0;i<indexTS;i++)
		printf (" %12s \t  %12s \t\t %12s \t\t %12d \t\t %12s  \n",TS[i].nom, TS[i].type,TS[i].nature,TS[i].size,TS[i].val);			  
}


int typeIdf(char* el)
{ 
	if( strcmp(TS[recherche(el)].type,"INTEGER")==0 ) return 1; 
	else { if( strcmp(TS[recherche(el)].type,"FLOAT")==0 ) return 2;}
	return 0;
}

char* natureIdf(char* el){
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
/*
void SaveValue(char entite[], float val)
{
	int position;
	position =recherche (entite);
	if (position != -1) 
	{
		TS[position].val=val;
	}
}
*/