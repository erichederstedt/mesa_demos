/*
 * Copyright (C) 2008  Brian Paul   All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * Draw a triangle with X/EGL.
 * Brian Paul
 * 3 June 2008
 */


#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "gl_wrap.h"

#include "eglut.h"


static GLfloat view_rotx = 0.0, view_roty = 0.0, view_rotz = 0.0;


static void
draw(void)
{
   static const GLfloat verts[3][2] = {
      { -1, -1 },
      {  1, -1 },
      {  0,  1 }
   };
   static const GLfloat colors[3][3] = {
      { 1, 0, 0 },
      { 0, 1, 0 },
      { 0, 0, 1 }
   };

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glPushMatrix();
   glRotatef(view_rotx, 1, 0, 0);
   glRotatef(view_roty, 0, 1, 0);
   glRotatef(view_rotz, 0, 0, 1);

   {
      glVertexPointer(2, GL_FLOAT, 0, verts);
      glColorPointer(3, GL_FLOAT, 0, colors);
      glEnableClientState(GL_VERTEX_ARRAY);
      glEnableClientState(GL_COLOR_ARRAY);

      glDrawArrays(GL_TRIANGLES, 0, 3);

      glDisableClientState(GL_VERTEX_ARRAY);
      glDisableClientState(GL_COLOR_ARRAY);
   }

   glPopMatrix();
}


/* new window size or exposure */
static void
reshape(int width, int height)
{
   GLfloat ar = (GLfloat) width / (GLfloat) height;

   glViewport(0, 0, (GLint) width, (GLint) height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-ar, ar, -1, 1, 5.0, 60.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -10.0);
}


static void
init(void)
{
   glClearColor(0.4, 0.4, 0.4, 0.0);
}


static void
special_key(int special)
{
   switch (special) {
   case EGLUT_KEY_LEFT:
      view_roty += 5.0;
      break;
   case EGLUT_KEY_RIGHT:
      view_roty -= 5.0;
      break;
   case EGLUT_KEY_UP:
      view_rotx += 5.0;
      break;
   case EGLUT_KEY_DOWN:
      view_rotx -= 5.0;
      break;
   default:
      break;
   }
   eglutPostRedisplay();
}

int
main(int argc, char *argv[])
{
   eglutInitWindowSize(300, 300);
   eglutInitAPIMask(EGLUT_OPENGL_BIT);
   eglutInit(argc, argv);

   eglutCreateWindow("egltri");

   eglutReshapeFunc(reshape);
   eglutDisplayFunc(draw);
   eglutSpecialFunc(special_key);

   init();

   eglutMainLoop();

   return 0;
}
