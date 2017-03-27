

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "lib/lib.h"
#include "application/applicationMain.h"



int main(int argc , char** args)
{
    gtk_init(&argc,&args);
    ApplicationMain();
    gtk_main();

    return 0;
}
