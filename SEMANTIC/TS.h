#ifndef TS_H
#define TS_H

#define taille 10000
//
typedef struct {
				char* nom;
				int type; //1: entier, 2: reel ,0: none
				int nature ; //0: variable , 1: constante,2: structure ,3:tableau
				int size ; // taille tab, sinon 0 
				float val; //valeur de idf ou constante 
				}elem;
				
elem TS[taille];

// fonction qui recherche un element chaine de caractere dans la table des symboles
int recherche (char*);
// fonction d'insertion d'un idf dans la table
void inserer (char*,int,int,int,float);
// fonction qui affiche la table des symboles
void afficherTS ();
// fonction qui retourne le type d'un IDF
int typeIdf(char*);
// fonction qui retourne le nature d'un IDF
int natureIdf(char*);
//fonction qui genere la TS
void GenerationTS (char*,int,int,int,float);

#endif //TS_H