#ifndef RS_H
#define RS_H

char* tab_expression[100];

//routine semantique de la double declaration d'un idf
int doubleDec (char*);

//routine semantique de la non declaration d'un idf
void dec (char * );

//Routine semantique de la division par zero
//void divZero(int);

//Routine semantique de l'incompatibilité de type

//Routine semantique de modification de constante
void modifConstante(char *);

//routine semantique de la non declaration de tableau
void decTab (char* el);

// routine semantique de la non declaration d'une structure
int decStruct(char *el);


#endif// RS_H