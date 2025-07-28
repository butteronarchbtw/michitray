#include "Indicator.hpp"

#ifndef NGTK
#ifndef APP_IS_INDICATOR
#define APP_IS_INDICATOR(obj)                                                  \
    (G_TYPE_CHECK_INSTANCE_TYPE((obj), APP_INDICATOR_TYPE))
#endif
#endif

Indicator::Indicator()
{
#ifndef NGTK
    _ci = app_indicator_new("michitray-client", "audio-card",
                            APP_INDICATOR_CATEGORY_APPLICATION_STATUS);

    // FIXME: idk about these asserts
    g_assert(APP_IS_INDICATOR(_ci));
    g_assert(G_IS_OBJECT(_ci));

    app_indicator_set_status(_ci, APP_INDICATOR_STATUS_ACTIVE);
    app_indicator_set_title(_ci, "michitray");
#endif
}

void Indicator::setMenu(const TrayMenu* menu)
{
#ifndef NGTK
    app_indicator_set_menu(_ci, GTK_MENU(menu->menu()));
#endif
}
