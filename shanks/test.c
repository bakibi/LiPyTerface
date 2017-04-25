
#include "includeTools.h"

int main(int argc,char **args)
{




    commande *cmd1 = new_commande("5+5*5-10");   
 
     
        printf("\n");
        printf("%f\n",calcule(cmd1->com));
        lexical_compile(cmd1->com);
    return 0;
}