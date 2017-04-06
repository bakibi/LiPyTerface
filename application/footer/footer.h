Container* footer_constructor(All *all)
{
    Component *lnCol = all->lnCol;

    Container *footer = all->footer;
    cssDataToWidget(footer->this, "color:#CCC;background-color:#007ACC;font:Bold 10px");
    
    Component *mode = new_StatusBar();
    mode = StatusBar_empilerMSG(mode,"Mode Interpreteur",1);
    all->mode=mode;

    Component *fileName = new_StatusBar();
    fileName = StatusBar_empilerMSG(fileName,"Current File Name",2);
    all->fileName=fileName;
    
    lnCol = StatusBar_empilerMSG(lnCol,"Ln 0 | Col 0",3);

    Box_addFirst(footer, mode->this    , TRUE, FALSE, 0);
    Box_addFirst(footer, fileName->this , TRUE, FALSE, 0);
    Box_addLast(footer, lnCol->this     , TRUE, FALSE, 0);
    
    return( footer );
}


