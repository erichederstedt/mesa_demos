/*
 * Mesa 3-D graphics library
 * Version:  7.9
 *
 * Copyright (C) 2010 LunarG Inc.
 *
 * SPDX-License-Identifier: MIT
 *
 * Authors:
 *    Chia-I Wu <olv@lunarg.com>
 */

/*
 * This demo tests eglGetProcAddress and glClear.
 */

#include <stdlib.h>
#include <stdio.h>
#include <EGL/egl.h>
#include <GLES/gl.h>

#include "eglut.h"

typedef void (GL_APIENTRY *type_ClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (GL_APIENTRY *type_Clear)(GLbitfield mask);

static type_ClearColor fn_ClearColor;
static type_Clear fn_Clear;

static void
draw(void)
{
   fn_Clear(GL_COLOR_BUFFER_BIT);
}

static void *
get_proc(const char *name)
{
   void *proc;

   proc = (void *) eglGetProcAddress(name);
   if (!proc) {
      /*
       * note that eglGetProcAddress is not required to support non-extension
       * functions
       */
      printf("failed to find %s (not necessarily a bug)\n", name);
      exit(1);
   }

   return proc;
}

static void
init(void)
{
   fn_ClearColor = (type_ClearColor) get_proc("glClearColor");
   fn_Clear = (type_Clear) get_proc("glClear");

   fn_ClearColor(1.0, 0.4, 0.4, 0.0);
}

int
main(int argc, char *argv[])
{
   eglutInitWindowSize(300, 300);
   eglutInitAPIMask(EGLUT_OPENGL_ES1_BIT);
   eglutInit(argc, argv);

   eglutCreateWindow("clear");

   eglutDisplayFunc(draw);

   init();

   eglutMainLoop();

   return 0;
}
