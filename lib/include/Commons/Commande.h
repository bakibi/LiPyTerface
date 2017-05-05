

//      La structure de donnees Commande

typedef struct Commande
{
    char *commande;  // La Commande
    char *warnings;     //  Les Warnings rencotrer apres compilation
    char *errors;           //  Les erreurs rencontrer apres compilation
    char *output;           //  Le output est le resultat de la commande si elle est sans faute
    int etat;                   //  L'etat de la commande
    int outstat;                //  Letat de sortir // veut dire que si la commande est complete ou pas 
}Commande;



//      LEs prototypes 
Commande *new_Commande(const char *chaine);
Commande *Commande_interpreter(Commande *cmd,int *test,Finale *f);

//      Les implementations



//      Creation d une nouvelle commande
Commande *new_Commande(const char *chaine)
{
    Commande *cmd  = (Commande *)malloc(sizeof(Commande));
    if(!cmd) return NULL;
    cmd->commande = (char *)malloc(strlen(chaine)); strcpy(cmd->commande,chaine);
     cmd->output = (char *)malloc(sizeof(char)*5000);
    cmd->errors= (char *)malloc(sizeof(char)*5000);
    cmd->warnings = (char *)malloc(sizeof(char)*5000);
    strcpy(cmd->errors,"");strcpy(cmd->output,"");strcpy(cmd->warnings,"");
    cmd->etat = cmd->outstat = 0;
    return cmd;
}//eof









//      interpreter une commande
Commande *Commande_interpreter(Commande *cmd,int *test,Finale *f)
{   
    if(cmd == NULL) return NULL;


     Lexemes *liste = al(cmd->commande);//analyse lexicale
      printf("-------------Analyse Lexicale\n");
     Lexemes_toString(liste);


   printf("-------------Analyse Syntaxique\n");
   Grammaires *listeS = as(liste,cmd->errors);//analyse syntaxique 1
                                     as1(listeS,cmd->errors);// analyse syntaxique finale
   Grammaires_toString(listeS);
  
   
    printf("-------------Analyse Semantique\n");
    if(strcmp(cmd->errors,"") == 0 ) listeS = ase(listeS,cmd->errors,cmd->warnings,cmd->output,f);//si il y a des erreur syntaxique
 
    printf("\n-------------OUTPUT\n");
if(strcmp(cmd->errors,"") == 0 ) 
{
    printf("%s\n",cmd->output);
    *test = 1;
}
    printf("\n--------------Errors\n");
    printf("%s\n",cmd->errors);

    printf("\n--------------Warnings\n");
    printf("%s\n",cmd->warnings);
    return cmd;
}




