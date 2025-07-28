#pragma once

#include "Config.hpp"
#include "Indicator.hpp"
#include "Sound.hpp"
#include "TrayMenu.hpp"
#include "miniaudio.h"
#include <string>

class App
{
  public:
    App();

    static App& getInstance()
    {
        static App instance;
        return instance;
    }

    App(const App&) = delete;
    void operator=(const App&) = delete;

    ~App();

    void initConfig(std::string configFile);
    void initMenu();

    ma_engine* engine() const { return _engine; }

    int playSound(Sound* sound);

  private:
    // FIXME: shared ptr or std::optional
    Config* _config;
    Indicator _indicator;
    TrayMenu* _menu;
    ma_engine* _engine;
};
