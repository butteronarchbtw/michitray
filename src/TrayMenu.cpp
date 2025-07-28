#include "TrayMenu.hpp"
#include "App.hpp"

#ifndef NGTK
TrayMenu::TrayMenu() { _menu = gtk_menu_new(); }

void TrayMenu::clickEventCb(GtkWidget* widget, gpointer data)
{
    Sound* sound = static_cast<Sound*>(data);
    // FIXME: error handling
    App::getInstance().playSound(sound);
}
#else
TrayMenu::TrayMenu() {}
#endif
