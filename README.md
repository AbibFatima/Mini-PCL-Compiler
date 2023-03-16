# Mini-PCL-Compiler : HOW TO MAKE A MINI COMPILER
Making a mini PCL compiler using flex/bison


Steps to make a mini PCL Compiler :

> Note : First of all we're going to work with flex and bison so they have to be aleady installed 


## Step 1 : LEXICAL ANALYSIS ( Analyse lexicale ) 

Elle consiste à :
- Déterminer toutes les entités &emsp; &emsp; &emsp;  **we are going to focus on this part first**
- Construire la table des symboles &emsp; &emsp;       **this one will be treated later on**

Les entités représentent les mots clés, les identificateurs, les constantes, espaces...


1. We create a .l file that is separated in 3 parts with ``%%`` : 
   * First part (pre-code C): (in ``%{ %}``) holds all C libraries used in this script, 
   * Second part  : les définitions des expressions réguliéres (definitions of regular expressions),
   * Third part : les régles de traductions,
   * Fourth part (additional, used only in this Analysis to check if the script works correctly. We'll change its emplacement after to the .y file) : contains the MAIN function.

 
### The First part : Pre-Code C
the libraries used are 

<code> #include <stdio.h> </code> : used when calling the function printf

<code> #include <stdlib.h> </code> : used when calling the functions fopen and fclose in MAIN

### The Second part :  Regular Expressions
Some exemples to see how "les expressions réguliéres" are written to help define "les entités lexicales" : 

<pre>
<code>
chiffre [0-9]                      //Définition chiffre : qui sont les caracteres compris entre le caractere 0 et 9 dans la table ascii
lettre [a-zA-z]                     //Définition lettre : les lettres compris entre 'a' et 'z' plus aussi entre 'A' et 'Z'
entier {chiffre}+"."{chiffre}*       
idf {lettre}+
space ("\t"|" ")+                   //l'espace + tabulation  
saut "\n"+                          //saut de ligne
</code>
</pre>

**Remarque :** 
On définit l'espace et le saut de ligne pour faire le compte de la ligne et la colonne de l'erreur lexicale lorsqu'on la rencontre.
Pour cela il faut compter le nombre de saut de ligne pour retrouver la ligne de l'erreur, et le nombre d'espace pour incrémenter le compteur du numéro de colonne.

the 3rd part :  C'est ici qu'on enumere toutes les entités lexicales qui appartienent au langage 
                et définir l'action générer lors de la rencontre de chaque entité.

Le processus :
D'abord, il va lire l'entité lexicale depuis le fichier.txt qui va l'ouvrir dans le Main (PARTIE 4) 
et va la mettre dans la variable yytext aprés il rentre dans un énorme switch case car il va tester chaque entité, 
si c'est la bonne il va realisé la portion de code correspondante 
sinon il va afficher l'erreur lexicale.


Exemples : 
CASE 1: chaine de caracteres
"INT" {colo+=yyleng; printf("%s est un mot cle\n",yytext);}

colo : is an int variable to count the number of colonne to catch the error that we declared
yyleng : int variable that saves the length of the read word, declared by FLEX
yytext : char variable that containes the read word, declared by FLEX

CASE 2: expression reguliere qui à été définit dans la 2eme partie du script
{idf} {colo+=yyleng; printf("%s est un identificateur \n",yytext);}

CASE 3: les opérateurs et séparateurs
"=" {colo+=yyleng; printf("%s est un operateur \n",yytext);}
";" {colo+=yyleng; printf("%s est un separateur \n",yytext);}


CASE 4: mis toujours à la fin, qui veut dire autres caracteres qui n'est pas définit en haut
. {printf("erreur lexicale entite %s ligne %d colonne %d\n",yytext,ligne,colo);}


the 4th part :  used just in the realisation of the "l'analyseur lexicale" and then moved to the .y file after 
                and contains a main function written in C language 

int main(){
    yyin = fopen("in.txt","r");         //Ouvrir le fichier in.txt en mode read et renvoie un pointeur de type file*, qu'on mets dans la variable yyin (définit par flex de type file*)
    yylex();                            //Appellé l'analyseur lexicale, fonction qui est généré par flex
    fclose(yyin);                       //Fermer le fichier pointé par la variable yyin
    return 0;
}

2. we create a .bat file containing all the used compilations instructions to not rewrite them everytime. 

the makefile.bat contains : 
flex p.l            //generates a file lex.yy.c that needs to be compiled with the next command to generate the .exe file
gcc lex.yy.c -o p.exe  

The commands are : 
    1) open cmd 
    2) .\makefile.bat 
    3) .\p.exe

REMARQUE :
We may uncounter the error : undifined reference to 'yywrap'
yywrap : used when we need to compile multiple files at the same time 
but in our case we are using just one so we need to add an option to say that we don't need it. That way we're going to add the line "%option noyywrap" in the 2nd part just before "les expressions réguliéres".

p.l : (mettre fichier .l ici)

makefile.bat : (mettre fichier .bat ici)


/******************************************/
Step 2 : Analyse syntaxique    

1. we're going to create another file that we talked about eatlier which is .y, it will hold the syntaxic analysis . 
separated like the .l file with the same parts but contains different

2. Making some changes on the .l 
After that we are sure that lexical analysis is correct we remove the 4th part to copy it in this new file at the same part.
And we also have to remove all the printf s because we do not need that anymore, and we gonna add 

1st part : 
#include <string.h>; : 
#include "p.tab.h";  :
extern YYSTYPE yylval; :


"INT" {colo+=yyleng; printf("%s est un mot cle\n",yytext);} ----> "INT" {colo+=yyleng; yyval.nom=strdup(yytext); return(INTEGER);}


3. Adding another command to the makefile.bat, then it becomes : 

makefile.bat :
flex p.l
bison -d p.y
gcc lex.yy.c p.tab.c -o p.exe


##### video : 25min 
