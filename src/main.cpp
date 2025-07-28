#define MINIAUDIO_IMPLEMENTATION

#include "App.hpp"
#include <iostream>
#include <miniaudio.h>

#include <gtk/gtk.h>
#include <libayatana-appindicator/app-indicator.h>

// TODO:
//  - split into files
//  - split into more classes
//  - testable library
//  - tests
//  - spdlog
//  - remove some deps
//  - docs
//  - memory usage?

static void quitGtk(int s) { gtk_main_quit(); }

int main(int argc, char** argv)
{

    if (argc != 2)
    {
        return 1;
    }

    const char* filename = argv[1];

    gtk_init(&argc, &argv);

    App& app = App::getInstance();
    app.initMenu();

    app.initConfig(filename);

    signal(SIGINT, &quitGtk);
    signal(SIGTERM, &quitGtk);
    gtk_main();

    return 0;
}
