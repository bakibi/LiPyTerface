# Create Workspace & Gtk directories if not exist
mkdir -p ~/Workspace/Gtk
#delete the old LiPyTerface direcory project if exists
rm -rf ~/Workspace/Gtk/LiPyTerface
#copy the new LiPyTerface direcory
cp -avr ../LiPyTerface ~/Workspace/Gtk

#go to the new LiPyTerface project direcory (drag and drop if you're using VS Code)

#now you're ready to compile or run the program
