//  BOUTON SHOW
void show_clicked(GtkWidget *widget, gpointer data) {

  Quick *quick = data;

  if(quick->isShown == FALSE)
  {
    //    Showing the options with animation
    animation_fadeIn(quick->mode->this);
    animation_fadeIn(quick->theme->this);
    animation_fadeIn(quick->quit->this);
    //    modifing the show button to hide button
    Button_set_image(quick->show,"quick/hide.png");

    quick->isShown = TRUE;
  }
  else
  {
    //  hiding the options with animation
    animation_fadeOut(quick->mode->this);
    animation_fadeOut(quick->theme->this);
    animation_fadeOut(quick->quit->this);
    //    renaming the plus button and then adding it
    Button_set_image(quick->show,"quick/show.png");

    quick->isShown = FALSE;
  }
}

//  BOUTON THEME
void theme_clicked(GtkWidget *widget, gpointer data) {

  All *all = data;

  if(all->isDark == TRUE)
  {
    cssDataToWidget(all->console, "color : #222;background-color: #EEE"); 
    cssDataToWidget(all->paned->this, "background-color: #CCCEDB"); 
    cssDataToWidget(all->leftFrame, "color : #222;background-color: #DDD");
    cssDataToWidget(all->leftTitre, "color : #444;");
    cssDataToWidget(all->rightFrame, "color : #222;background-color: #DDD");
    cssDataToWidget(all->rightTitre, "color : #444;");
    cssDataToWidget(all->footer->this, "color : #222;background-color: #29a1f2");

    Button_set_image(all->quick->theme,"quick/darkTheme.png");
    StatusBar_empilerMSG(all->theme,"Theme Clair",2);

    all->isDark = FALSE;
  }
  else
  {
    cssDataToWidget(all->console, "color : #DDDDDD;background-color: #1E1E1D;"); 
    cssDataToWidget(all->paned->this, "background-color:#3F3F46"); 
    cssDataToWidget(all->leftFrame, "color : #23D18B;background-color: #252526");
    cssDataToWidget(all->leftTitre, "color : #23D18B");
    cssDataToWidget(all->rightFrame, "color : #23D18B;background-color: #1E1E1D");
    cssDataToWidget(all->rightTitre, "color : #23D18B");
    cssDataToWidget(all->footer->this, "color:#CCC;background-color:#007ACC");

    Button_set_image(all->quick->theme,"quick/lightTheme.png");
    StatusBar_empilerMSG(all->theme,"Theme Sombre",2);

    all->isDark = TRUE;
  }
}

//  BOUTON MODE
void mode_clicked(GtkWidget *widget, gpointer data) {

  All *all = data;

  if(all->isBash == FALSE)
  {
    StatusBar_empilerMSG(all->mode,"Mode Bash",1);
    all->isBash = TRUE;
  }
  else
  {
    
    StatusBar_empilerMSG(all->mode,"Mode Interpreteur",1);
    all->isBash = FALSE;
  }
}