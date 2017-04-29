//  BOUTON SHOW

void show_clicked(GtkWidget *widget, gpointer data) {

  All *all = data;

  if(all->quick->isShown == FALSE)
  {
    //    Afficher les Option avec Animation
    animation_fadeIn(all->quick->mode->this);
    animation_fadeIn(all->quick->theme->this);
    animation_fadeIn(all->quick->search->this);
    animation_fadeIn(all->quick->quit->this);
    if(all->isBash==TRUE)
    {
        animation_fadeIn(all->quick->run->this);
        animation_fadeIn(all->quick->upload->this);
        gtk_widget_set_tooltip_text (all->quick->run->this, utf8("Exécuter le Bash"));
        gtk_widget_set_tooltip_text (all->quick->upload->this, utf8("Ouvrir un Fichier"));
    }
    //    Modifier le Show Bouton à Hide Bouton
    Button_set_image(all->quick->show,"quick/hide.png");
    //  Ajouter les Tooltip
    gtk_widget_set_tooltip_text (all->quick->mode->this, "Changer de Mode");
    gtk_widget_set_tooltip_text (all->quick->theme->this, utf8("Changer de Thème"));
    gtk_widget_set_tooltip_text (all->quick->quit->this, utf8("Quitter le Programme"));
    gtk_widget_set_tooltip_text (all->quick->show->this, utf8("Cacher les Options"));
    gtk_widget_set_tooltip_text (all->quick->search->this, utf8("Rechercher un mot clé"));

    all->quick->isShown = TRUE;
  }
  else
  {
    //  Cacher les Option avec Animation
    animation_fadeOut(all->quick->mode->this);
    animation_fadeOut(all->quick->theme->this);
    animation_fadeOut(all->quick->quit->this);
    animation_fadeOut(all->quick->run->this);
    animation_fadeOut(all->quick->upload->this);
    animation_fadeOut(all->quick->search->this);
    //    Modifier le Hide Bouton à Show Bouton
    Button_set_image(all->quick->show,"quick/show.png");
    //  Ajouter/Desactiver les Tooltip
    gtk_widget_set_tooltip_text (all->quick->mode->this, NULL);
    gtk_widget_set_tooltip_text (all->quick->theme->this, NULL);
    gtk_widget_set_tooltip_text (all->quick->quit->this, NULL);
    gtk_widget_set_tooltip_text (all->quick->show->this, "Afficher les Options");
    gtk_widget_set_tooltip_text (all->quick->run->this, NULL);
    gtk_widget_set_tooltip_text (all->quick->upload->this, NULL);
    gtk_widget_set_tooltip_text (all->quick->search->this, NULL);

    all->quick->isShown = FALSE;
  }
}

//  BOUTON THEME
void theme_clicked(GtkWidget *widget, gpointer data) {

  All *all = data;

  if(all->quick->isShown == TRUE)
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
}

//  BOUTON MODE
void mode_clicked(GtkWidget *widget, gpointer data) {

  All *all = data;

  if(all->quick->isShown == TRUE)
  {
    if(all->isBash == FALSE)
    {
      //  Cacher Mode Interpréteur et Afficher le Mode Bash
      gtk_widget_set_visible (all->body->this, FALSE);
      gtk_widget_set_visible (all->bodyBash->this, TRUE);
      gtk_widget_show_all (all->bodyBash->this);

      //    Afficher les Option Bash avec Animation
      animation_fadeIn(all->quick->run->this);
      animation_fadeIn(all->quick->upload->this);
      gtk_widget_set_tooltip_text (all->quick->run->this, utf8("Exécuter le Bash"));
      gtk_widget_set_tooltip_text (all->quick->upload->this, utf8("Ouvrir un Fichier"));

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
}

//  BOUTON UPLOAD
void upload_clicked(GtkWidget *widget, gpointer data) {

  All *all = data;

  //  Si on et dans le mode Bash Ouvrir l'explorateur de fichier
  if(all->quick->isShown == TRUE)
     dialog_open_file(all);
}

//  BOUTON RUN
void run_clicked(GtkWidget *widget, gpointer data) {

  All *all = data;

  GtkTextBuffer *buffer1=gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->editor));
  
  //  creation de 2 iter pour delimiter le debut et la fin du contenu
  GtkTextIter start,end;
  gtk_text_buffer_get_iter_at_mark(buffer1, &start, gtk_text_buffer_get_insert(buffer1));
  gtk_text_buffer_get_iter_at_mark(buffer1, &end, gtk_text_buffer_get_insert(buffer1));
  gtk_text_iter_set_offset (&start, 0);
  gtk_text_iter_forward_to_end (&end);

  gchar *bashText = gtk_text_buffer_get_text(buffer1,&start,&end,FALSE);

  //  Chargement des commandes
  Commande *cmd = new_Commande(bashText);
  cmd = Commande_interpreter(cmd);

  //  Affichage du resulat dans le VS terminal (à enlever après)
  char stri[30000] = "";
  sprintf(stri,"%s\n %s \n%s",cmd->errors,cmd->warnings,cmd->output);

  //  Nettoyer l'output
  GtkTextBuffer *buffer2=gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->output));
  gtk_text_buffer_set_text(buffer2,"",-1);

  //  Recuperer Le buffer l'iter sur la premiere position
  GtkTextIter iter =  TextView_get_iter(all->output_comp, 0, 0);

  //  Recuperer l'heure et date d'execution
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  gchar *dateHeure = g_strconcat( "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDate et Heure d'éxécution : " ,
                                  asctime (timeinfo) ,"\n\n", NULL);

  //  Ecrire l'heure et date d'execution
  iter = TextView_get_iter_end(all->output_comp);
  TextView_insert_text(all->output_comp,iter, dateHeure, "green_fg");
  
  //  Afficher les warnings en orange
  iter = TextView_get_iter_end(all->output_comp);
  TextView_insert_text(all->output_comp,iter,cmd->warnings , "orange_fg");
  //  Afficher la sortie standard en couleur standard  
  iter = TextView_get_iter_end(all->output_comp);
  TextView_insert_text(all->output_comp,iter,cmd->output , NULL);
  //  Afficher les erreurs en rouge
  iter = TextView_get_iter_end(all->output_comp);
  TextView_insert_text(all->output_comp,iter,cmd->errors , "red_fg");
}

//    Double clique sur show pour afficher l'application
gint signal_handler_event(GtkWidget *widget, GdkEventButton *event, gpointer data)
{

    All *all = data;

    if (GTK_IS_BUTTON(widget) &&
        (event->type==GDK_2BUTTON_PRESS ||
            event->type==GDK_3BUTTON_PRESS) ) {
        
        gtk_window_deiconify(GTK_WINDOW(all->f->this));
    }

    return FALSE;
}