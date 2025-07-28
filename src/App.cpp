#include "App.hpp"
#include <libconfig.h>
#include <stdexcept>

int App::playSound(Sound* sound)
{
    ma_result res
        = ma_engine_play_sound(_engine, sound->name().c_str(), nullptr);
    return res;
}

App::App()
{
    _engine = new ma_engine;
    // FIXME:
    //     check errors
    ma_result res = ma_engine_init(nullptr, _engine);
    if (res != MA_SUCCESS)
    {
        throw std::runtime_error("could not initialize miniaudio engine");
    }
}

App::~App()
{

    ma_engine_uninit(_engine);
    delete _engine;
    // INFO: even better example on why to use shared ptr
    if (_config != nullptr)
    {
        delete _config;
    }
    if (_menu != nullptr)
    {
        delete _menu;
    }
}

void App::initConfig(std::string configFile)
{
    if (_menu == nullptr)
    {
        throw std::runtime_error("initConfig called without initMenu first");
    }
    _config = new Config(configFile, _menu);
}

void App::initMenu()
{
    _menu = new TrayMenu;
    _indicator.setMenu(_menu);
}
