#pragma once

#include "Sound.hpp"
#include "TrayMenu.hpp"
#include <vector>

class Config
{
  public:
    Config() = delete;
    Config(std::string fileName, TrayMenu* menu);

  private:
    std::vector<SharedSound> _sounds;
    void _registerSound(std::string title, SharedSound sound, TrayMenu* menu);
    std::string _fileName;
};
