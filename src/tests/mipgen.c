/* Test GL_TEXTURE_BASE_LEVEL and GL_TEXTURE_MAX_LEVEL
 * Brian Paul
 * 10 May 2006
 */


/* Copyright (c) Mark J. Kilgard, 1994. */

/*
 * (c) Copyright 1993, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * SPDX-License-Identifier: SGI-OpenGL
 */

#include <stdlib.h>
#include <stdio.h>
#include "glad/gl.h"
#include "glut_wrap.h"


static GLfloat LodBias = 6.0;   /* make smallest miplevel visible */
static GLuint texImage;

#define WIDTH 2
#define HEIGHT 2

static void
InitValues(void)
{
   LodBias = 6.0;               /* make smallest miplevel visible */
}


static void MakeImage(void)
{
   const GLubyte color0[4] = { 0xff, 0x80, 0x20, 0xff };
   const GLubyte color1[4] = { 0x10, 0x20, 0x40, 0xff };

   GLubyte img[WIDTH*HEIGHT*3];
   int i, j;
   for (i = 0; i < HEIGHT; i++) {
      for (j = 0; j < WIDTH; j++) {
         int k = (i * WIDTH + j) * 3;
         int p = ((i+j)%2);
         if (p == 0) {
            img[k + 0] = color0[0];
            img[k + 1] = color0[1];
            img[k + 2] = color0[2];
         }
         else {
            img[k + 0] = color1[0];
            img[k + 1] = color1[1];
            img[k + 2] = color1[2];
         }
      }
   }

   glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, WIDTH, HEIGHT, 0,
                GL_RGB, GL_UNSIGNED_BYTE, img);
   glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_FALSE);
}



static void myinit(void)
{
   InitValues();

   glShadeModel(GL_FLAT);

   glTranslatef(0.0, 0.0, -3.6);

   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
   glGenTextures(1, &texImage);
   glBindTexture(GL_TEXTURE_2D, texImage);
   MakeImage();

   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
   glEnable(GL_TEXTURE_2D);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1);

   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_LOD, -1);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_LOD, 1);

   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST_MIPMAP_NEAREST);
}



static void display(void)
{
   GLfloat tcm = 1.0;
   glBindTexture(GL_TEXTURE_2D, texImage);

   printf("Bias=%.2g\n", LodBias);
   fflush(stdout);

   glTexEnvf(GL_TEXTURE_FILTER_CONTROL_EXT, GL_TEXTURE_LOD_BIAS_EXT, LodBias);

   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
   glTexCoord2f(0.0, tcm); glVertex3f(-2.0, 1.0, 0.0);
   glTexCoord2f(tcm * 3000.0, tcm); glVertex3f(3000.0, 1.0, -6000.0);
   glTexCoord2f(tcm * 3000.0, 0.0); glVertex3f(3000.0, -1.0, -6000.0);
   glEnd();
   glFlush();
}

static void myReshape(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, 1.0*(GLfloat)w/(GLfloat)h, 1.0, 30000.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

static void
key(unsigned char k, int x, int y)
{
  (void) x;
  (void) y;
  switch (k) {
  case 'l':
     LodBias -= 0.25;
     break;
  case 'L':
     LodBias += 0.25;
     break;
  case ' ':
     InitValues();
     break;
  case 27:  /* Escape */
    exit(0);
    break;
  default:
    return;
  }
  glutPostRedisplay();
}


static void usage(void)
{
   printf("usage:\n");
   printf("  l/L    decrease/increase GL_TEXTURE_LOD_BIAS\n");
   printf("  SPACE  reset values\n");
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize (600, 600);
    glutCreateWindow (argv[0]);
    gladLoaderLoadGL();
    myinit();
    glutReshapeFunc (myReshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    usage();
    glutMainLoop();
    gladLoaderUnloadGL();
    return 0;
}
