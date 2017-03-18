/****   Cette page est reservé au compososant  de Container        ***/




//              LES FONCTIONS   :
//  Fonction de creation du Container
//      ENTREE: type du Container
//              direction (VERTICAL,HORIZENTAL) optiannal
//              name le nom de label optiannal
//      SORTIE: un Container intialiser
Container *new_Container(int type,int direction,char *name)
{
    Container *c = (Container *)malloc(sizeof(Container));
    if(!c)
    {
        printf("Erreur! probleme d'allocation en Container\n");
        exit(-1);
    }
    c->type = type;
    switch (type)
    {
        case BOX:
                if(direction == HORIZENTAL)
                    c->this = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
                else
                    c->this = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); 
                break;
        case GRID:break;
        case LISTBOX:break;
        case FLOWBOX:break;
        case STACK:break;
        case BUTTONBOX:break;
        case EXPANDER:break;
        case FIXED:break;
        default:printf("le type de Container saisie est incorrect\n");
                exit(-1);
                break;
    };

    return (Container *)c;
}//Fin de la fonction