#include "transparentWindow.h"

void quick_clicked(GtkWidget *widget, gpointer data) {

  Quick *quick = data;

  if(quick->show == FALSE)
  {
   
    //    Showing the options
    gtk_widget_set_opacity(quick->option1->this,1);
    gtk_widget_set_opacity(quick->option2->this,1);
    gtk_widget_set_opacity(quick->option3->this,1);
    //    renaming the plus button and then adding it
    gtk_button_set_label(GTK_BUTTON(quick->plus->this),"MOINS (-)");

    quick->show = TRUE;
  }
  else
  {
    //  hiding the options
    gtk_widget_set_opacity(quick->option1->this,0);
    gtk_widget_set_opacity(quick->option2->this,0);
    gtk_widget_set_opacity(quick->option3->this,0);
    //    renaming the plus button and then adding it
    gtk_button_set_label(GTK_BUTTON(quick->plus->this),"PLUS (+)");

    quick->show = FALSE;
  }
  
  g_print("clicked\n");
}

Fenetre* quick_constructor()
{
    Quick *quick = (Quick*)malloc(sizeof(Quick));
    //  initiation fenetre
    quick->f = new_transparent_fenetre();
    gtk_window_set_keep_above(GTK_WINDOW(quick->f->this), TRUE);
    gtk_window_move (GTK_WINDOW(quick->f->this), 1220, 580);
    //  initation Container
    quick->c = new_Box(VERTICAL,0, FALSE);
    quick->f = Fenetre_setContainer(quick->f,quick->c);

    //  initation bouton add
    quick->plus = new_Button("PLUS (+)");
    //Component *btn = new_Button_image("add.png");
    
    //  initation des options
    quick->option1 = new_Button("Option 1");
    quick->option2 = new_Button("Option 2");
    quick->option3 = new_Button("Option 3");
    //  intition show booleen
    quick->show = FALSE;

    //  adding the plus botton to the box
    Box_addLast(quick->c, quick->plus->this, FALSE, FALSE, 0);
    //    adding the options to the box
    Box_addFirst(quick->c, quick->option1->this, FALSE, FALSE, 0);
    Box_addFirst(quick->c, quick->option2->this, FALSE, FALSE, 0);
    Box_addFirst(quick->c, quick->option3->this, FALSE, FALSE, 0);
    //  hiding the options
    gtk_widget_set_opacity(quick->option1->this,0);
    gtk_widget_set_opacity(quick->option2->this,0);
    gtk_widget_set_opacity(quick->option3->this,0);

     g_signal_connect(G_OBJECT(quick->plus->this), "clicked", 
      G_CALLBACK(quick_clicked), quick);

    return (quick->f);
}

