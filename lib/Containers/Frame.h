//  Fonction Creation de frame
Container* new_Frame(const gchar *titre, int espace)
{
    Container *c = (Container *)malloc(sizeof(Container));

    if(!c)
    {
        printf("Erreur ! Probleme d'allocation du composant Container");
        exit(-1);
    }

    c->type = FRAME;
    
    c->this = gtk_frame_new(titre);

    gtk_container_set_border_width ( GTK_CONTAINER(c->this), espace);

    return (Container *)c; 
}//la fin de la fonction



//  Fonction ajouter un element au frame
Container* Frame_add(Container *c, GtkWidget *w)
{
    gtk_container_add( GTK_CONTAINER(c->this) , w );
    return (c);
}//la fin de la fonction



//  Fonction recuperer l'objet label du frame
GtkWidget* Frame_get_label(Container *c)
{
    GtkWidget *label = gtk_frame_get_label_widget(GTK_FRAME(c->this));
    return (label);
}//la fin de la fonction

