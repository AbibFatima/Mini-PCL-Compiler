# PROJECT : HOW TO MAKE A MINI-PCL-COMPILER
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
### The Third part :  
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


1. Before writting the script of the syntactic analysis, 
we have to make changes in the first file that we created (.l)

<hr>

**THE CHANGES ARE :**
1. Remove the main function and move it to the .y file after we checked that it works correctly.
2. We don't have to print all the entities with ``printf("%s est un mot cle\n",yytext);``, so we going to remove them all and replace them with

``yylval.nom = strdup(yytext); return (INTEGER);`` : duplicated the yytext to the external variable yylval.nom 
which will send the reconised lexical entitie to the syntactic analyzer within the ``yylval`` variable defined by BISON, but to use it we have to add two lines in the pre-code part

    #include<string.h>;     // needed for the strdup() function 
    #include "tp.tab.h"     // file generated from bison it l'entete du fichier tp.tab.c qui est le code c de l'analyseur syntaxique.
    extern YYSTYPE yylval;  // pre defined var, par défaut entier but will change that to a structure in the .y file


and it returns the name of the lexical entite that we're going to use to  write the grammar.

[mettre file here s.l](SYNTACTIC\s.l)
<hr>

2. We are going to create a new file with the extension .y which it will hold the syntaxic analysis, with the same format as the .l file, means that is a script with 3 parts devided with '%%'
    - First part contains pre-code C 
    - Second part : we will define the lexical entites 
    - Third part will hold the grammar 
    - and the last one we hold the main function (the one that were in .l file)


### The first part :

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    
    // signature de fonction
    int yylex();       
    int yyerror(char *);

    //extern variables
    extern FILE* yyin;
    extern int ligne, col;

### The second part :

This part contains all the lexical entites that we returned from .l file8 means that belongs to the language, set with the word ``%token`` 
    
    %token IDF AFF ENTIER REEL ';' INTEGER FLOAT '(' ')' '*' '+' '-' '/'

### The third part :

C'est toutes les regles de production d'une grammaire LALR (ascendante) + code qui sera executé lors de la réduction avec cette régle .  

Exemples : 

    s: declar inst;
    declar: INTEGER  IDF ';' declar {printf ("reduction declar integer\n");}
	    | FLOAT IDF ';' declar {printf ("reduction declar float\n");}
	    |
	    ;

### The fourth part :

    //We have to define the yyerror which is called when the analyzer finds an error
    int yyerror(char* msg){
        printf(" %s ligne %d \n",msg, ligne, col);      //msg = syntaxe error
        exit(0);
        return 1;
    }

    int main(){
        yyin = fopen("in.txt","r");
        yyparse();          //Different that the one we used in the .l file, this is the function used in the syntactic analyzer et imlicitement il va appelé yylex() de l'analyseur lexicale
        fclode(yyin);
    }

3. Add another command in the _makefile.bat_ and it will contain : 

    flex tp.l \
    bison -d tp.y \
    gcc lex.yy.c tp.tab.c -o tp.exe 


[See Script here : s.l](SYNTACTIC\s.l)

[See Script here : s.y](SYNTACTIC\s.y)

[See __ here : makefile.bat ](SYNTACTIC\makefile.bat)

#### video = 41min


> REMARQUE : \
On redéfinit la variable yylval dans le fichier .y avec l'instruction ``%union {char nom*;}``

<pre>
<code>%left ADD SUB   //veut dire que l'addition et la substration  sont plus
%let MUL DIV    //prioritaire que la multiplication et la division</code>
</pre>

### Step 3 : Table des Symboles

Pour la réalisation de la table des symboles qui englobe l'ensemble des entités lexicales du code analysé (mais concretement, elle englobera les idfs rencontré seulement) on deuvra rajouter deux fichiers : 
    - TS.h : on va definir un tableau pour les idfs (elle peut etre sous forme d'une liste chainée ou une table de hachage aussi) qui est un tableau d'elements (nom et type)
    et aussi on définit les signatures des fonctions prémitives 
    de ce point, on ajoutera le fichier TS.x
<pre>
<code>#define TS_H
    
#define taille 10000

typedef struct{
        char* nom;
        int type;
}elem;

//fonction qui recherche un element chaine de caractere dans table des symboles
int recherche(char *);

//fonction d'insertion d'un idf dans la table
void inserer(char *, int);

//fonction qui affiche la table des symboles
void affichierTS();

//fonction qui retourne le type d'un IDF
int typeidf(char *);

#endif //TS_H
</code></pre>
    - TS.c : 