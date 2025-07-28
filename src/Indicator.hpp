#pragma once

#include "TrayMenu.hpp"
#ifndef NGTK
#include "libayatana-appindicator/app-indicator.h"
#endif

class Indicator
{
  public:
    Indicator();

    void setMenu(const TrayMenu* menu);

  private:
    // FIXME: shared ptr or optional
#ifndef NGTK
    AppIndicator* _ci;
#endif
};
