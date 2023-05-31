#ifndef TS_H
#define TS_H

#define taille 10000
//
typedef struct {
				char* nom;
				char type[20]; //1: entier, 2: reel ,0: none
				char nature[20]; //0: variable , 1: constante,2: structure ,3:tableau
				int size ; // taille tab, sinon 0 
				char val[20]; //valeur de idf ou constante 
				}elem;
				
elem TS[taille];
 

// fonction qui recherche un element chaine de caractere dans la table des symboles
int recherche (char*);
// fonction d'insertion d'un idf dans la table
void inserer (char*,char[],char[],int,char[]);
// fonction qui affiche la table des symboles
void afficherTS ();
// fonction qui retourne le type d'un IDF
int typeIdf(char*);
// fonction qui retourne le nature d'un IDF
char* natureIdf(char*);
//fonction qui sauvgarde la valeur
//void SaveValue(char*, float );

//fonction qui retourne la taille de la TS
int tailleTS();


#endif //TS_H