//  BOUTON SHOW
void show_clicked(GtkWidget *widget, gpointer data) {

  All *all = data;

  if(all->quick->isShown == FALSE)
  {
    //    Showing the options with animation
    animation_fadeIn(all->quick->mode->this);
    animation_fadeIn(all->quick->theme->this);
    animation_fadeIn(all->quick->quit->this);
    if(all->isBash==TRUE)
    {
        animation_fadeIn(all->quick->run->this);
        animation_fadeIn(all->quick->upload->this);
        gtk_widget_set_tooltip_text (all->quick->run->this, utf8("Exécuter le Bash"));
        gtk_widget_set_tooltip_text (all->quick->upload->this, utf8("Ouvrir un Fichier"));
    }
    //    modifing the show button to hide button
    Button_set_image(all->quick->show,"quick/hide.png");
    //  setting tooltips
    gtk_widget_set_tooltip_text (all->quick->mode->this, "Changer de Mode");
    gtk_widget_set_tooltip_text (all->quick->theme->this, utf8("Changer de Thème"));
    gtk_widget_set_tooltip_text (all->quick->quit->this, utf8("Quitter le Programme"));
    gtk_widget_set_tooltip_text (all->quick->show->this, utf8("Cacher les Options"));

    all->quick->isShown = TRUE;
  }
  else
  {
    //  hiding the options with animation
    animation_fadeOut(all->quick->mode->this);
    animation_fadeOut(all->quick->theme->this);
    animation_fadeOut(all->quick->quit->this);
    animation_fadeOut(all->quick->run->this);
    animation_fadeOut(all->quick->upload->this);
    //    renaming the plus button and then adding it
    Button_set_image(all->quick->show,"quick/show.png");
    //  setting tooltips
    gtk_widget_set_tooltip_text (all->quick->mode->this, NULL);
    gtk_widget_set_tooltip_text (all->quick->theme->this, NULL);
    gtk_widget_set_tooltip_text (all->quick->quit->this, NULL);
    gtk_widget_set_tooltip_text (all->quick->show->this, "Afficher les Options");
    gtk_widget_set_tooltip_text (all->quick->run->this, NULL);
    gtk_widget_set_tooltip_text (all->quick->upload->this, NULL);

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
        //  interpretor mode
        cssDataToWidget(all->console, "color : #222;background-color: #EEE"); 
        cssDataToWidget(all->body->this, "background-color: #CCCEDB"); 
        cssDataToWidget(all->leftFrame, "color : #222;background-color: #DDD");
        cssDataToWidget(all->leftTitre, "color : #444;");
        cssDataToWidget(all->rightFrame, "color : #222;background-color: #DDD");
        cssDataToWidget(all->rightTitre, "color : #444;");
        //  bash mode
        cssDataToWidget(all->editor, "color : #222;background-color: #EEE");
        cssDataToWidget(all->output, "color : #222;background-color: #EEE"); 
        cssDataToWidget(all->bodyBash->this, "background-color: #CCCEDB"); 
        cssDataToWidget(all->topFrame, "color : #222;background-color: #DDD");
        cssDataToWidget(all->bottomFrame, "color : #222;background-color: #DDD");
        cssDataToWidget(all->topTitre, "color : #444;");
        cssDataToWidget(all->bottomTitre, "color : #444;");
        //  Both
        cssDataToWidget(all->footer->this, "color : #222;background-color: #29a1f2");

        Button_set_image(all->quick->theme,"quick/darkTheme.png");
        StatusBar_empilerMSG(all->theme,"Theme Clair",2);

        all->isDark = FALSE;
      }
      else
      {
        //  interpretor mode
        cssDataToWidget(all->console, "color : #DDDDDD;background-color: #1E1E1D;"); 
        cssDataToWidget(all->body->this, "background-color:#3F3F46"); 
        cssDataToWidget(all->leftFrame, "color : #23D18B;background-color: #252526");
        cssDataToWidget(all->leftTitre, "color : #23D18B");
        cssDataToWidget(all->rightFrame, "color : #23D18B;background-color: #1E1E1D");
        cssDataToWidget(all->rightTitre, "color : #23D18B");
        //  bash mode
        cssDataToWidget(all->editor, "color : #DDDDDD;background-color: #1E1E1D;"); 
        cssDataToWidget(all->output, "color : #DDDDDD;background-color: #1E1E1D;"); 
        cssDataToWidget(all->bodyBash->this, "background-color:#3F3F46"); 
        cssDataToWidget(all->topFrame, "color : #23D18B;background-color: #252526");
        cssDataToWidget(all->topTitre, "color : #23D18B");
        cssDataToWidget(all->bottomFrame, "color : #23D18B;background-color: #1E1E1D");
        cssDataToWidget(all->bottomTitre, "color : #23D18B");
        //  both
        cssDataToWidget(all->footer->this, "color:#CCC;background-color:#007ACC");

        Button_set_image(all->quick->theme,"quick/lightTheme.png");
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
      //  HIDING INTERPRETOR MODE AND SHOWING BASH MODE
      gtk_widget_set_visible (all->body->this, FALSE);
      gtk_widget_set_visible (all->bodyBash->this, TRUE);
      gtk_widget_show_all (all->bodyBash->this);

      //    Showing the bash options with animation
      animation_fadeIn(all->quick->run->this);
      animation_fadeIn(all->quick->upload->this);
      gtk_widget_set_tooltip_text (all->quick->run->this, utf8("Exécuter le Bash"));
      gtk_widget_set_tooltip_text (all->quick->upload->this, utf8("Ouvrir un Fichier"));

      Button_set_image(all->quick->mode,"quick/interpreteur.png");
      StatusBar_empilerMSG(all->mode,"Mode Bash",1);
      all->isBash = TRUE;
    }
    else
    {
      //  HIDING BASH MODE AND SHOWING INTERPRETOR MODE
      gtk_widget_set_visible (all->body->this, TRUE);
      gtk_widget_set_visible (all->bodyBash->this, FALSE);

      //  Hiding the bash options with animation
      animation_fadeOut(all->quick->run->this);
      animation_fadeOut(all->quick->upload->this);
      gtk_widget_set_tooltip_text (all->quick->run->this, NULL);
      gtk_widget_set_tooltip_text (all->quick->upload->this, NULL);

      Button_set_image(all->quick->mode,"quick/bash.png");
      StatusBar_empilerMSG(all->mode,"Mode Interpreteur",1);
      all->isBash = FALSE;
    }
  }
}

//  BOUTON UPLOAD
void upload_clicked(GtkWidget *widget, gpointer data) {

  All *all = data;

  if(all->quick->isShown == TRUE)
     dialog_open_file(all);
}