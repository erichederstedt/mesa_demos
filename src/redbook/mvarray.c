/*
 * Copyright (c) 1993-2003, Silicon Graphics, Inc.
 * All Rights Reserved
 *
 * SPDX-License-Identifier: SGI-OpenGL
 */

/*
 *  mvarray.c
 *  This program demonstrates multiple vertex arrays,
 *  specifically the OpenGL routine glMultiDrawElements().
 */

#include "glad/gl.h"
#include "glut_wrap.h"
#include <stdlib.h>
#include <stdio.h>

static void setupPointer(void)
{
   static GLint vertices[] = {25, 25,
                       75, 75,
                       100, 125,
                       150, 75,
                       200, 175,
                       250, 150,
                       300, 125,
                       100, 200,
                       150, 250,
                       200, 225,
                       250, 300,
                       300, 250};

   glEnableClientState (GL_VERTEX_ARRAY);
   glVertexPointer (2, GL_INT, 0, vertices);
}

static void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   setupPointer ();
}

static void display(void)
{
   static GLubyte oneIndices[] = {0, 1, 2, 3, 4, 5, 6};
   static GLubyte twoIndices[] = {1, 7, 8, 9, 10, 11};
   static GLsizei count[] = {7, 6};
   static GLvoid * indices[2] = {oneIndices, twoIndices};

   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   glMultiDrawElementsEXT (GL_LINE_STRIP, count, GL_UNSIGNED_BYTE,
                           (const GLvoid **) indices, 2);
   glFlush ();
}

static void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

static void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (350, 350);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   gladLoaderLoadGL();
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   gladLoaderUnloadGL();
   return 0;
}
