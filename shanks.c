#include "include/include.h"

int main(int argc,char *argv[])
{
     char *commande = readFromFile(commande,argv[1]);
     
   
   Commande *cmd = new_Commande(commande);
    cmd = Commande_interpreter(cmd);
   

    return 0;
}