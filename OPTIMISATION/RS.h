#ifndef RS_H
#define RS_H


//routine semantique de la double declaration d'un idf
int doubleDec (char*);
//routine semantique de la non declaration d'un idf
void dec (char[]);

//Routine semantique de la division par zero

//Routine semantique de l'incompatibilité de type

//Routine semantique de depassement de la taille du tableau

//Routine semantique de modification de constante
void modifConstante(char *);

//routine semantique de la non declaration de tableau
void decTab (char* el);

// routine semantique de la non declaration d'une structure
int decStruct(char *el);


#endif// RS_H