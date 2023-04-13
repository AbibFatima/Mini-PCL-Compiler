#ifndef TS_H
#define TS_H

#define taille 10000
//
typedef struct {
				char* nom;
				int type; //1: entier, 2: reel ,0: none
				int nature ; // 0: variable , 1: constante,2: structure ,3:tableau
				}elem;
				
elem TS[taille];

// fonction qui recherche un element chaine de caractere dans la table des symboles
int recherche (char * );
// fonction d'insertion d'un idf dans la table
void inserer (char*,int,int );

// fonction qui affiche la table des symboles
void afficherTS ();
// fonction qui retourne le type d'un IDF
int typeIdf(char*);

#endif //TS_H