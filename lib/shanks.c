#include "include/include.h"

int main(int argc,char *argv[])
{
     char *commande = readFromFile(commande,argv[1]);
     int test  = 0;
     Finale *f = NULL;
   Space *s = new_Space("space1");
   Commande *cmd = Space_compile(s,commande);

   

    return 0;
}