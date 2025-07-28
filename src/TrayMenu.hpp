#pragma once

#ifndef NGTK
#include "gtk/gtk.h"
#endif

class TrayMenu
{

  public:
    TrayMenu();
#ifndef NGTK
    GtkWidget* menu() const { return _menu; }

    static void clickEventCb(GtkWidget* widget, gpointer data);
#endif

  private:
#ifndef NGTK
    GtkWidget* _menu = nullptr;
#endif
};
