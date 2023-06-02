#ifndef TS_H
#define TS_H

#define taille 10000

typedef struct 
{
	char nom[20];
	char type[20]; 		//1: entier, 2: reel ,0: none
	char nature[20]; 	//0: variable , 1: constante,2: structure ,3:tableau
	int size ; 			// taille tab, sinon 0 
	char val[20]; 		//valeur de idf ou constante 
} elem;
				
elem TS[taille];
 

// fonction qui recherche un element chaine de caractere dans la table des symboles
int recherche(char []);
// fonction d'insertion d'un idf dans la table
void inserer(char [], char[], char[], int, char[]);
// fonction d'insertion d'un idf/constante dans la table des symboles
void recherche2(char [], char[], char[]);
// fonction qui insert la nature dans la table des symboles
void inserer_nature(char [], char[]);
// fonction qui insert la type dans la table des symboles
void inserer_type(char [], char[]);
// fonction qui insert la valeur dans la table des symboles
void inserer_valeur(char [], char[]);
// fonction qui insert la size dans la table des symboles
void inserer_size(char [], int);
// fonction qui affiche la table des symboles
void afficherTS();
// fonction qui retourne le type d'un IDF
int typeIdf(char []);
// fonction qui retourne le nature d'un IDF
char* natureIdf(char []);
//fonction qui retourne la taille de la TS
int tailleTS();

//fonction qui sauvgarde la valeur
//void SaveValue(char*, float );




#endif //TS_H