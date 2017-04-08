//  Fenetre Dialog
void interfaceDialog_fenetre(GtkWidget *widget,gpointer data)
{
    All *all = data;
    GtkWidget *parent = all->f->this , *content_area ;
    int rep;
    GtkWidget   *id, *idVal, *titre, *titreVal, *longueur, *longueurVal, 
                *largeur, *largeurVal, *positionX, *positionXVal, *positionY, *positionYVal;

    GtkWidget *dialog = gtk_dialog_new_with_buttons( utf8("Creation d'une Fenêtre") ,
                                                    GTK_WINDOW(parent)               ,
                                                    GTK_DIALOG_MODAL                ,
                                                    "_Creer",GTK_RESPONSE_OK        ,
                                                    "_Annuler",GTK_RESPONSE_CANCEL  ,
                                                    NULL);
    cssDataToWidget(dialog, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(dialog, "color : #222;background-color:#CCCEDB;");

    //  recuperer contenaire du dialog                                                    
    content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
    cssDataToWidget(content_area, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(content_area, "color : #222;background-color:#CCCEDB;");
    //  creation d'un  grid où on va mettre nos element
    Container *grid = new_Grid();
    //  creation des elements
    id 			 =gtk_label_new("Id du Composant");
    idVal		 =gtk_entry_new();
    titre		 =gtk_label_new("Titre");
    titreVal     =gtk_entry_new();
    longueur 	 =gtk_label_new("Longueur");
    longueurVal	 =gtk_entry_new();
    largeur 	 =gtk_label_new("Largeur");
    largeurVal	 =gtk_entry_new();
    positionX 	 =gtk_label_new("Position X");
    positionXVal =gtk_entry_new();
    positionY 	 =gtk_label_new("Position Y");
    positionYVal =gtk_entry_new();
    //  ajout des elements au grid
    grid = Grid_add(grid,id             ,0,0,1,1);			 
    grid = Grid_add(grid,idVal          ,1,0,1,1);		 
    grid = Grid_add(grid,titre          ,0,1,1,1);		 
    grid = Grid_add(grid,titreVal       ,1,1,1,1);		 
    grid = Grid_add(grid,longueur       ,0,2,1,1); 	 
    grid = Grid_add(grid,longueurVal    ,1,2,1,1);	 
    grid = Grid_add(grid,largeur        ,0,3,1,1); 	 
    grid = Grid_add(grid,largeurVal     ,1,3,1,1);	 
    grid = Grid_add(grid,positionX      ,0,4,1,1); 	 
    grid = Grid_add(grid,positionXVal   ,1,4,1,1); 
    grid = Grid_add(grid,positionY      ,0,5,1,1); 	 
    grid = Grid_add(grid,positionYVal   ,1,5,1,1); 

    //  Ajouter des espacement
    gtk_grid_set_row_spacing (GTK_GRID(grid->this), 10);
    gtk_grid_set_column_spacing (GTK_GRID(grid->this), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(content_area), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(grid->this), 20);

    gtk_container_add(GTK_CONTAINER(content_area),grid->this);
    gtk_widget_show_all (dialog);

    //  execution du dialog    
    rep = gtk_dialog_run (GTK_DIALOG (dialog));
    //  creer la fenetre si la reponse est oui
    if(rep == GTK_RESPONSE_OK)
    {
        //  TRAITEMENT
    }
    else
        gtk_widget_destroy (dialog);
}