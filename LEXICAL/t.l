%{
    //Déclaration C (pré-code)
    #include <stdio.h>
    #include <string.h>
    int ligne=1,col=1;
%}

%option noyywrap

chiffre [0-9]
lettre [a-zA-Z]
entier {chiffre}+|\([+-]?{chiffre}+\)                    
reel {chiffre}+(\.{chiffre})?|\([+-]?{chiffre}+\.{chiffre}+\)
idf  [A-Z][a-z]+|[a-z]*
space ("\t"|" ")+
saut "\n"+ 
commentaire "%%"[^"\n"]*"\n"?

%%
"VAR" {col+=yyleng; printf ("%s est un mot cle\n",yytext);}
"CODE" {col+=yyleng; printf ("%s est un mot cle\n",yytext);}
"INTEGER" {col+=yyleng; printf ("%s est un mot cle\n",yytext);}
"FLOAT" {col+=yyleng; printf ("%s est un mot cle\n",yytext);}
"CONST" {col+=yyleng; printf ("%s est un mot cle\n",yytext);}
"STRUCT" {col+=yyleng; printf ("%s est un mot cle\n",yytext);}
"IF" {col+=yyleng; printf ("%s est un mot cle\n",yytext);}
"ELSE" {col+=yyleng; printf ("%s est un mot cle\n",yytext);}
"FOR" {col+=yyleng; printf ("%s est un mot cle\n",yytext);}
"WHILE" {col+=yyleng; printf ("%s est un mot cle\n",yytext);}
{entier} {col+=yyleng; printf ("%s est un entier\n",yytext);}
{idf} {col+=yyleng; printf ("%s est un idf\n",yytext);}
{reel} {col+=yyleng; printf ("%s est un reel\n",yytext);}
"=" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
"(" {col+=yyleng; printf ("%s est un separateur\n",yytext);}
")" {col+=yyleng; printf ("%s est un separateur\n",yytext);}
"{" {col+=yyleng; printf ("%s est un separateur\n",yytext);}
"}" {col+=yyleng; printf ("%s est un separateur\n",yytext);}
"+" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
"-" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
"/" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
"*" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
";" {col+=yyleng; printf ("%s est un separateur\n",yytext);}
"&&" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
"||" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
"!" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
">" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
"<" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
">=" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
"<=" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
"==" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
"!=" {col+=yyleng; printf ("%s est un operateur\n",yytext);}
"," {col+=yyleng; printf ("%s est un separateur\n",yytext);}
{commentaire} {col+=yyleng; printf ("%s est un commantaire\n",yytext);}
{space} {col+=yyleng;}
{saut} {col=1; ligne+=yyleng;}
. {printf ("erreur lexicale entite %s ligne %d colonne %d \n",yytext,ligne,col);}
%%
//Code Additionnel (post-code C)
int main(){
    yyin=fopen("test.txt","r");
    yylex();    //permet de lancer l'analyseur lexical
    fclose(yyin); 
    return 0;
}