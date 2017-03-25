/********************** Cette page est dedier à Stack  **************************/




//          Fonction de creation d un container de type Stack
//      Entree:
//      Sortie:
Container *new_Stack()
{
    Container *c = (Container *)malloc(sizeof(Container));
    if(!c)
    {
        printf("Erreur ! Probleme d'allocation du composant Container");
        exit(-1);
    }
    c->type = STACK;
    c->this = gtk_stack_new();

    return (Container *)c;
}//fin de la fonction




//          Fonction qui ajout un componement a un container de type stack
//      Entree:
//      Sortie:
Container *Stack_add(Container *c,GtkWidget *w,const char *nom)
{
    gtk_stack_add_titled(GTK_STACK(c->this),w,nom,nom);
    return (Container *)c;

}//fin de la fonction


//          Fonction qui rend le panneau qui switch les pages
//      Entree: le container qui f=doit etre de type Stack
//      Sortie: le container qui contient le stackswitched
Container *Stack_getStackSwitch(Container *cc)
{
    Container *c = (Container *)malloc(sizeof(Container));
    if(!c)
    {
        printf("Erreur ! Probleme d'allocation du composant Container");
        exit(-1);
    }
    c->type = STACKSWITCHER;
    c->this = gtk_stack_switcher_new ();
    gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(c->this),GTK_STACK(cc->this));

    return (Container *)c;
}



//          Fonction qui choisie quel fils doit etre afficher en premier
//      ENtree: le fils 
//      Sortie : le container bien modifier
Container *Stack_setVisibleChild(Container *c,GtkWidget *w)
{
    gtk_stack_set_visible_child(GTK_STACK(c->this),w);
    return (Container *)c;
}