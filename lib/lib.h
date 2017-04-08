#include <string.h>
#include "SD/Structures.h"
#include "SD/Taille.h"
#include "Prototypes.h"

//Include compososant

char* utf8(char *chaine)
{
    return(g_locale_to_utf8 (chaine,-1,0,0,0));
}


//  CSS
#include "css/cssFunctions.h"
#include "css/animations.h"

//  dialogs 
#include "dialog/dialogs.h"
#include "dialog/interfaceDialogs.h"

// all the Containers
#include "Containers/Container.h"
#include "Containers/Box.h"
#include "Containers/Grid.h"
#include "Containers/FlowBox.h"
#include "Containers/Stack.h"
#include "Containers/Fixed.h"
#include "Containers/Paned.h"



//all the windows
#include "Windows/Fenetre.h"



//all the component
#include "Components/Component.h"
#include "Components/Label.h"
#include "Components/Image.h"
#include "Components/infoBar.h"
#include "Components/statusBar.h"
#include "Components/Button.h"

//  CallBacks

#include "CallBacks/quickCallBacks.h"
#include "CallBacks/rightBodyCallBacks.h"

