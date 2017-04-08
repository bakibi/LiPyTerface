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
            gtk_main_quit();
        else
            gtk_widget_destroy (dialog);
    }
}