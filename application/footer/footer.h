Container* footer_constructor()
{

    Container *footer = new_Box(HORIZENTAL, 0, FALSE);
    ALL_setBackgroundColor(footer->this,0 , 0.478, 0.8, 1);
    ALL_setForegroundColor(footer->this,0.8, 0.8, 0.8, 1);
    
    Component *mode = new_StatusBar();
    mode = StatusBar_empilerMSG(mode,"Mode Interpreteur",1);
    gtk_widget_override_font(GTK_WIDGET(mode->this) ,pango_font_description_from_string("Bold 10"));

    Component *fileName = new_StatusBar();
    fileName = StatusBar_empilerMSG(fileName,"Current File Name",2);
    gtk_widget_override_font(GTK_WIDGET(fileName->this) ,pango_font_description_from_string("Bold 10"));

    Component *lnCol = new_StatusBar();
    lnCol = StatusBar_empilerMSG(lnCol,"Ln 70 / Col 32",3);
    gtk_widget_override_font(GTK_WIDGET(lnCol->this) ,pango_font_description_from_string("Bold 10"));

    Box_addFirst(footer, mode->this    , TRUE, FALSE, 0);
    Box_addFirst(footer, fileName->this , TRUE, FALSE, 0);
    Box_addLast(footer, lnCol->this     , TRUE, FALSE, 0);
    
    return( footer );
}


