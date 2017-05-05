
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
             //  si on est dans une commande en cours
            if(all->cmd_encours)
                gtk_text_iter_set_line_offset (&start_cmd,5);
            else
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
                all->histo.rang_actuel=19;
        }
         //si on tape la fleche de bas --> descendre l'historique
        else if(key_code==65364)
        {
             //  selectionner la commande actuelle
            GtkTextIter start_cmd, end_cmd;
            gtk_text_buffer_get_iter_at_mark(buffer, &start_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_buffer_get_iter_at_mark(buffer, &end_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_iter_set_line (&start_cmd, -1);
             //  si on est dans une commande en cours
            if(all->cmd_encours)
                gtk_text_iter_set_line_offset (&start_cmd,5);
            else
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
            all->histo.rang_actuel=19;
            int col = gtk_text_iter_get_line_offset(&iter);
		    //si on efface avec commande en cours
            if ( g_strcmp0(key_name, "BackSpace")==0 && all->cmd_encours!=NULL &&
                        gtk_text_iter_get_line_offset(&iter) == 5 ) 
                gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);
            //si on efface sans commande en cours
            else if ( g_strcmp0(key_name, "BackSpace")==0 && all->cmd_encours==NULL &&
                        gtk_text_iter_get_line_offset(&iter) == 16 ) 
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
             //  si on est dans une commande en cours
            if(all->cmd_encours)
                gtk_text_iter_set_line_offset (&start_cmd,5);
            else
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
                all->histo.rang_actuel=19;
        }
        //si on tape la fleche de bas --> descendre l'historique
        else if(key_code==65364)
        {
             //  selectionner la commande actuelle
            GtkTextIter start_cmd, end_cmd;
            gtk_text_buffer_get_iter_at_mark(buffer, &start_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_buffer_get_iter_at_mark(buffer, &end_cmd, gtk_text_buffer_get_insert(buffer));
            gtk_text_iter_set_line (&start_cmd, -1);
             //  si on est dans une commande en cours
            if(all->cmd_encours)
                gtk_text_iter_set_line_offset (&start_cmd,5);
            else
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
	    //si on est sur la derniere ligne et on pas touché les touche HAUT ou BAS
        else if(gtk_text_iter_is_end (&iter))
        {
            //  reintialiser l'indice initial de l'historique
            all->histo.rang_actuel=19;
            
            //CTRL + ENTRER = Retour ligne commande non complete
            if ( (event->type == GDK_KEY_PRESS)      &&
                 (event->state & GDK_CONTROL_MASK)   &&
                 ( g_strcmp0(key_name, "Return")==0  || key_code==65421   ) )
            {
                gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);

                //  premiere fois ctrl + entrer
                if(all->cmd_encours == NULL)
                {
                    //  MAJ de l'historique
                    for(int i=0;i<19;i++)
                        strcpy( all->histo.cmd[i] ,all->histo.cmd[i+1]);
                    strcpy( all->histo.cmd[19] ,retourner_commande(buffer));

                    g_print("\ncmd@incomplete> %s\n",retourner_commande(buffer));
                    all->cmd_encours = g_strconcat( retourner_commande(buffer), NULL);
                    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n\n---> ", -1, "#00B5FF_fg", NULL);

                    
                }
                //  on est deja dans l'etat d'une commande nn complete
                else
                {
                    //  MAJ de l'historique
                    for(int i=0;i<19;i++)
                        strcpy( all->histo.cmd[i] ,all->histo.cmd[i+1]);
                    strcpy( all->histo.cmd[19] ,retourner_commande_non_complete(buffer));

                    g_print("\ncmd@incomplete> %s\n",retourner_commande_non_complete(buffer));
                    all->cmd_encours = g_strconcat(all->cmd_encours, retourner_commande_non_complete(buffer), NULL);
                    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n---> ", -1, "#00B5FF_fg", NULL);
                }
            }

            //si on fait un retour chariot
            else if(g_strcmp0(key_name, "Return")==0 || key_code==65421)
            {   
                gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);
                //  si il y a une cmd en cours 
                if(all->cmd_encours)
                {
                     //  MAJ de l'historique
                    for(int i=0;i<19;i++)
                        strcpy( all->histo.cmd[i] ,all->histo.cmd[i+1]);
                    strcpy( all->histo.cmd[19] ,retourner_commande_non_complete(buffer));

                    all->cmd_encours = g_strconcat(all->cmd_encours, retourner_commande_non_complete(buffer), NULL);
                    g_print("\ncmd@complete> %s\n",all->cmd_encours);
                    //  pas de cmd en cours maintenant
                    all->cmd_encours=NULL;

                    //  preparer la nouvelle ligne
                    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n\nilisi@shanks:~# ", -1, "orange_fg", NULL);

                }
                //  pas de cmd en cours
                else
                {
                    //  MAJ de l'historique
                    for(int i=0;i<19;i++)
                        strcpy( all->histo.cmd[i] ,all->histo.cmd[i+1]);
                    strcpy( all->histo.cmd[19] ,retourner_commande(buffer));

                    //retourner la cmd saisie
                    g_print("\ncmd@complete> %s\n",retourner_commande(buffer));

                    //  preparer la nouvelle ligne
                    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\nilisi@shanks:~# ", -1, "orange_fg", NULL);
                }
            }
		    //si on efface avec commande en cours
            else if ( g_strcmp0(key_name, "BackSpace")==0 && all->cmd_encours!=NULL &&
                        gtk_text_iter_get_line_offset(&iter) == 5 ) 
                gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);
            //si on efface sans commande en cours
            else if ( g_strcmp0(key_name, "BackSpace")==0 && all->cmd_encours==NULL &&
                        gtk_text_iter_get_line_offset(&iter) == 16 ) 
                gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);
            else 
                gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),TRUE);
        }   
    }
}
