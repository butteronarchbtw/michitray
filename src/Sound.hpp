#pragma once

#include <memory>
#include <string>

class Sound
{
  public:
    Sound(std::string name) : _name(name) {}
    std::string name() const { return _name; }

  private:
    std::string _name;
};

using SharedSound = std::shared_ptr<Sound>;
