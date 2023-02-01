/*
 * Copyright © 2023 Hoe Hao Cheng
 *
 * SPDX-License-Identifier: MIT
 */

#include "eglutint.h"
#include "wsi.h"

#include <stdlib.h>

struct eglut_wsi_interface
_eglutGetWindowSystemInterface(void)
{
#if defined(WAYLAND_SUPPORT) && defined(X11_SUPPORT)
   const char *wayland_dpy = getenv("WAYLAND_DISPLAY");
   return wayland_dpy && *wayland_dpy ? wayland_wsi_interface() :
                                        x11_wsi_interface();
#elif defined(WAYLAND_SUPPORT)
   return wayland_wsi_interface();
#elif defined(X11_SUPPORT)
   return x11_wsi_interface();
#endif
}

void
_eglutNativeInitDisplay(void)
{
   _eglut->wsi.init_display();
}

void
_eglutNativeFiniDisplay(void)
{
   _eglut->wsi.fini_display();
}

void
_eglutNativeInitWindow(struct eglut_window *win, const char *title,
                       int x, int y, int w, int h)
{
   _eglut->wsi.init_window(win, title, x, y, w, h);
}

void
_eglutNativeFiniWindow(struct eglut_window *win)
{
   _eglut->wsi.fini_window(win);
}

void
_eglutNativeEventLoop(void)
{
   _eglut->wsi.event_loop();
}
