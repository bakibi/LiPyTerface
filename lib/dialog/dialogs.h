//  file chooser open file dialog
void dialog_open_file(All *all)
{
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;

    dialog = gtk_file_chooser_dialog_new ("Ouvrir un Fichier" ,  GTK_WINDOW(all->quick->f->this), action,
                                            "_Annuler"   ,   GTK_RESPONSE_CANCEL     ,
                                            "_Ouvrir"     ,   GTK_RESPONSE_ACCEPT     ,
                                            NULL);

    res = gtk_dialog_run (GTK_DIALOG (dialog));
    if (res == GTK_RESPONSE_ACCEPT)
        {
        char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
        filename = gtk_file_chooser_get_filename (chooser);

        FILE *file;
        file = fopen(filename, "r");
        if (file) {
            //clear editor
            GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->editor));
            gtk_text_buffer_set_text(buffer,"",-1);
            GtkTextIter iter;
            gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
            
            //adding content of file character per character
            char ch;
            while ((ch = getc(file)) != EOF)
            {
                char tmp[2];
                tmp[0]=ch;
                
                tmp[1]='\0';
                gtk_text_buffer_insert (buffer,&iter,tmp,-1);
            }
            fclose(file);
        }
        g_free (filename);
        }

    gtk_widget_destroy (dialog);
}

//  YES NO confirmation when quitting programm
void dialog_quit_confirmation (GtkWidget *widget, gpointer data)
{
    All *all = data;

    if(all->quick->isShown == TRUE)
    {
        GtkWidget *parent = all->f->this , *content_area , *label;
        int rep;
        const gchar *conv_utf8;

        GtkWidget *dialog = gtk_dialog_new_with_buttons("Pas si Vite !"         ,
                                                        GTK_WINDOW(parent)      ,
                                                        GTK_DIALOG_MODAL        ,
                                                        "_Oui",GTK_RESPONSE_YES ,
                                                        "_Non",GTK_RESPONSE_NO  ,
                                                        NULL
                                                        );
        cssDataToWidget(dialog, "color :#DDDDDD;background-color:#252526;");
        if(!all->isDark)    
            cssDataToWidget(dialog, "color : #222;background-color:#CCCEDB;");
        //  recuperer contenaire du dialog                                                    
        content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
        cssDataToWidget(content_area, "color :#DDDDDD;background-color:#252526;");
        if(!all->isDark)    
            cssDataToWidget(content_area, "color : #222;background-color:#CCCEDB;");
        gtk_container_set_border_width ( GTK_CONTAINER(content_area), 10);
        //  creation de message label
        conv_utf8 = g_locale_to_utf8 ("Êtes vous sûr de vouloir quitter le programme ?",-1,0,0,0);
        label = gtk_label_new( conv_utf8 );
        //  ajout du message au contenaire du dialog et afficher tout
        gtk_container_add (GTK_CONTAINER (content_area), label);
        gtk_widget_show_all (dialog);
        //  execution du dialog    
        rep = gtk_dialog_run (GTK_DIALOG (dialog));
        //  quitter le programme si la reponse est oui
        if(rep == GTK_RESPONSE_YES)
        {
            enregistrer_historique_fichier(all->histo);
            gtk_main_quit();
        }
            
        else
            gtk_widget_destroy (dialog);
    }
}

