#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"quad.h"
#include "ts.c"


/*generation des quadruplets*/
void genere(char opr[],char op1[],char op2[],char res[]){
	strcpy(quad[qc].oper,opr);
	strcpy(quad[qc].op1,op1);
	strcpy(quad[qc].op2,op2);
	strcpy(quad[qc].res,res);
	qc++;
}

/*affichage des quadruplets*/
void afficherQuad()
{
    int i;
    for ( i = 0; i < qc; i++)
    {
        printf("%d-(%s ,%s ,%s ,%s )\n",i,quad[i].oper,quad[i].op1,quad[i].op2,quad[i].res);
    }
}



//convert interger to string
char* ToSTR(int i){
	char s[15];
	sprintf(s,"%d",i);
	return strdup(s);
}

//creation d'1 quad arithmeitque
void createQuadCompare(int type, char *cond1, char *cond2, char *res){
	char *TypeBR;
	switch(type){
		case 1 :{//1==> "!=" (different)
			TypeBR=strdup("BNE");
		}
		break;
		case 2 :{//2==> "==" (égale)
			TypeBR=strdup("BE");
		}
		break;
		case 3 :{//3==> "<" lower
			TypeBR=strdup("BL");
		}
		break;
		case 4 :{//4==> ">" higher 
			TypeBR=strdup("BG");
		}
		break;
		case 5 :{//5==>  ">=" higher Or Equal
			TypeBR=strdup("BGE");
		}
		break;
		case 6 :{//6==> "<=" lower Or Equal 
			TypeBR=strdup("BLE");
		}
		break;
	}
	quad(TypeBR,ToSTR(indq+3),cond1,cond2);
	quad("=","1","",res);
	quad("BR",ToSTR(indq+2),"","");
	quad("=","0","",res);
}

//creation d'1 quad logique
void createQuadLogic(int type, char *cond1, char *cond2, char *res){
	switch(type){
		case 1 :{//1==> not
			quad("BNZ",ToSTR(indq+3),cond1,"");
			quad("=","1","",res);
			quad("BR",ToSTR(indq+2),"","");
			quad("=","0","",res);
		}
		break;
		case 2 :{//2==> or
			quad("BNZ",ToSTR(indq+4),cond1,"");
			quad("BNZ",ToSTR(indq+3),cond2,"");
			quad("=","0","",res);
			quad("BR",ToSTR(indq+2),"","");
			quad("=","1","",res);
		}
		break;
		case 3 :{//3==> and
			quad("BZ",ToSTR(indq+4),cond1,"");
			quad("BZ",ToSTR(indq+3),cond2,"");
			quad("=","1","",res);
			quad("BR",ToSTR(indq+2),"","");
			quad("=","0","",res);
		}
		break;
	}
}  


/*mise a jour des quadruplets*/
void majbr(int saveqc,int qcCourant){
	char b[20];
	
	sprintf(b,"%d",qcCourant);
	strcpy(quad[saveqc].op1,b);
}

/*gerer les num des temporaires (incrementation) */
void cr(char s[3]){
	sprintf(s,"T%d",inid);
	inid = inid + 1;
}


