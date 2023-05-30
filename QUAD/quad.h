typedef struct qdr{
    char oper[100]; 
    char op1[100];   
    char op2[100];   
    char res[100];  
}qdr;

  qdr quad[1000];
  int qc=0;
  int saveqc = -1;
  int inid = 0;

// Fonction qui genere des quadruplets
void genere(char opr[],char op1[],char op2[],char res[]);

// Fonction mise a jour des quadruplets
void majbr(int saveqc,int qcCourant);

// Fonction qui gere les num des temporaires
void cr(char s[3]);

// Fonction qui affiche les quadruplets 
void afficherquad();