#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "QUAD.h"
#include "TS.h"
#include "optimisation.h"


void optimisation() 
{	
    multiplication_X2();
    variable_non_utilisee();
    Propagation_de_copie();	
  
	// Suppression des quadruplets vides
    int i=0;
    for(i=0;i<indq-1;i++)
    {
        if(strcmp(q[i].opr,"")==0)
        {
            int j = 0;
            for(j=i;j<indq-1;j++)
            {
                q[j].opr=strdup(q[j+1].opr);
                q[j].op1=strdup(q[j+1].op1);
                q[j].op2=strdup(q[j+1].op2);
                q[j].res=strdup(q[j+1].res);
            }
            indq--;
        }
    }
}

// Optimisation : multiplication par 2
void multiplication_X2()
{
    int i=0;
    for (i=0;i<indq;i++){
        if(q[i].opr[0]=='*'){
            if(q[i].op1[0]=='2'){
                q[i].opr=strdup("+");
                q[i].op1=strdup(q[i].op2);
            }else {
                if (q[i].op2[0]=='2'){
                    q[i].opr=strdup("+");
                    q[i].op2=strdup(q[i].op1);
                }
            }    
        }
    }
}

// Optimisation: variables non utilisee (afficher un warning)
void variable_non_utilisee()
{
    int use=0;
    int lengthTS = tailleTS(); 
    for(int l=0;l<lengthTS;l++){
        use=0;
        
        for(int k=0;k<indq;k++){
            if( strcmp(q[k].op1,TS[l].nom)== 0 || strcmp(q[k].op2,TS[l].nom)== 0 || strcmp(q[k].res,TS[l].nom)== 0){
                use = 1;
                break;
            }
        }
        if(use == 0){
            printf("Attention!!! : IDF ( %s ) declare et non utilise\n",TS[l].nom);
        } 
    }
}
       
// Optimisation : Propagation de copie
void Propagation_de_copie( )
{
    int i=0;
    for (i=0;i<indq;i++){
        if((q[i].opr[0]==':') || (q[i].opr[0]=='=')){
            int k=0;
            for(k=i+1;k<indq;k++){
                if(strcmp(q[i].op1,q[k].res)==0 || strcmp(q[i].res,q[k].res)==0)
                    break;
                if(q[k].opr[0]=='+' || q[k].opr[0]=='*' || q[k].opr[0]=='-' || q[k].opr[0]=='/'  ){
                    if(strcmp(q[i].res,q[k].op1)==0){
                        q[k].op1=strdup(q[i].op1);
                        q[i].opr=strdup("");
                        q[i].op1=strdup("");
                        q[i].op2=strdup("");
                        q[i].res=strdup("");
                    }else if(strcmp(q[i].res,q[k].op2)==0){
                        q[k].op2=strdup(q[i].op1);
                        q[i].opr=strdup("");
                        q[i].op1=strdup("");
                        q[i].op2=strdup("");
                        q[i].res=strdup("");
                    }
                }
            }
        }
    }
}