#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexical/registre.h"
#include "lexical/numbers.h"
#include "lexical/commande.h"
int main(int argc,char **args)
{

    char mot[] = "-0x13+x12";

    int i = 0;
   
        printf("%f\n",calcule(mot));
        
    return 0;
}