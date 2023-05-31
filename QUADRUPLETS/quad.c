#include <stdio.h>
#include <string.h>
#include "quad.h"

void quadr(char* opr,char* op1,char* op2,char* res)
{
    strcpy(quad[qc].oper , opr);
    strcpy(quad[qc].op1 , op1);
    strcpy(quad[qc].op2 , op2);
    strcpy(quad[qc].res , res);
    qc++;

int indq=0;
void quad (char* o,char*o1,char*o2,char*r)
{   
    q[indq].opr=o;
    q[indq].op1=o1;
    q[indq].op2=o2;
    q[indq].res=r;
    indq++;
}
}


void ajour_quad(int num_quad, int colon_quad, char val)
{
    if (colon_quad==0) strcpy(quad[num_quad].oper , val);
    else    if (colon_quad==1) strcpy(quad[num_quad].op1 , val);
            else    if (colon_quad==2) strcpy(quad[num_quad].op2 , val);
                    else if (colon_quad==3) strcpy(quad[num_quad].res , val);
}


void afficher_qdr()
{
    printf("*********************LesQuadruplets***********************\n");
    int i;
    for(i=0;i<qc;i++)
    {
        printf("\n %d - ( %s , %s , %s , %s )",i,quad[i].oper,quad[i].op1,quad[i].op2,quad[i].res);
        printf("\n---------------------------------------------------\n");
    }
}
*****************
void afficherQuad()
{ int i;
for (i=0;i<indq;i++)
{printf ("%d-( %s , %s , %s , %s )\n",i,q[i].opr,q[i].op1,q[i].op2,q[i].res);}
}