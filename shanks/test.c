#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "progtools/lexical/registre.h"
#include "progtools/lexical/numbers.h"
#include "commons/commande.h"
int main(int argc,char **args)
{

    char mot[] = "-0x13+x12";

    int i = 0;
   
        printf("%f\n",calcule(mot));
        
    return 0;
}