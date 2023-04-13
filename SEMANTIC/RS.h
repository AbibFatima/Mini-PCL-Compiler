#ifndef RS_H
#define RS_H

char* tab_expression[100];

//routine semantique de la double declaration d'un idf
void doubleDec (char* );

//routine semantique de la non declaration d'un idf
void dec (char * );

//Routine semantique de la division par zero
void divZero(int);

//Routine semantique de l'incompatibilité de type
void incompType(char *, char*);

//Routine semantique de modification de constante
void modifConstante(char *);

#endif// RS_H