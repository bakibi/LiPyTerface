
void checkUser(GtkWidget *widget, gpointer data);
void start(GtkWidget *widget, gpointer data);


void *connexionPopUp(All *all) {

    Fenetre *f = new_Fenetre("Shanks Connect",NORMAL,new_Taille(800,200),P_CENTER);
    cssDataToWidget(f->this, "color :#DDDDDD;background-color:#252526;");
    all->cnx = f;
    Fenetre_setIcon(f,"logo.png","logo");

    Container *vBox= new_Box(VERTICAL,0, FALSE);
    all->vbox = vBox;
    cssDataToWidget(vBox->this, "color :#DDDDDD;background-color:#252526;");
    f = Fenetre_setContainer(f,vBox);

    Component *label = new_Label("Pseudonyme",0,0);
    cssDataToWidget(label->this,"font-size:30px");

    Component *entry = new_Entry("Ecrivez votre pseudo ici !");
    all->pseudo = entry;
    cssDataToWidget(entry->this,"font-size:30px");

    Component *bouton= new_Button("Valider");
    cssDataToWidget(bouton->this,"font-size:30px;background:#06d6a0;color:#222");

    Component *combo = new_Label("Ecrivez votre pseudo pour voir vos espaces de travail",0,0);
    all->combo=combo;
    cssDataToWidget(combo->this,"font-size:30px;color:#CCC;");

    Component *bouton2= new_Button("Commencer");
    all->commencer= bouton2;
    cssDataToWidget(bouton2->this,"font-size:0px;opacity:0;padding:0px;margin:0px;");

    vBox = Box_addFirst(vBox,label->this,TRUE,TRUE,10);
    vBox = Box_addFirst(vBox,entry->this,FALSE,FALSE,10);
    vBox = Box_addFirst(vBox,bouton->this,TRUE,TRUE,10);
    vBox = Box_addFirst(vBox,combo->this,TRUE,TRUE,10);
    vBox = Box_addFirst(vBox,bouton2->this,TRUE,TRUE,10);

    g_signal_connect(G_OBJECT(bouton->this), "clicked", G_CALLBACK(checkUser), all);
    

    Fenetre_setVisible(f,1);
}

void checkUser(GtkWidget *widget, gpointer data) 
{
    All *all = data;
    const gchar *user = Entry_get_text(all->pseudo);
    gchar *userPath = g_strconcat( "users/" , user , NULL);
    
    if(strcmp(userPath,"users/")==0)  alert_champs_vide(all);
    else 
    {
        GSList *files= NULL;
        DIR *d;
        struct dirent *dir;
        d = opendir(userPath);
        //  si le dossier du user exite deja (user deja existant)
        if (d)
        {
            //  Recuperation de tous les namesSpaces
            GSList *iterator=NULL;

            while ((dir = readdir(d)) != NULL)
                if( strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ) 
                    files = g_slist_append (files, dir->d_name);

            closedir(d);

            //  remove combo and commencer
            gtk_container_remove (GTK_CONTAINER(all->vbox->this), all->combo->this);
            gtk_container_remove (GTK_CONTAINER(all->vbox->this), all->commencer->this);

            all->combo = new_Combo_Box_List(files,0);
            cssDataToWidget(all->combo->this,"font-size:30px");
            
            all->commencer= new_Button("Commencer");
            cssDataToWidget(all->commencer->this,"font-size:30px;background:#2892d7;color:#ccc");
            g_signal_connect(G_OBJECT(all->commencer->this), "clicked", G_CALLBACK(start), all);

            all->vbox = Box_addFirst(all->vbox , all->combo->this, TRUE,TRUE,10);
            all->vbox = Box_addFirst(all->vbox , all->commencer->this, TRUE,TRUE,10);

            //  remove combo and commencer
            gtk_container_remove (GTK_CONTAINER(all->vbox->this), all->combo->this);
            gtk_container_remove (GTK_CONTAINER(all->vbox->this), all->commencer->this);

            all->combo = new_Combo_Box_List(files,0);
            cssDataToWidget(all->combo->this,"font-size:30px");
            
            all->commencer= new_Button("Commencer");
            cssDataToWidget(all->commencer->this,"font-size:30px;background:#2892d7;color:#ccc");
            g_signal_connect(G_OBJECT(all->commencer->this), "clicked", G_CALLBACK(start), all);

            all->vbox = Box_addFirst(all->vbox , all->combo->this, TRUE,TRUE,10);
            all->vbox = Box_addFirst(all->vbox , all->commencer->this, TRUE,TRUE,10);
        }
        //  si le dossier du user n'exite pas (nouveau user)
        else 
        {
            mkdir(userPath,0777);   //  creation du dossier user personnel
            
            //  remove combo and commencer
            gtk_container_remove (GTK_CONTAINER(all->vbox->this), all->combo->this);
            gtk_container_remove (GTK_CONTAINER(all->vbox->this), all->commencer->this);

            all->combo = new_Label("Vous êtes nouveau! Nous vous avons ajouté. Vous pouvez commencer",0,0);
            cssDataToWidget(all->combo->this,"font-size:20px;background:#ffd166;color:#333");
            
            all->commencer= new_Button("Commencer");
            cssDataToWidget(all->commencer->this,"font-size:30px;background:#2892d7;color:#ccc");
            g_signal_connect(G_OBJECT(all->commencer->this), "clicked", G_CALLBACK(start), all);

            all->vbox = Box_addFirst(all->vbox , all->combo->this, TRUE,TRUE,10);
            all->vbox = Box_addFirst(all->vbox , all->commencer->this, TRUE,TRUE,10);
        }
        gtk_widget_show_all(all->cnx->this);
    }
}

void start(GtkWidget *widget, gpointer data) 
{
    All *all = data;
    const gchar *user = Entry_get_text(all->pseudo);
    gchar *userPath = g_strconcat( "users/" , user , NULL);
    
    if(strcmp(userPath,"users/")==0)  alert_champs_vide(all);
    else 
    {
        g_print("\nactive data: %s\n",gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(all->combo->this)));

        gchar *nameSpace = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(all->combo->this));

        //all->userPath = 

        //ApplicationMain(all,userPath,nameSpace);
    }
}
