
Container* top_bodyBash(All *all)
{
    //  creation du frame
    Container *top = new_Frame("  Editeur de Texte  ",20);
    all->topFrame=top->this;
    cssDataToWidget(top->this, "color : #23D18B;background-color: #1E1E1D;margin:30px;");

    //  edition du titre
    GtkWidget *titre = Frame_get_label(top);
    all->topTitre=titre;
    cssDataToWidget(titre, "color : #23D18B;font-size:30px;font-weight:bolder;");

    //  Creation Scroll Container
    Container *scrolled_editor = new_Scroll(10);

    //  Creation de l'editeur
    Component *editor = new_TextView(TRUE);
    all->editor=editor->this;
    cssDataToWidget(editor->this, "color : #DDDDDD;background-color: #1E1E1D;");

    //  Recuperer Le buffer
    GtkTextBuffer *buffer = TextView_get_buffer(editor);

    //  Recuperer Le buffer l'iter sur la premiere position
    GtkTextIter iter =  TextView_get_iter(editor, 0, 0);

    //  Creation des couleurs
    TextView_create_fg_color(editor,"blue");
    TextView_create_fg_color(editor,"black");
    TextView_create_bg_color(editor,"lightgray");

    //  Ajout de l'editeur au Scroll Container
    scrolled_editor = Scroll_add(scrolled_editor,editor->this);
    
    //  Ajout du Scroll Container Au Top Frame Container
    top = Frame_add(top,scrolled_editor->this);

    //  SIGNAUX
    g_signal_connect(buffer, "changed",G_CALLBACK(syntaxHighlight_keyWords_editor), all);
    g_signal_connect(buffer, "mark_set", G_CALLBACK(mark_set_callback), all);

    return(top);
}