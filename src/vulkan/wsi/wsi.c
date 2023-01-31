/*
 * Copyright © 2023 Collabora Ltd
 *
 * SPDX-License-Identifier: MIT
 */

#include "wsi.h"

#include <stdlib.h>

struct wsi_interface
get_wsi_interface(void)
{
#if defined(METAL_SUPPORT) && defined(XCB_SUPPORT)
   return getenv("USE_X11") ? xcb_wsi_interface() :
                              metal_wsi_interface();
#elif defined(WAYLAND_SUPPORT) && defined(XCB_SUPPORT)
   return getenv("WAYLAND_DISPLAY") ? wayland_wsi_interface() :
                                      xcb_wsi_interface();
#elif defined(WAYLAND_SUPPORT)
   return wayland_wsi_interface();
#elif defined(XCB_SUPPORT)
   return xcb_wsi_interface();
#elif defined(METAL_SUPPORT)
   return metal_wsi_interface();
#elif defined(WIN32_SUPPORT)
   return win32_wsi_interface();
#endif
}
