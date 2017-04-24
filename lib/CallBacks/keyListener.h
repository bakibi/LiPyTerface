
void keyListener_pressed(GtkWidget *widget,GdkEventKey *event, gpointer data)
{
    All *all=data;
    gchar *key_name = gdk_keyval_name(event->keyval);
    int key_code = gdk_keyval_from_name(key_name);

   //  si on travail sur la console
    if(gtk_widget_has_focus (all->console))
    {
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->console));

        GtkTextIter iter;
        gtk_text_buffer_get_iter_at_mark(buffer, &iter, gtk_text_buffer_get_insert(buffer));
    
        //si on tape la fleche de haut --> monter l'historique
        if(key_code==65362)
        {
            //  selectionner la commande actuelle
            GtkTextIter start_cmd, end_cmd;
            gtk_text_buffer_get_iter_at_mark(buffer, &start_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_buffer_get_iter_at_mark(buffer, &end_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_iter_set_line (&start_cmd, -1);
            gtk_text_iter_set_line_offset (&start_cmd,16);
            gtk_text_iter_forward_to_end (&end_cmd);
            //effacer commande actuel
            gtk_text_buffer_delete (buffer,&start_cmd,&end_cmd);
            //  BLOCKER le curseur de bouger
            gtk_text_iter_forward_to_end (&end_cmd);
            gtk_text_buffer_place_cursor (GTK_TEXT_BUFFER(buffer), &end_cmd );
            //ajouter la cmd de l'historique selon le rang
            gtk_text_iter_forward_to_end (&end_cmd);
            gtk_text_buffer_place_cursor (GTK_TEXT_BUFFER(buffer), &end_cmd );
            if(all->histo.rang_actuel>-1)
                gtk_text_buffer_insert( buffer, &end_cmd, all->histo.cmd[all->histo.rang_actuel+1], -1);
            else
                all->histo.rang_actuel=18;
        }
         //si on tape la fleche de bas --> descendre l'historique
        else if(key_code==65364)
        {
            //  selectionner la commande actuelle
            GtkTextIter start_cmd, end_cmd;
            gtk_text_buffer_get_iter_at_mark(buffer, &start_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_buffer_get_iter_at_mark(buffer, &end_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_iter_set_line (&start_cmd, -1);
            gtk_text_iter_set_line_offset (&start_cmd,16);
            gtk_text_iter_forward_to_end (&end_cmd);
            //effacer commande actuel
            gtk_text_buffer_delete (buffer,&start_cmd,&end_cmd);
            //  BLOCKER le curseur de bouger
            gtk_text_iter_forward_to_end (&end_cmd);
            gtk_text_buffer_place_cursor (GTK_TEXT_BUFFER(buffer), &end_cmd );
            //ajouter la cmd de l'historique selon le rang
            gtk_text_iter_forward_to_end (&end_cmd);
            gtk_text_buffer_place_cursor (GTK_TEXT_BUFFER(buffer), &end_cmd );
            if(all->histo.rang_actuel<19)
                gtk_text_buffer_insert( buffer, &end_cmd, all->histo.cmd[all->histo.rang_actuel+1], -1);
        }    
	    //si on est sur la derniere ligne
        else if(gtk_text_iter_is_end (&iter))
        {
            all->histo.rang_actuel=18;
            int col = gtk_text_iter_get_line_offset(&iter);
		    //si on efface
            if ( g_strcmp0(key_name, "BackSpace")==0 && col == 16 ) 
                gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);
            else 
                gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),TRUE);
        }
    }

}

void keyListener_releassed(GtkWidget *widget,GdkEventKey *event, gpointer data)
{
    All *all=data;
    gchar *key_name = gdk_keyval_name(event->keyval);
    int key_code = gdk_keyval_from_name(key_name);

    //  si on travail sur la console
    if(gtk_widget_has_focus (all->console))
    {
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->console));

        GtkTextIter iter;
        gtk_text_buffer_get_iter_at_mark(buffer, &iter, gtk_text_buffer_get_insert(buffer));

        //si on tape la fleche de haut --> monter l'historique
        if(key_code==65362)
        {
            //  selectionner la commande actuelle
            GtkTextIter start_cmd, end_cmd;
            gtk_text_buffer_get_iter_at_mark(buffer, &start_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_buffer_get_iter_at_mark(buffer, &end_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_iter_set_line (&start_cmd, -1);
            gtk_text_iter_set_line_offset (&start_cmd,16);
            gtk_text_iter_forward_to_end (&end_cmd);
            //effacer commande actuel
            gtk_text_buffer_delete (buffer,&start_cmd,&end_cmd);
            //  BLOCKER le curseur de bouger
            gtk_text_iter_forward_to_end (&end_cmd);
            gtk_text_buffer_place_cursor (GTK_TEXT_BUFFER(buffer), &end_cmd );
            //ajouter la cmd de l'historique selon le rang
            gtk_text_iter_forward_to_end (&end_cmd);
            gtk_text_buffer_place_cursor (GTK_TEXT_BUFFER(buffer), &end_cmd );
            if(all->histo.rang_actuel>-1)
                gtk_text_buffer_insert( buffer, &end_cmd, all->histo.cmd[all->histo.rang_actuel--], -1);
            else
                all->histo.rang_actuel=18;
        }
        //si on tape la fleche de bas --> descendre l'historique
        else if(key_code==65364)
        {
            //  selectionner la commande actuelle
            GtkTextIter start_cmd, end_cmd;
            gtk_text_buffer_get_iter_at_mark(buffer, &start_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_buffer_get_iter_at_mark(buffer, &end_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_iter_set_line (&start_cmd, -1);
            gtk_text_iter_set_line_offset (&start_cmd,16);
            gtk_text_iter_forward_to_end (&end_cmd);
            //effacer commande actuel
            gtk_text_buffer_delete (buffer,&start_cmd,&end_cmd);
            //  BLOCKER le curseur de bouger
            gtk_text_iter_forward_to_end (&end_cmd);
            gtk_text_buffer_place_cursor (GTK_TEXT_BUFFER(buffer), &end_cmd );
            //ajouter la cmd de l'historique selon le rang
            gtk_text_iter_forward_to_end (&end_cmd);
            gtk_text_buffer_place_cursor (GTK_TEXT_BUFFER(buffer), &end_cmd );
            if(all->histo.rang_actuel<19)
                gtk_text_buffer_insert( buffer, &end_cmd, all->histo.cmd[all->histo.rang_actuel++], -1);
        }
	    //si on est sur la derniere ligne
        else if(gtk_text_iter_is_end (&iter))
        {
            all->histo.rang_actuel=18;
	        //si on fait un retour chariot
            if(g_strcmp0(key_name, "Return")==0)
            {   
                //retourner la cmd saisie
                gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);
                g_print("\n> %s\n",retourner_commande(buffer));
                //  MAJ de l'historique
                for(int i=0;i<19;i++)
                    strcpy( all->histo.cmd[i] ,all->histo.cmd[i+1]);
                strcpy( all->histo.cmd[19] ,retourner_commande(buffer));
                //  preparer la nouvelle ligne
                gboolean cmd_complete=TRUE;
                if(cmd_complete)
                    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\nilisi@shanks:~# ", -1, "orange_fg", NULL);
                else
                    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n           ---> ", -1, "orange_fg", NULL);
            }
		//si on efface
            else if ( g_strcmp0(key_name, "BackSpace")==0 && gtk_text_iter_get_line_offset(&iter) == 16 ) 
                gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);
            else 
                gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),TRUE);
        }   
    }
}
