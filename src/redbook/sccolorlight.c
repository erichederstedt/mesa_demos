
/* Copyright (c) Mark J. Kilgard, 1994. */

/*
 * (c) Copyright 1993, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * SPDX-License-Identifier: SGI-OpenGL
 */
/*
 *  sccolorlight.c
 *  This program demonstrates the use of a colored
 *  (magenta, in this example) light source.  Objects
 *  are drawn using a grey material characteristic.
 *  A single light source illuminates the objects.
 */
#include <stdlib.h>
#include "glut_wrap.h"

/*  Initialize material property and light source.
 */
static void myinit(void)
{
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 0.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 0.0, 1.0, 1.0 };
/*	light_position is NOT default value	*/
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix ();
    glRotatef (20.0, 1.0, 0.0, 0.0);

    glPushMatrix ();
    glTranslatef (-0.75, 0.5, 0.0);
    glRotatef (90.0, 1.0, 0.0, 0.0);
    glutSolidTorus (0.275, 0.85, 20, 20);
    glPopMatrix ();

    glPushMatrix ();
    glTranslatef (-0.75, -0.5, 0.0);
    glRotatef (270.0, 1.0, 0.0, 0.0);
    glutSolidCone (1.0, 2.0, 20, 20);
    glPopMatrix ();

    glPushMatrix ();
    glTranslatef (0.75, 0.0, -1.0);
    glutSolidSphere (1.0, 20, 20);
    glPopMatrix ();

    glPopMatrix ();
    glFlush();
}

static void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
	glOrtho (-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w,
	    2.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else
	glOrtho (-2.5*(GLfloat)w/(GLfloat)h,
	    2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

static void
key(unsigned char k, int x, int y)
{
  switch (k) {
  case 27:  /* Escape */
    exit(0);
    break;
  default:
    return;
  }
  glutPostRedisplay();
}

/*  Main Loop
 *  Open window with initial window size, title bar,
 *  RGBA display mode, and handle input events.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutCreateWindow (argv[0]);
    myinit();
    glutReshapeFunc (myReshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
