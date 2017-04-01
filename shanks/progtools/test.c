#include <stdio.h>
#include <stdlib.h>
#include "lexical/registre.h"
#include "lexical/numbers.h"
int main(int argc,char **args)
{
    char mot[] = "0.15+-156";

    int i = 0;
    for ( i = 0; i < 9; i++)
        printf("%d\n",est_virgule(&mot[i]));
    return 0;
}