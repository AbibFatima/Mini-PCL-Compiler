#ifndef QUAD_H
#define QUAD_H

extern int qc;

typedef struct
{
    char oper[100];
    char op1[100];
    char op2[100];
    char res[100];
}qdr;

qdr quad[1000];



//
void quadr(char,char,char,char);
//
void ajour_quad(int, int, char);
//
void afficher_qdr();

#endif //QUAD_H