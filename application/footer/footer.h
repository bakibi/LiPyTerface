Container* footer_constructor(All *all)
{
    Component *lnCol = all->lnCol;

    Container *footer = all->footer;
    cssDataToWidget(footer->this, "color:#CCC;background-color:#007ACC;font:Bold 10px");
    
    Component *mode = new_StatusBar();
    mode = StatusBar_empilerMSG(mode,"Mode Interpreteur",1);
    all->mode=mode;

    Component *theme = new_StatusBar();
    theme = StatusBar_empilerMSG(theme,"Theme : Sombre",2);
    all->theme=theme;
    
    lnCol = StatusBar_empilerMSG(lnCol,"Ln 0 | Col 0",3);

    Box_addFirst(footer, mode->this    , TRUE, FALSE, 0);
    Box_addFirst(footer, theme->this , TRUE, FALSE, 0);
    Box_addLast(footer, lnCol->this     , TRUE, FALSE, 0);
    
    return( footer );
}


