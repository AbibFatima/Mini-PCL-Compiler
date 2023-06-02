%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "s.tab.h"
    #include "TS.h"
    #include "TS.c"
    extern YYSTYPE yylval;
    int ligne=1,col=1;
    char t [20] , val[20];
    int i;		 int j = 0;
%}

%option noyywrap

lettre [A-Za-z]
maj [A-Z]
min [a-z]
chiffrez [0-9] 
chiffre [1-9]

entier  ({chiffre}{chiffrez}*|0)|(\(("-"|"+")?{chiffre}{chiffrez}*\))                    
reel  ({chiffrez}+\.{chiffrez}+)|(\(("-"|"+")?{chiffrez}+\.{chiffrez}+\))
idf  {lettre}({min}|{chiffrez})*

space ("\t"|" ")+
saut "\n"+ 
commentaire "%%"[^"\n"]*"\n"?

%%
"VAR"       {col+=yyleng; yylval.nom = strdup(yytext); return(VAR);}
"CODE"      {col+=yyleng; yylval.nom = strdup(yytext); return(CODE);}

"INTEGER"   {col+=yyleng; yylval.nom = strdup(yytext); return(INTEGER);}
"FLOAT"     {col+=yyleng; yylval.nom = strdup(yytext); return(FLOAT);}

"CONST"     {col+=yyleng; yylval.nom = strdup(yytext); return(CONST);}
"STRUCT"    {col+=yyleng; yylval.nom = strdup(yytext); return(STRUCT);}

"IF"        {col+=yyleng; yylval.nom = strdup(yytext); return(IF);}
"ELSE"      {col+=yyleng; yylval.nom = strdup(yytext); return(ELSE);}
"FOR"       {col+=yyleng; yylval.nom = strdup(yytext); return(FOR);}
"WHILE"     {col+=yyleng; yylval.nom = strdup(yytext); return(WHILE);}

"="     {col+=yyleng; yylval.nom = strdup(yytext); return(AFF);}

"("     {col+=yyleng; yylval.nom = strdup(yytext); return('(');}
")"     {col+=yyleng; yylval.nom = strdup(yytext); return(')');}
"{"     {col+=yyleng; yylval.nom = strdup(yytext); return('{');}
"}"     {col+=yyleng; yylval.nom = strdup(yytext); return('}');}
"["     {col+=yyleng; yylval.nom = strdup(yytext); return('[');}
"]"     {col+=yyleng; yylval.nom = strdup(yytext); return(']');}

"+"     {col+=yyleng; yylval.nom = strdup(yytext); return(ADD);}
"-"     {col+=yyleng; yylval.nom = strdup(yytext); return(SUB);}
"/"     {col+=yyleng; yylval.nom = strdup(yytext); return(DIV);}
"*"     {col+=yyleng; yylval.nom = strdup(yytext); return(MUL);}

"&&"    {col+=yyleng; yylval.nom = strdup(yytext); return(AND);}
"||"    {col+=yyleng; yylval.nom = strdup(yytext); return(OR);}
"!"     {col+=yyleng; yylval.nom = strdup(yytext); return(NOT);}

">"     {col+=yyleng; yylval.nom = strdup(yytext); return(GREATER);}
"<"     {col+=yyleng; yylval.nom = strdup(yytext); return(LESS);}
">="    {col+=yyleng; yylval.nom = strdup(yytext); return(GREATEREQUAL);}
"<="    {col+=yyleng; yylval.nom = strdup(yytext); return(LESSEQUAL);}
"=="    {col+=yyleng; yylval.nom = strdup(yytext); return(EQUAL);}
"!="    {col+=yyleng; yylval.nom = strdup(yytext); return(NOTEQUAL);}

","     {col+=yyleng; yylval.nom = strdup(yytext); return',';}
";"     {col+=yyleng; yylval.nom = strdup(yytext); return';';}
":"     {col+=yyleng; yylval.nom = strdup(yytext); return':';}
"."     {col+=yyleng; yylval.nom = strdup(yytext); return'.';}

{idf}   {   
            if(yyleng<=8){
                col+=yyleng;;
                recherche2(yytext," "," "); 
                yylval.nom = strdup(yytext); 
                return(IDF);
            } else {
                col+=yyleng;
                printf("Erreur Lexicale : Identificateur %s trop long\n",yytext);
            }
        }

{reel}  {
            col+=yyleng;
            strcpy(val ,yytext);
            //recherche2(val,"FLOAT",yytext);
		    if ( val[0] =='(' ) {
                if ( val[1] =='-' ){ 
                    for (i=2 ; i<strlen(val)-1 ; i++) {	t[j] = val[i] ;	j++; }
				    strcpy(val ,t);
				    yylval.reel = -1*atof(val);
                }
			    else { 
                    if ( val[1] =='+' ){   
                        for (i=2 ; i<strlen(val)-1 ; i++) {	t[j] = val[i] ;	j++; }
                        strcpy(val ,t);
                        yylval.reel =atof(val);
                    }            
                }
            } else yylval.reel =atof(val);
            return(REEL);
        }

{entier}    {
                if(atoi(yytext)<=32767 && atoi(yytext)>=-32768){   
                    sprintf(val,"%d",atoi(yytext));
                    //recherche2(val,"INTEGER",yytext);
                    col+=yyleng;
                    strcpy(val ,yytext);
		          	if ( val[0] =='(' ) {   	
                        if ( val[1] =='-' ) { 
                            for (i=2 ; i<strlen(val)-1 ; i++) {	t[j] = val[i] ;	j++; }
				            strcpy(val ,t);
				            yylval.ent =-1 *atoi(val);
                        } else { 
                            if ( val[1] =='+' ){
                                for (i=2 ; i<strlen(val)-1 ; i++) {	t[j] = val[i] ;	j++; }
							    strcpy(val ,t);
							    yylval.ent =atoi(val);
					     	}
                        }
                    } else yylval.ent =atoi(val); 	 	
                    return(ENTIER);
                } else {
                    col+=yyleng;
                    printf("Erreur Lexicale ligne %d colonne %d : Depacement de capacite\n",ligne,col);
                }
            }
{commentaire} {col+=yyleng; yylval.nom = strdup(yytext); return(COMMENT);}
{space}     {col+=yyleng;}
{saut}      {col=1; ligne+=yyleng;}

.           {printf("erreur lexicale entite %s ligne %d colonne %d \n",yytext,ligne,col);}
%%
