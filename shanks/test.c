
#include "includeTools.h"

int main(int argc,char **args)
{




    commande *cmd1 = new_commande("string");   
 
     
        printf("\n");
        printf("%d\n",is_keyWord(cmd1->com));
        lexical_compile(cmd1->com);
    return 0;
}