

//    la structure de donnée de commande
typedef struct commande 
{
    char *com;              //La commande
    char *errors;           // Liste des Erreurs
    char *result;           // le resultat
    char *warns;        //Si il y a des probleme mais c est compile alors ici on stock c est problemes
}commande;




//      Cette fonction initialise une commande par un str et retourne une SD commande
commande *new_commande(char *str)
{
    commande *cmd = (commande *)malloc(sizeof(commande));
    if(cmd == NULL)
    {
        printf("probeme de memoire !");
        exit(-1);
    }
    cmd->com = (char *)malloc(sizeof(str));
    if (strcpy(cmd->com,str) == NULL)
    {
        printf("probeme de memoire !");
        exit(-1);
    }
    cmd->errors = NULL;
    cmd->result = NULL;
    cmd->warns = NULL;
    return cmd;
}//end of the function