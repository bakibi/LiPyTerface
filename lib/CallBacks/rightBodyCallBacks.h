void update_lnCol(GtkTextBuffer *buffer,
                  GtkStatusbar *lnCol) {
    gchar *msg;
    gint row, col;
    GtkTextIter iter,iter_suiv;
    
    //    update status bar
    gtk_statusbar_pop(lnCol, 3); 
    gtk_text_buffer_get_iter_at_mark(buffer, &iter, gtk_text_buffer_get_insert(buffer));
    row = gtk_text_iter_get_line(&iter);
    col = gtk_text_iter_get_line_offset(&iter);
    msg = g_strdup_printf("Ln %d | Col %d", row+1, col+1);
    gtk_statusbar_push(lnCol, 3, msg);
    g_free(msg);

    //    remove selection
    GtkTextIter start_find, end_find;
    gtk_text_buffer_get_start_iter(buffer, &start_find);
    gtk_text_buffer_get_end_iter(buffer, &end_find);
    gtk_text_buffer_remove_tag_by_name(buffer, "gray_bg",&start_find, &end_find);  
    gtk_text_buffer_remove_tag_by_name(buffer, "black_fg",&start_find, &end_find);

    //    colorer curseur
    iter_suiv = iter;
    gtk_text_iter_forward_char (&iter_suiv);
    gtk_text_buffer_apply_tag_by_name(buffer, "gray_bg",&iter, &iter_suiv);
    gtk_text_buffer_apply_tag_by_name(buffer, "black_fg",&iter, &iter_suiv);
}

void mark_set_callback(GtkTextBuffer *buffer, 
    const GtkTextIter *new_location, GtkTextMark *mark, gpointer data) {

    All *all=data;
    GtkTextIter iter,lastLine;

    gtk_text_buffer_get_iter_at_mark(buffer, &iter, gtk_text_buffer_get_insert(buffer));
    gtk_text_buffer_get_iter_at_mark(buffer, &lastLine, gtk_text_buffer_get_insert(buffer));
    gtk_text_iter_set_line (&lastLine, -1);

    if( gtk_text_iter_get_line (&iter) != gtk_text_iter_get_line (&lastLine) )
        gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);
    else
        if(gtk_text_iter_get_line_offset (&iter)<16)
            gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);
        else
            gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),TRUE);
                       
    update_lnCol(buffer, GTK_STATUSBAR(all->lnCol->this));
}

