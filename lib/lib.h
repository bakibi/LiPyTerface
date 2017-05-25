#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

#include "include/include.h"

#include "SD/Structures.h"
#include "SD/Taille.h"

#include "Prototypes.h"


//  fonctions aide
#include "fonctions_aide.h"

//  CSS
#include "css/cssFunctions.h"
#include "css/animations.h"

//  Historique
#include "historique.h"

//  dialogs 
#include "dialog/alerts.h"
#include "dialog/dialogs.h"
#include "dialog/interfaceDialogs.h"
#include "dialog/menuDialogs.h"

//  Containers

#include "Containers/Container.h"
#include "Containers/Box.h"
#include "Containers/Grid.h"
#include "Containers/FlowBox.h"
#include "Containers/Stack.h"
#include "Containers/Fixed.h"
#include "Containers/Paned.h"
#include "Containers/Frame.h"
#include "Containers/Scroll.h"

//all the windows
#include "Windows/Fenetre.h"

//all the component
#include "Components/Component.h"
#include "Components/Label.h"
#include "Components/Image.h"
#include "Components/infoBar.h"
#include "Components/statusBar.h"
#include "Components/Button.h"
#include "Components/TextView.h"
#include "Components/Entry.h"
#include "Components/ComboBox.h"
#include "Components/CheckBox.h"
#include "Components/Radio.h"

//  CallBacks
#include "CallBacks/quickCallBacks.h"
#include "CallBacks/rightBodyCallBacks.h"
#include "CallBacks/keyListener.h"
#include "CallBacks/syntaxHighlight.h"


//  Accelerators
#include "accelerators.h"
