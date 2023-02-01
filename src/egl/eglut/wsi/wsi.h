/*
 * Copyright © 2023 Hoe Hao Cheng
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef WSI_H_
#define WSI_H_

#include <stdbool.h>

struct eglut_window;

struct eglut_wsi_interface {
   void (*init_display)();
   void (*fini_display)();

   void (*init_window)(struct eglut_window *win, const char *title,
                       int x, int y, int w, int h);
   void (*event_loop)();
   void (*fini_window)(struct eglut_window *win);
};

#ifdef WAYLAND_SUPPORT
struct eglut_wsi_interface
wayland_wsi_interface(void);
#endif

#ifdef X11_SUPPORT
struct eglut_wsi_interface
x11_wsi_interface(void);
#endif

struct eglut_wsi_interface
_eglutGetWindowSystemInterface(void);

#endif /* WSI_H_ */
