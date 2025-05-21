
/* Copyright (c) Mark J. Kilgard, 1994. */

/**
 * (c) Copyright 1993, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * SPDX-License-Identifier: SGI-OpenGL
 */
/**
 *  teaambient.c
 *  This program renders three lighted, shaded teapots, with
 *  different ambient values.
 */
#include <stdlib.h>
#include "glut_wrap.h"

/*  Initialize light source and lighting model.
 */
static void
myinit(void)
{
    GLfloat light_ambient[] =
    {0.0, 0.0, 0.0, 1.0};
    GLfloat light_diffuse[] =
    {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] =
    {1.0, 1.0, 1.0, 1.0};
/* light_position is NOT default value */
    GLfloat light_position[] =
    {1.0, 0.0, 0.0, 0.0};
    GLfloat global_ambient[] =
    {0.75, 0.75, 0.75, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    glFrontFace(GL_CW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
}

static void
display(void)
{
    GLfloat low_ambient[] =
    {0.1, 0.1, 0.1, 1.0};
    GLfloat more_ambient[] =
    {0.4, 0.4, 0.4, 1.0};
    GLfloat most_ambient[] =
    {1.0, 1.0, 1.0, 1.0};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*  material has small ambient reflection */
    glMaterialfv(GL_FRONT, GL_AMBIENT, low_ambient);
    glMaterialf(GL_FRONT, GL_SHININESS, 40.0);
    glPushMatrix();
    glTranslatef(0.0, 2.0, 0.0);
    glutSolidTeapot(1.0);
    glPopMatrix();

    /*  material has moderate ambient reflection */
    glMaterialfv(GL_FRONT, GL_AMBIENT, more_ambient);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glutSolidTeapot(1.0);
    glPopMatrix();

    /*  material has large ambient reflection */
    glMaterialfv(GL_FRONT, GL_AMBIENT, most_ambient);
    glPushMatrix();
    glTranslatef(0.0, -2.0, 0.0);
    glutSolidTeapot(1.0);
    glPopMatrix();
    glFlush();
}

static void
myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-4.0, 4.0, -4.0 * (GLfloat) h / (GLfloat) w,
            4.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-4.0 * (GLfloat) w / (GLfloat) h,
            4.0 * (GLfloat) w / (GLfloat) h, -4.0, 4.0, -10.0, 10.0);
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
int
main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow(argv[0]);
    myinit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
