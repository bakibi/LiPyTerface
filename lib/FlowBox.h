/************ Cette page est destine au composant du FlowBOx *************/




//          Fonction de creation de Container FlowBOx
//      Entree: NONE
//      Sortie: Container bien initialisé
Container *new_FlowBox()
{
    Container *c = (Container *)malloc(sizeof(Container));
    if(!c)
    {
        printf("Erreur ! Probleme d'allocation du composant Container");
        exit(-1);
    }
    c->type = FLOWBOX;
    c->this = gtk_flow_box_new();

    return (Container *)c;
}//fin de la fonction





//          Fonction d'insertion dans un container de type FlowBox
//      Entree: le Composant à inserer
//              la position du composant que vous voulez inserer
//      Sortie: le COntainer bien modifiées
Container *FlowBox_add(Container *c,GtkWidget *w,int position)
{
    gtk_flow_box_insert(GTK_FLOW_BOX(c->this),w,position);
    return (Container *)c;
}//fin de la fonction