#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//          Cellule struct
typedef struct Cellule{
    float value;
    struct Cellule *svt;
}Cellule; 

//          Liste struct 
typedef struct Cellule Liste;
//          Pile struct
typedef struct Cellule Pile;
//          File struct 
typedef struct File {
Cellule *debut;
Cellule *fin;
}File;
//          Arbre struct
typedef struct Arbre 
{
    float v;
    char op;
    struct Arbre *fg,*fd;
}Arbre ;


#include "commons/SD/Liste.h"
#include "commons/SD/File.h"
#include "commons/SD/Pile.h"
#include "commons/SD/Arbre.h"

#include "commons/commande.h"

#include "progtools/lexical/registre.h"
#include "progtools/lexical/numbers.h"