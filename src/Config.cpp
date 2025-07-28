#include "Config.hpp"
#ifndef NGTK
#include "gtk/gtk.h"
#endif
#include <libconfig.h>
#include <stdexcept>

Config::Config(std::string fileName, TrayMenu* menu)
{
    _fileName = fileName;

    config_t cfg;
    config_init(&cfg);

    if (!config_read_file(&cfg, _fileName.c_str()))
    {
        config_destroy(&cfg);
        throw std::runtime_error("could not read config file");
    }

    // FIXME: better error handling
    config_setting_t* sounds = config_lookup(&cfg, "sounds");
    int count = config_setting_length(sounds);

    for (int i = 0; i < count; ++i)
    {
        config_setting_t* setting = config_setting_get_elem(sounds, i);
        const char* title
            = config_setting_get_string(config_setting_get_elem(setting, 0));
        const char* sound
            = config_setting_get_string(config_setting_get_elem(setting, 1));

        SharedSound sP = std::make_shared<Sound>(sound);
        _registerSound(title, sP, menu);
    }

    config_destroy(&cfg);
}
void Config::_registerSound(std::string title, SharedSound sound,
                            TrayMenu* menu)
{
#ifndef NGTK
    GtkWidget* item = gtk_menu_item_new_with_label(title.c_str());
    g_signal_connect(item, "activate", G_CALLBACK(TrayMenu::clickEventCb),
                     sound.get());
    gtk_menu_shell_append(GTK_MENU_SHELL(menu->menu()), item);
    gtk_widget_show(item);
#endif
    _sounds.push_back(sound);
}
