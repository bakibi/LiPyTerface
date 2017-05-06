Container* right_body(All *all)
{
    //  creation du frame
    Container *right = new_Frame("  Console  ",10);
    all->rightFrame=right->this;
    cssDataToWidget(right->this, "color : #23D18B;background-color: #1E1E1D;padding:10px;");

    //  edition du titre
    GtkWidget *titre = Frame_get_label(right);
    all->rightTitre=titre;
    cssDataToWidget(titre, "color : #0098FF;font-size:30px;font-weight:bolder;");
    
    //  Creation Scroll Container
    Container *scrolled_console = new_Scroll(10);

    //  Creation de la console
    Component *console = new_TextView(TRUE);
    all->console_comp = console;
    all->console=console->this;
    cssDataToWidget(console->this, "color : #DDDDDD;background-color: #1E1E1D;");

    //  Recuperer Le buffer
    GtkTextBuffer *buffer = TextView_get_buffer(console);
    
    //  Recuperer Le buffer l'iter sur la premiere position
    GtkTextIter iter =  TextView_get_iter(console, 0, 0);

    //  Creation des couleurs
    TextView_create_fg_color(console,"red");
    TextView_create_fg_color(console,"#00B5FF");
    TextView_create_fg_color(console,"#0EAF47");
    TextView_create_fg_color(console,"orange");
    TextView_create_fg_color(console,"black");
    TextView_create_fg_color(console,"brown");
    TextView_create_bg_color(console,"lightgray");

    //  Afficher Message d'acceuil
    TextView_insert_text(console,iter, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tBienvenue à Shanks v2.8 ! \n\n"
                                      "\t\t\t\t\tVous êtes sur le mode Interpreteur cela vous permet de réaliser"
                                      " votre application ou de faire des traitement rapide\n \t\t\t\t\t\t\t"
                                      "en écrivant votre code ShankScript commande par commande et de "
                                      "voir le résultat immédiatement \n\n",
                                      "brown_fg");

    //  Insertion du premier prefixe console en orange
    iter = TextView_get_iter_end(console);
    TextView_insert_text(console,iter,"ilisi@shanks:~# ","#00B5FF_fg");
    
    //  Ajout de la Console au Scroll Container
    scrolled_console = Scroll_add(scrolled_console,console->this);
    
    //  Ajout du Scroll Container Au Right Frame Container
    right = Frame_add(right,scrolled_console->this);

    //  SIGNAUX
    //g_signal_connect(buffer, "changed",G_CALLBACK(update_lnCol), all->lnCol->this);
    g_signal_connect(buffer, "mark_set", G_CALLBACK(mark_set_callback), all);

    return(right);
}