//  YES NO confirmation when quitting programm
void dialog_quit_confirmation_from_menu (GtkWidget *widget, gpointer data)
{
    All *all = data;

    GtkWidget *parent = all->f->this , *content_area , *label;
    int rep;
    const gchar *conv_utf8;

    GtkWidget *dialog = gtk_dialog_new_with_buttons("Pas si Vite !"         ,
                                                    GTK_WINDOW(parent)      ,
                                                    GTK_DIALOG_MODAL        ,
                                                    "_Oui",GTK_RESPONSE_YES ,
                                                    "_Non",GTK_RESPONSE_NO  ,
                                                    NULL
                                                    );
    cssDataToWidget(dialog, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(dialog, "color : #222;background-color:#CCCEDB;");
    //  recuperer contenaire du dialog                                                    
    content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
    cssDataToWidget(content_area, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(content_area, "color : #222;background-color:#CCCEDB;");
    gtk_container_set_border_width ( GTK_CONTAINER(content_area), 10);
    //  creation de message label
    conv_utf8 = g_locale_to_utf8 ("Êtes vous sûr de vouloir quitter le programme ?",-1,0,0,0);
    label = gtk_label_new( conv_utf8 );
    //  ajout du message au contenaire du dialog et afficher tout
    gtk_container_add (GTK_CONTAINER (content_area), label);
    gtk_widget_show_all (dialog);
    //  execution du dialog    
    rep = gtk_dialog_run (GTK_DIALOG (dialog));
    //  quitter le programme si la reponse est oui
    if(rep == GTK_RESPONSE_YES)
        {
            enregistrer_historique_fichier(all->histo);
            gtk_main_quit();
        }
    else
        gtk_widget_destroy (dialog);
}

//  recherche dialog
void recherche_dialog(GtkWidget *widget,gpointer data)
{
    All *all = data;
    int rep;
    GtkWidget *parent = all->f->this , *content_area ;
    GtkWidget   *label, *entry;

    GtkWidget *dialog = gtk_dialog_new_with_buttons( utf8("Recherche") ,
                                                    GTK_WINDOW(parent)               ,
                                                    GTK_DIALOG_MODAL                ,
                                                    "_Rechercher",GTK_RESPONSE_OK        ,
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
    label 	=gtk_label_new(utf8("Mot clé"));
    entry	=gtk_entry_new();
    gtk_entry_set_placeholder_text ( GTK_ENTRY(entry), utf8("Terme à Rechercher") );
    
    //  ajout des elements au grid
    grid = Grid_add(grid,label  ,0,0,1,1);			 
    grid = Grid_add(grid,entry  ,1,0,1,1);

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
        //  si on a rien saisi
        int x = (int)gtk_entry_get_text_length (GTK_ENTRY(entry));
        if( x == 0)
        {
            alert_recherche_vide(all);
             gtk_widget_destroy (dialog);
        }
        else
        {
            int count1=0, count2=0;
            GtkTextIter start_find, end_find, start_match, end_match;
            
            //  INTERPRETEUR
            GtkTextBuffer *buffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->console));

            gtk_text_buffer_get_start_iter(buffer, &start_find);
            gtk_text_buffer_get_end_iter(buffer, &end_find);

            gtk_text_buffer_remove_tag_by_name(buffer, "lightgray_bg", &start_find, &end_find);
            gtk_text_buffer_remove_tag_by_name(buffer, "black_fg", &start_find, &end_find);  
            const gchar *keyWord = gtk_entry_get_text(GTK_ENTRY(entry));

            while (gtk_text_iter_forward_search(&start_find, keyWord, 
                    GTK_TEXT_SEARCH_TEXT_ONLY | GTK_TEXT_SEARCH_VISIBLE_ONLY, 
                    &start_match, &end_match, NULL)) {
            
            gtk_text_buffer_apply_tag_by_name(buffer, "lightgray_bg",&start_match, &end_match);
            gtk_text_buffer_apply_tag_by_name(buffer, "black_fg",&start_match, &end_match);
            gint offset = gtk_text_iter_get_offset(&end_match);
            gtk_text_buffer_get_iter_at_offset(buffer, &start_find, offset);
            //    incrementer le nombre d'occurence'
            count1++;
            }

            //  EDITEUR
            buffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->editor));

            gtk_text_buffer_get_start_iter(buffer, &start_find);
            gtk_text_buffer_get_end_iter(buffer, &end_find);

            gtk_text_buffer_remove_tag_by_name(buffer, "lightgray_bg", &start_find, &end_find);
            gtk_text_buffer_remove_tag_by_name(buffer, "black_fg", &start_find, &end_find);  
            keyWord = gtk_entry_get_text(GTK_ENTRY(entry));

            while (gtk_text_iter_forward_search(&start_find, keyWord, 
                    GTK_TEXT_SEARCH_TEXT_ONLY | GTK_TEXT_SEARCH_VISIBLE_ONLY, 
                    &start_match, &end_match, NULL)) {
            
            gtk_text_buffer_apply_tag_by_name(buffer, "lightgray_bg",&start_match, &end_match);
            gtk_text_buffer_apply_tag_by_name(buffer, "black_fg",&start_match, &end_match);
            gint offset = gtk_text_iter_get_offset(&end_match);
            gtk_text_buffer_get_iter_at_offset(buffer, &start_find, offset);
            //    incrementer le nombre d'occurence'
            count2++;
            }

            //  ouvrir un pop up indiquant ces nombres d'occurence
            char buf1[30], buf2[30];
            sprintf(buf1, "Nb Occurence iterpréteur : %d", count1);
            sprintf(buf2, "Nb Occurence éditeur         : %d", count2);
            alert_nombre_occ(all,buf1, buf2);
            gtk_widget_destroy (dialog);
        }
    }
    else
        gtk_widget_destroy (dialog);
}

