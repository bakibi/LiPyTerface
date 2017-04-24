void alert_nombre_occ(All *all,char *text)
{
    int rep;
    GtkWidget *parent = all->f->this , *content_area ;
    GtkWidget   *label;

    GtkWidget *dialog = gtk_dialog_new_with_buttons( utf8("Résultat Recherche") ,
                                                    GTK_WINDOW(parent)               ,
                                                    GTK_DIALOG_MODAL                ,
                                                    "_OK",GTK_RESPONSE_OK  ,
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
    label 	=gtk_label_new(text);
    //  ajout des elements au grid
    grid = Grid_add(grid,label  ,0,0,1,1);			 
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
        gtk_widget_destroy (dialog);
}