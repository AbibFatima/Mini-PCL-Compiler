#ifndef QUAD_H
#define QUAD_H

// la taille de la table des quadruplets
#define t 200

//la structure d'un element de la table 
typedef struct 
{
    char* opr;
    char* op1;
    char* op2;
    char* res;
}quadruplet;

// pile liste variable 
typedef struct element_pile{
	char *donnee;
	struct element_pile *prc;
}pile;
pile *sauv_var;

// pile update  qc position 
typedef struct element_pile_Qc{
	int donnee;
	struct element_pile_Qc *prc;
}pileQc;

pileQc *pileIF;
pileQc *pileWHILE;
pileQc *pileFOR;

//declaration de la table 
quadruplet q[t];

//____signature des fonctions de qud.c

//fonction d'insertion d'un nouveau quad
void quad(char*,char*,char*,char*);
//fonction qui affiche les quads
void afficherQuad();
//fonction qui creer un quadruplet de comparaison
void createQuadCompare(int type, char *cond1, char *cond2, char *res);
//fonction qui creer un  quadruplet logique
void createQuadLogic(int type, char *cond1, char *cond2, char *res);
//fonction qui convertie un entier en chaîne de caractères
char* ToSTR(int i);
//fonction qui empile les indices des boucles (IF, WHILE, FOR)
void empiler_qc(pileQc **p, int pos);
//fonction qui depile les indices des boucles (IF, WHILE, FOR)
int depiler_qc(pileQc **p);

// Empiler une chaîne de caractères dans la pile
void empiler_Str(pile **p,char *donne);
//depiler un caractere
char* depiler(pile**p);


#endif //QUAD_H

