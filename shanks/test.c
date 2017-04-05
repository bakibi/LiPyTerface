
#include "includeTools.h"

int main(int argc,char **args)
{

    char mot[] = "-0x13+x12";

    int i = 0;
   
   //     printf("%f\n",calcule(mot));
        Arbre *a = new_Arbre();
        a = Arbre_add(a,2,10,0);
        a = Arbre_add(a,1,0,'+');
        a = Arbre_add(a,2,10,0);
        a = Arbre_add(a,1,0,'%');
        a = Arbre_add(a,2,30,0);

        Arbre_toString(a);
        printf("\n");

        printf("%f\n",Arbre_evaluer(a));
    return 0;
}