/****   Cette page est reservé au compososant  de Container        ***/




//              LES FONCTIONS   :
//  Fonction de creation du Container
//      ENTREE: type du Container
//              direction (VERTICAL,HORIZENTAL) optiannal
//              name le nom de label optiannal
//      SORTIE: un Container intialiser
Container *new_Container()
{
    Container *c = (Container *)malloc(sizeof(Container));
    if(!c)
    {
        printf("Erreur! probleme d'allocation en Container\n");
        exit(-1);
    }
    c->type = -1;
    c->this = NULL;

    return (Container *)c;
}//Fin de la fonction



//          Fonction pour BoxAddFirst
