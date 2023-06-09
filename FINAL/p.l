%{
    //Déclaration C (pré-code)
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "p.tab.h"
    extern YYSTYPE yylval;
    int ligne=1,col=1;
%}

%option noyywrap

chiffre [0-9]
lettre [a-zA-Z]
entier {chiffre}+|([\+\-]\({chiffre}+\))
reel {chiffre}+\.{chiffre}+|([\+\-]\({chiffre}+\.{chiffre}+\))
idf [A-Z]{lettre}* | {lettre}*
space ("\t"|" ")+
saut "\n"+ 

%%
"VAR" {col+=yyleng; yylval.nom = strdup(yytext); return(VAR);}
"CODE" {col+=yyleng; yylval.nom = strdup(yytext); return(CODE);}
"INTEGER" {col+=yyleng; yylval.nom = strdup(yytext); return(INTEGER);}
"FLOAT" {col+=yyleng; yylval.nom = strdup(yytext); return(FLOAT);}
"CONST" {col+=yyleng; yylval.nom = strdup(yytext); return(CONST);}
"STRUCT" {col+=yyleng; yylval.nom = strdup(yytext); return(STRUCT);}
"IF" {col+=yyleng; yylval.nom = strdup(yytext); return(IF);}
"ELSE" {col+=yyleng; yylval.nom = strdup(yytext); return(ELSE);}
"FOR" {col+=yyleng; yylval.nom = strdup(yytext); return(FOR);}
"WHILE" {col+=yyleng; yylval.nom = strdup(yytext); return(WHILE);}
{idf} {col+=yyleng; yylval.nom = strdup(yytext); return(IDF);}
{reel} {col+=yyleng; yylval.nom = strdup(yytext); return(REEL);}
{entier} {col+=yyleng; yylval.nom = strdup(yytext); }
"=" {col+=yyleng; return(AFF);}
"(" {col+=yyleng; return('(');}
")" {col+=yyleng; return(')');}
"{" {col+=yyleng; return('{');}
"}" {col+=yyleng; return('}');}
"+" {col+=yyleng; yylval.nom = strdup(yytext); return(ADD);}
"-" {col+=yyleng; yylval.nom = strdup(yytext); return(SUB);}
"/" {col+=yyleng; yylval.nom = strdup(yytext); return(DIV);}
"*" {col+=yyleng; yylval.nom = strdup(yytext); return(MUL);}
"&&" {col+=yyleng; yylval.nom = strdup(yytext); return(AND);}
"||" {col+=yyleng; yylval.nom = strdup(yytext); return(OR);}
"!" {col+=yyleng; yylval.nom = strdup(yytext); return(NOT);}
">" {col+=yyleng; yylval.nom = strdup(yytext); return(GREATER);}
"<" {col+=yyleng; yylval.nom = strdup(yytext); return(LESS);}
">=" {col+=yyleng; yylval.nom = strdup(yytext); return(GREATEREQUAL);}
"<=" {col+=yyleng; yylval.nom = strdup(yytext); return(LESSEQUAL);}
"==" {col+=yyleng; yylval.nom = strdup(yytext); return(EQUAL);}
"!=" {col+=yyleng; yylval.nom = strdup(yytext); return(NOTEQUAL);}
"," {col+=yyleng; yylval.nom = strdup(yytext); return',';}
";" {col+=yyleng; yylval.nom = strdup(yytext); return';';}
"%%" {col+=yyleng; yylval.nom = strdup(yytext); return(COMMENT);}
{space} {col+=yyleng;}
{saut} {col=1; ligne+=yyleng;}
. {printf("erreur lexicale entite %s ligne %d colnne %d \n",yytext,ligne,col);}
%%
//Code Additionnel (post-code C)
int main(){
    yyin=fopen("test.txt","r");
    yylex();    //permet de lancer l'analyseur lexical
    fclose(yyin); 
    return 0;
}

/*
//Appelée par l'analyseur lexical à la fin du fichier, 
// retourne 1 si la totalité des flux a été consommée et l'analyseur a fini sa tache, 0 sinon.
int yywrap(void)    
{
    return 0;
}
*/