//  Fonction Creation du Scroll Container
Container* new_Scroll(int espace)
{
    Container *c = (Container *)malloc(sizeof(Container));

    if(!c)
    {
        printf("Erreur ! Probleme d'allocation du composant Container");
        exit(-1);
    }

    c->type = SCROLL;

    c->this = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(c->this), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS );

    gtk_container_set_border_width ( GTK_CONTAINER(c->this), espace);

    return (Container *)c; 
}//la fin de la fonction



//  Fonction ajouter un element au Scroll Container
Container* Scroll_add(Container *c, GtkWidget *w)
{
    gtk_container_add( GTK_CONTAINER(c->this) , w );
    return (c);
}//la fin de la fonction
