/*
 * Copyright (c) 1993-1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * SPDX-License-Identifier: SGI-OpenGL
 */

/*
 *  texprox.c
 *  The brief program illustrates use of texture proxies.
 *  This program only prints out some messages about whether
 *  certain size textures are supported and then exits.
 */
#include "glut_wrap.h"
#include <stdlib.h>
#include <stdio.h>

/* Microsoft OpenGL 1.1's <GL/gl.h> forgets to define
   GL_TEXTURE_INTERNAL_FORMAT. */
#ifndef GL_TEXTURE_INTERNAL_FORMAT
#define GL_TEXTURE_INTERNAL_FORMAT GL_TEXTURE_COMPONENTS
#endif

static void init(void)
{
   GLint proxyComponents;

   putchar('\n');

   glTexImage2D(GL_PROXY_TEXTURE_2D, 0, GL_RGBA8,
                64, 64, 0,
                GL_RGBA, GL_UNSIGNED_BYTE, NULL);
   glGetTexLevelParameteriv(GL_PROXY_TEXTURE_2D, 0,
                            GL_TEXTURE_INTERNAL_FORMAT, &proxyComponents);
   printf ("Proxying 64x64 level 0 RGBA8 texture (level 0)\n");
   if (proxyComponents == GL_RGBA8)
      printf ("proxy allocation succeeded\n");
   else
      printf ("proxy allocation failed\n");
   putchar('\n');

   glTexImage2D(GL_PROXY_TEXTURE_2D, 0, GL_RGBA16,
                2048, 2048, 0,
                GL_RGBA, GL_UNSIGNED_SHORT, NULL);
   glGetTexLevelParameteriv(GL_PROXY_TEXTURE_2D, 0,
                            GL_TEXTURE_INTERNAL_FORMAT, &proxyComponents);
   printf ("Proxying 2048x2048 level 0 RGBA16 texture (big so unlikely to be supported)\n");
   if (proxyComponents == GL_RGBA16)
      printf ("proxy allocation succeeded\n");
   else
      printf ("proxy allocation failed\n");
   putchar('\n');
}

static void display(void)
{
   exit(0);
}

static void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
