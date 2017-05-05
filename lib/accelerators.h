void accelerator(GtkWidget *window, GdkEventKey* event, All *all) 
{
  gchar *key_name = gdk_keyval_name(event->keyval);
  int key_code = gdk_keyval_from_name(key_name);

  if ((event->type == GDK_KEY_PRESS) && (event->state & GDK_CONTROL_MASK)) 
  {

    //CTRL + L = clear console 
    if( (key_code==76 || key_code==108) && gtk_widget_has_focus(all->console) )
    {         
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->console));
        gtk_text_buffer_set_text(buffer,"",-1);
        GtkTextIter iter;
        gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
        gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "ilisi@shanks:~# ", -1, "orange_fg", NULL);

    }

    //CTRL + P = afficher quick
    else if( (key_code==80 || key_code==112) )
    {
        show_clicked(NULL, all);
    }

    //CTRL + K = afficher l'application
    else if( (key_code==75 || key_code==107) )
    {
        gtk_window_deiconify(GTK_WINDOW(all->f->this));
    }

  //CTRL + Q = Quitter
    else if( (key_code==81 || key_code==113) )
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

    //CTRL + T = Theme
    else if( (key_code==84 || key_code==116) )
    {
        if(all->isDark == TRUE)
        {
          //  Changer les couleur du Mode Interpreteur 
          cssDataToWidget(all->console, "color : #222;background-color: #EEE"); 
          cssDataToWidget(all->body->this, "background-color: #CCCEDB"); 
          cssDataToWidget(all->leftFrame, "color : #222;background-color: #DDD");
          cssDataToWidget(all->leftTitre, "color : #444;");
          cssDataToWidget(all->rightFrame, "color : #222;background-color: #DDD");
          cssDataToWidget(all->rightTitre, "color : #444;");
          //  Changer les couleur du Mode Interpreteur 
          cssDataToWidget(all->editor, "color : #222;background-color: #EEE");
          cssDataToWidget(all->output, "color : #222;background-color: #EEE"); 
          cssDataToWidget(all->bodyBash->this, "background-color: #CCCEDB"); 
          cssDataToWidget(all->topFrame, "color : #222;background-color: #DDD");
          cssDataToWidget(all->bottomFrame, "color : #222;background-color: #DDD");
          cssDataToWidget(all->topTitre, "color : #444;");
          cssDataToWidget(all->bottomTitre, "color : #444;");
          //  Changer les couleur du Footer
          cssDataToWidget(all->footer->this, "color : #222;background-color: #29a1f2");
          //  Modifier l'icone du theme
          Button_set_image(all->quick->theme,"quick/darkTheme.png");
          //  Modifier le message theme du status bar
          StatusBar_empilerMSG(all->theme,"Theme Clair",2);

          all->isDark = FALSE;
        }
        else
        {
          //  Changer les couleur du Mode Interpreteur 
          cssDataToWidget(all->console, "color : #DDDDDD;background-color: #1E1E1D;"); 
          cssDataToWidget(all->body->this, "background-color:#3F3F46"); 
          cssDataToWidget(all->leftFrame, "color : #23D18B;background-color: #252526");
          cssDataToWidget(all->leftTitre, "color : #23D18B");
          cssDataToWidget(all->rightFrame, "color : #23D18B;background-color: #1E1E1D");
          cssDataToWidget(all->rightTitre, "color : #23D18B");
          //  Changer les couleur du Mode Interpreteur 
          cssDataToWidget(all->editor, "color : #DDDDDD;background-color: #1E1E1D;"); 
          cssDataToWidget(all->output, "color : #DDDDDD;background-color: #1E1E1D;"); 
          cssDataToWidget(all->bodyBash->this, "background-color:#3F3F46"); 
          cssDataToWidget(all->topFrame, "color : #23D18B;background-color: #252526");
          cssDataToWidget(all->topTitre, "color : #23D18B");
          cssDataToWidget(all->bottomFrame, "color : #23D18B;background-color: #1E1E1D");
          cssDataToWidget(all->bottomTitre, "color : #23D18B");
          //  Changer les couleur du Footer
          cssDataToWidget(all->footer->this, "color:#CCC;background-color:#007ACC");
          //  Modifier l'icone du theme
          Button_set_image(all->quick->theme,"quick/lightTheme.png");
          //  Modifier le message theme du status bar
          StatusBar_empilerMSG(all->theme,"Theme Sombre",2);

          all->isDark = TRUE;
        }
    }
    //CTRL + M = Mode
    else if( (key_code==77 || key_code==109) )
    {
        if(all->isBash == FALSE)
        {
          //  Cacher Mode Interpréteur et Afficher le Mode Bash
          gtk_widget_set_visible (all->body->this, FALSE);
          gtk_widget_set_visible (all->bodyBash->this, TRUE);
          gtk_widget_show_all (all->bodyBash->this);

          //    Changer l'icone Mode
          Button_set_image(all->quick->mode,"quick/interpreteur.png");
          
          //    Changer le message du Mode dans le status bar
          StatusBar_empilerMSG(all->mode,"Mode Bash",1);
          
          all->isBash = TRUE;
        }
        else
        {
          //  Cacher Mode Bash et Afficher le Mode Interpréteur
          gtk_widget_set_visible (all->body->this, TRUE);
          gtk_widget_set_visible (all->bodyBash->this, FALSE);

          //    Cahcher les Option Bash avec Animation
          animation_fadeOut(all->quick->run->this);
          animation_fadeOut(all->quick->upload->this);
          gtk_widget_set_tooltip_text (all->quick->run->this, NULL);
          gtk_widget_set_tooltip_text (all->quick->upload->this, NULL);

          //    Changer l'icone Mode
          Button_set_image(all->quick->mode,"quick/bash.png");
    
          //    Changer le message du Mode dans le status bar
          StatusBar_empilerMSG(all->mode,"Mode Interpreteur",1);
    
          all->isBash = FALSE;
        }
    }

    //CTRL + R = Recherche
    else if( (key_code==82 || key_code==114) )
    {
      
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

    //CTRL + O = Ouvrir Fichier
    else if( (key_code==79 || key_code==111) )
    {
        if(all->isBash == TRUE)
            dialog_open_file(all);
    }

     //CTRL + E = Executer le bash
    else if( (key_code==69 || key_code==101) )
    {
        if(all->isBash == TRUE)
          run_clicked(NULL,all);
    }
  }
}