//  YES NO confirmation when quitting programm
void dialog_raccourcis (GtkWidget *widget, gpointer data)
{
    All *all = data;

    GtkWidget *parent = all->f->this , *content_area ;
    int rep;
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Liste Raccourci"         ,
                                                    GTK_WINDOW(parent)      ,
                                                    GTK_DIALOG_MODAL        ,
                                                    "_Fermer",GTK_RESPONSE_YES ,
                                                    NULL
                                                    );
    cssDataToWidget(dialog, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(dialog, "color : #222;background-color:#CCCEDB;");
    //  recuperer contenaire du dialog                                                    
    content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
    cssDataToWidget(content_area, "color :#DDDDDD;background-color:#252526;");
    if(!all->isDark)    
        cssDataToWidget(content_area, "color : #222;background-color:#CCCEDB;");
    gtk_container_set_border_width ( GTK_CONTAINER(content_area), 10);
    
    //  creation d'un  grid où on va mettre nos element
    Container *grid = new_Grid();
    
    //  creation des elements
    GtkWidget   *label1 = gtk_label_new(utf8("CTRL + L ou l"));
    GtkWidget   *label2 = gtk_label_new(utf8("CTRL + P ou p"));
    GtkWidget   *label3 = gtk_label_new(utf8("CTRL + Q ou q"));
    GtkWidget   *label4 = gtk_label_new(utf8("CTRL + T ou t"));
    GtkWidget   *label5 = gtk_label_new(utf8("CTRL + K ou k"));
    GtkWidget   *label6 = gtk_label_new(utf8("CTRL + M ou m"));
    GtkWidget   *label7 = gtk_label_new(utf8("CTRL + R ou r"));
    GtkWidget   *label8 = gtk_label_new(utf8("CTRL + O ou o"));
    GtkWidget   *label9 = gtk_label_new(utf8("CTRL + E ou e"));
    GtkWidget   *label10= gtk_label_new(utf8("Effacer contenu Console"));
    GtkWidget   *label11= gtk_label_new(utf8("Afficher les Options Quick"));
    GtkWidget   *label12= gtk_label_new(utf8("Quitter"));
    GtkWidget   *label13= gtk_label_new(utf8("Changer de Thème"));
    GtkWidget   *label14= gtk_label_new(utf8("Afficher l'application"));
    GtkWidget   *label15= gtk_label_new(utf8("Changer de Mode"));
    GtkWidget   *label16= gtk_label_new(utf8("Recherche"));
    GtkWidget   *label17= gtk_label_new(utf8("Ouvrir Fichier Bash"));
    GtkWidget   *label18= gtk_label_new(utf8("Exécuter Bash"));
    
    //  ajout des elements au grid
    grid = Grid_add(grid , label1 , 0 , 0 , 1 , 1 );
    grid = Grid_add(grid , label2 , 0 , 1 , 1 , 1 );
    grid = Grid_add(grid , label3 , 0 , 2 , 1 , 1 );
    grid = Grid_add(grid , label4 , 0 , 3 , 1 , 1 );
    grid = Grid_add(grid , label5 , 0 , 4 , 1 , 1 );
    grid = Grid_add(grid , label6 , 0 , 5 , 1 , 1 );
    grid = Grid_add(grid , label7 , 0 , 6 , 1 , 1 );
    grid = Grid_add(grid , label8 , 0 , 7 , 1 , 1 );
    grid = Grid_add(grid , label9 , 0 , 8 , 1 , 1 );
    grid = Grid_add(grid , label10, 1 , 0 , 1 , 1 );
    grid = Grid_add(grid , label11, 1 , 1 , 1 , 1 );
    grid = Grid_add(grid , label12, 1 , 2 , 1 , 1 );
    grid = Grid_add(grid , label13, 1 , 3 , 1 , 1 );
    grid = Grid_add(grid , label14, 1 , 4 , 1 , 1 );
    grid = Grid_add(grid , label15, 1 , 5 , 1 , 1 );
    grid = Grid_add(grid , label16, 1 , 6 , 1 , 1 );
    grid = Grid_add(grid , label17, 1 , 7 , 1 , 1 );
    grid = Grid_add(grid , label18, 1 , 8 , 1 , 1 );
    //  Ajouter des espacement
    gtk_grid_set_row_spacing (GTK_GRID(grid->this), 30);
    gtk_grid_set_column_spacing (GTK_GRID(grid->this), 100);
    gtk_container_set_border_width ( GTK_CONTAINER(content_area), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(grid->this), 20);

    gtk_container_add(GTK_CONTAINER(content_area),grid->this);
    gtk_widget_show_all (dialog);

    //  execution du dialog    
    rep = gtk_dialog_run (GTK_DIALOG (dialog));
    //  quitter le programme si la reponse est oui
    if(rep == GTK_RESPONSE_YES)
         gtk_widget_destroy (dialog);
       
}