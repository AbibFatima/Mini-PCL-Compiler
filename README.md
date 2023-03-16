# Mini-PCL-Compiler : HOW TO MAKE A MINI COMPILER
Making a mini PCL compiler using flex/bison


Steps to make a mini PCL Compiler :


> Note : First of all we're going to work with flex and bison so they have to be aleady installed 


##  Step 1 : LEXICAL ANALYSIS ( Analyse lexicale ) 

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
Some exemples to see how regular expressions are written to help define lexical entities : 

<pre>
<code>chiffre [0-9]                       //Définition chiffre : qui sont les caracteres compris entre le caractere 0 et 9 dans la table ascii
lettre [a-zA-z]                     //Définition lettre : les lettres compris entre 'a' et 'z' plus aussi entre 'A' et 'Z'
entier {chiffre}+"."{chiffre}*       
idf {lettre}+
space ("\t"|" ")+                   //l'espace + tabulation  
saut "\n"+                          //saut de ligne</code>
</pre>

____
**REMARQUE :** 

On définit l'espace et le saut de ligne pour faire le compte de la ligne et la colonne de l'erreur lexicale lorsqu'on la rencontre. 
Pour cela il faut compter le nombre de saut de ligne pour retrouver la ligne de l'erreur, et le nombre d'espace pour incrémenter le compteur du numéro de colonne.
___
### The Thirs part :  
C'est dans cette que l'enumeration de toutes les entités lexicales qui appartienent au langage est faite et la définition des actions générer lors de la rencontre de chaque entité.

Le processus :
- D'abord, il va lire l'entité lexicale depuis le fichier.txt qui va l'ouvrir dans le Main (PARTIE 4) 
- et va la mettre dans la variable yytext aprés il rentre dans un énorme switch case car il va tester chaque entité, 
    - si c'est la bonne il va realisé la portion de code correspondante 
    - sinon il va afficher l'erreur lexicale.



Exemples : 
==========
**CASE 1 :** Chaine de caracteres

<pre><code>"INT" {colo+=yyleng; printf("%s est un mot cle\n",yytext);}</code>
</pre>

- colo : is an int variable to count the number of colonne to catch the error that we declared
- yyleng : int variable that saves the length of the read word, declared by FLEX.
- yytext : char variable that containes the read word, declared by FLEX.

**CASE 2 :** Expression reguliere qui à été définit dans la 2eme partie du script

<pre>
<code>{idf} {colo+=yyleng; printf("%s est un identificateur \n",yytext);}</code>
</pre>

**CASE 3 :** Les opérateurs et séparateurs

<pre>
<code>"=" {colo+=yyleng; printf("%s est un operateur \n",yytext);}
";" {colo+=yyleng; printf("%s est un separateur \n",yytext);}</code>
</pre>

**CASE 4 :** 
Mis toujours à la fin, qui veut dire autres caracteres qui n'est pas définit en haut

<pre>
<code>. {printf("erreur lexicale entite %s ligne %d colonne %d\n",yytext,ligne,colo);}</code>
</pre>


### The Fourth part :  
Used just in the making of the lexical analyzer and then moved to the _.y_ file after and contains a main function written in C language 

<pre>
<code>int main(){
    yyin = fopen("in.txt","r");         //Ouvrir le fichier in.txt en mode read et renvoie un pointeur de type file*, qu'on mets dans la variable yyin (définit par flex de type file*)
    yylex();                            //Appellé l'analyseur lexicale, fonction qui est généré par flex
    fclose(yyin);                       //Fermer le fichier pointé par la variable yyin
    return 0;
}</code>
</pre>

2. We create a _.bat_ file containing all the used compilations instructions to not rewrite them everytime. 

_makefile.bat_ contains : 
* ``flex p.l`` : generates a file _lex.yy.c_ that needs to be compiled with the next command to generate the .exe file.

* ``gcc lex.yy.c -o p.exe``  

The commands are :

    1) open cmd 
    2) .\makefile.bat 
    3) .\p.exe

___
**REMARQUE :** 

We may uncounter the error : ``undifined reference to 'yywrap'``

yywrap : used when we need to compile multiple files at the same time, but in our case we are using just one. Then we have to add an option to say that we don't need it. 

That way we're going to add the line ``%option noyywrap`` in the 2nd part just before regular expressions.
___

[See Script here : t.l](LEXICAL\t.l)

[See __ here : makefile.bat ](LEXICAL\makefile.bat)


## Step 2 : Syntactic Analysis ( Analyse syntaxique )  

1. We're going to create another file that we talked about eatlier which is _.y_ , it will hold the syntaxic analysis . 
separated like the _.l_ file with the same parts but contains different

2. Making some changes on the _.l_ 

After that we are sure that lexical analysis is correct we remove the 4th part to copy it in this new file at the same part.
And we also have to remove all the printf s because we do not need that anymore, and we gonna add 

#### First part : 
<pre>
<code>#include <string.h>;                   //
#include "s.tab.h";          //
extern YYSTYPE yylval;       // </code>
</pre>

#### Third part : 
<pre>
<code>"INT" {colo+=yyleng; printf("%s est un mot cle\n",yytext);} ----> "INT" {colo+=yyleng; yyval.nom=strdup(yytext); return(INTEGER);}</code>
</pre>

3. Adding another command to the _makefile.bat_, then it becomes : 

    flex s.l \
    bison -d s.y  \
    gcc lex.yy.c s.tab.c -o s.exe


##### video : 25min 
