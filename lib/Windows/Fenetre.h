
/****************************************************************************
 ****************************************************************************
 ****		Cette page est reservé au compososant  de LA FENTERE		 ****
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 *					Fonction de creation de la Fenetre						*
 ****************************************************************************
 *		Entree	:	titre de lafenetre										*
 *					type de la fenetre										*	
 *					taille de la fenetre									*
 *					position de la fenetre									*
 *      Sortie	:	Une nouvelle Fenetre									*
 ****************************************************************************/

Fenetre *new_Fenetre(const char *titre,int type,Taille *t,int position)
{

    Fenetre *f = (Fenetre *)malloc(sizeof(Fenetre));
    f->container = NULL;
    f->t = NULL;
    f->titre = (char *)malloc(sizeof(char)*15);
    if(!f || !f->titre)
    {
        printf("Erreur ! Allocation de memoire Fenetre \n");
        exit(-1);
    }

    if(type == NORMAL)
        f->this = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        
    else 
        f->this = gtk_window_new(GTK_WINDOW_POPUP);
        
    Container *c = new_Box(VERTICAL,0,FALSE);
    f = Fenetre_setContainer(f,c);
    f = Fenetre_setTaille(f,t);
    f = Fenetre_setTitre(f,titre);
    f = Fenetre_setPosition(f,position);

    g_signal_connect (f->this, "destroy",G_CALLBACK (gtk_main_quit), NULL);

    return (Fenetre *)f;
}//Fin de la fonction

/****************************************************************************
 *							Fonction setVisible								*
 ****************************************************************************
 *	Cette fonction met une fenetre dans un etat visible ou pas				*
 ****************************************************************************
 *		Entree	:	Fenetre													*
 *					Booléen													*
 *      Sortie	:	void													*
 ****************************************************************************/

void Fenetre_setVisible(Fenetre *f,gboolean verite)
{
    if(verite)
        gtk_widget_show_all(f->this);
    else
        gtk_widget_hide(f->this);        
}

/****************************************************************************
 *							Fonction destroy								*
 ****************************************************************************
 *	cette fonction detruit difinitivement une fenetre						*
 ****************************************************************************
 *		Entree	:	Fenetre à detruire										*
 *      Sortie	:	pointeur NULL											*
 ****************************************************************************/

Fenetre *Fenetre_destroy(Fenetre *f)
{
    gtk_widget_destroy(f->this);
    if(f) free(f);
    return NULL;
}

/****************************************************************************
 *							Fonction setIcon								*
 ****************************************************************************
 *	Cette permet d'ajouter une icon situant dans le disque					*
 **************************************************************************** 
 *	Entree	:	filePath	le chemin de l'icone							*
 *              name		le nom de l'icon								*
 *	Sortie	:	void														*
 ****************************************************************************/

void Fenetre_setIcon(Fenetre *f,const char *file,const char *name)
{
    const gchar *filepath = g_strconcat( "/home/elk/Documents/ILISI/S2/gtk project/Step to LiPyTerface/img/", file, NULL);
    GdkPixbuf *g = gdk_pixbuf_new_from_file(filepath,NULL);
    gtk_window_set_icon (GTK_WINDOW(f->this),g);
    //gtk_window_set_default_icon_name (name);
}//fin de la fonction




//          Fonction qui fait le lien entre le window et le fichier
//      Entree: path of the file 
//      Sortie: une fenetre bien modifiés
Fenetre *Fenetre_addCssFile(Fenetre *f,const char *path)
{
    GtkStyleContext *context;
    GtkCssProvider *provider;
    GFile *fi = g_file_new_for_path (path);

    context = gtk_widget_get_style_context (f->this);
    provider = gtk_css_provider_new ();
    gtk_css_provider_load_from_file (GTK_CSS_PROVIDER (provider),fi,NULL);
    gtk_style_context_add_provider (context,GTK_STYLE_PROVIDER (provider),GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
     g_object_unref (provider);
}//fin de la focntion 



//          Fonction qui agrandie totalement une fenetre 
//      Entree: la fenetre
//      Sortie: NONE
void Fenetre_agrandir(Fenetre *f)
{
	GdkScreen * ecran = gtk_window_get_screen(GTK_WINDOW(f->this));

	gint x = gdk_screen_get_width(ecran),
		 y = gdk_screen_get_height(ecran);

    gtk_window_set_default_size(GTK_WINDOW(f->this),x,y);

}//fin de la fonction


/****************************************************************************
 ****************************************************************************
 ******							LES ACCESSEURS						   ******
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 *								CONTAINER									*
 ****************************************************************************/

//      Fonction set
Fenetre *Fenetre_setContainer(Fenetre *f,Container *c)
{
    if(f->container != NULL)
    {
        gtk_container_remove(GTK_CONTAINER(f->this),f->container->this);
       if(f->container != NULL) free(f->container);
    }
    f->container = c;
    gtk_container_add(GTK_CONTAINER(f->this),c->this);

    return (Fenetre *)f;
}//fin de la fonction

//      Fonction get
Container *Fenetre_getContainer(Fenetre *f)
{
    return (Container *) f->container;
}//Fin de la fonction


/****************************************************************************
 *									TITRE									*
 ****************************************************************************/

//      Fonction set
Fenetre *Fenetre_setTitre(Fenetre *f,const char *nvtitre)
{
      strcpy(f->titre,"");
      strcpy(f->titre,nvtitre);
      gtk_window_set_title(GTK_WINDOW(f->this),f->titre);
    if(!f->titre)
    {
        printf("Erreur! probleme de copiage du tire de la fenetre\n");
        exit(-1);
    }
    return (Fenetre *)f;
}//fin de la fonction

//      Fonction set
char *Fenetre_getTitre(Fenetre *f)
{
    return f->titre;
}//fin de la fonction 

/****************************************************************************
 *									TAILLE									*
 ****************************************************************************/

//      Fonction set
Fenetre *Fenetre_setTaille(Fenetre *f,Taille *t)
{
    Taille *r = f->t;
    if(!r) free(r);
    f->t = t;
    gtk_window_set_default_size(GTK_WINDOW(f->this),t->x,t->y);
    return (Fenetre *)f;
}//fin de la fonction

//      Fonction set
Taille *Fenetre_getTaille(Fenetre *f)
{
    return f->t;
}//fin de la fonction


/****************************************************************************
 *									POSITION								*
 ****************************************************************************/

//      Fonction set
Fenetre *Fenetre_setPosition(Fenetre *f,int position)
{
    f->position = position;
    switch (position)
    {
        case P_NONE : gtk_window_set_position(GTK_WINDOW(f->this),GTK_WIN_POS_NONE);
                      break;
        case P_CENTER : gtk_window_set_position(GTK_WINDOW(f->this),GTK_WIN_POS_CENTER);
                      break;
        case P_CENTER_ON_PARENT : gtk_window_set_position(GTK_WINDOW(f->this),GTK_WIN_POS_CENTER_ON_PARENT);
                      break;
        case P_MOUSE : gtk_window_set_position(GTK_WINDOW(f->this),GTK_WIN_POS_MOUSE);
                      break;
        default :
                      break;                      
    };
    return (Fenetre *)f;
}//fin de la fonction

//      Fonction set
int Fenetre_getPosition(Fenetre *f)
{
    return f->position;
}//fin de la fonction
