/*
 * (C) Copyright IBM Corporation 2005
 * All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/**
 * \file bug_3101.c
 *
 * Simple regression test for bug #3101.  Attempt to draw a single square.
 * After emiting the first vertex, call \c glEdgeFlag to change the vertex
 * format.  If the bug still exists, this will cause a segfault.
 *
 * \author Ian Romanick <idr@us.ibm.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "glad/gl.h"
#include "glut_wrap.h"

static int Width = 400;
static int Height = 200;
static const GLfloat Near = 5.0, Far = 25.0;


static void Display( void )
{
   glClearColor(0.2, 0.2, 0.8, 0);
   glClear( GL_COLOR_BUFFER_BIT );

   glPushMatrix();

   /* This is the "reference" square.
    */

   glTranslatef(-4.5, 0, 0);
   glBlendEquation( GL_FUNC_ADD );
   glBlendFunc( GL_ONE, GL_ZERO );
   glBegin(GL_QUADS);
   glColor3f( 0.5, 0.5, 0.5 );
   glVertex2f(-1, -1);
   glVertex2f( 1, -1);
   glEdgeFlag(GL_TRUE);
   glVertex2f( 1,  1);
   glVertex2f(-1,  1);
   glEnd();

   glPopMatrix();

   glutSwapBuffers();
}


static void Reshape( int width, int height )
{
   GLfloat ar = (float) width / (float) height;
   Width = width;
   Height = height;
   glViewport( 0, 0, width, height );
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   glFrustum( -ar, ar, -1.0, 1.0, Near, Far );
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();
   glTranslatef( 0.0, 0.0, -15.0 );
}


static void Key( unsigned char key, int x, int y )
{
   (void) x;
   (void) y;
   switch (key) {
      case 27:
         exit(0);
         break;
   }
   glutPostRedisplay();
}


static void Init( void )
{
   const char * const ver_string = (const char *)
       glGetString( GL_VERSION );

   printf("GL_RENDERER = %s\n", (char *) glGetString(GL_RENDERER));
   printf("GL_VERSION = %s\n", ver_string);

   printf("\nThis program should draw a single square, but not crash.\n");
   printf("This is a regression test for bug #3101.\n");
   printf("https://bugs.freedesktop.org/show_bug.cgi?id=3101\n");
   glEnable( GL_BLEND );
}


int main( int argc, char *argv[] )
{
   glutInit( &argc, argv );
   glutInitWindowPosition( 0, 0 );
   glutInitWindowSize( Width, Height );
   glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
   glutCreateWindow( "Bug #3101 Test" );
   gladLoaderLoadGL();
   glutReshapeFunc( Reshape );
   glutKeyboardFunc( Key );
   glutDisplayFunc( Display );
   Init();
   glutMainLoop();
   gladLoaderUnloadGL();
   return 0;
}
