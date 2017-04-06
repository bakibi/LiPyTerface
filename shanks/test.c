
#include "includeTools.h"

int main(int argc,char **args)
{




    commande *cmd1 = new_commande("10.002");   
 
     
        printf("\n");

        printf("%f\n",calcule(cmd1->com));
    return 0;
}