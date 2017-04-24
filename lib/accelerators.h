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
  }
}
