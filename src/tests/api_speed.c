/*
 * (C) Copyright IBM Corporation 2002
 * All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/**
 * \file api_speed.c
 * Simple test to measure the overhead of making GL calls.
 *
 * The main purpose of this test is to measure the difference in calling
 * overhead of different dispatch methods.  Since it uses asm/timex.h to
 * access the Pentium's cycle counters, it will probably only compile on
 * Linux (though most architectures have a get_cycles function in timex.h).
 * That is why it isn't in the default Makefile.
 *
 * \author Ian Romanick <idr@us.ibm.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "glad/gl.h"
#include "glut_wrap.h"

#define inline __inline__
#include <asm/timex.h>

static float Width = 400;
static float Height = 400;
static unsigned count = 1000000;


static void Idle( void )
{
   glutPostRedisplay();
}

#define DO_FUNC(f,p) \
   do { \
      t0 = get_cycles(); \
      for ( i = 0 ; i < count ; i++ ) { \
	 f p ; \
      } \
      t1 = get_cycles(); \
      printf("%u calls to % 20s required %llu cycles.\n", count, # f, t1 - t0); \
   } while( 0 )

/**
 * Main display function.  This is the place to add more API calls.
 */
static void Display( void )
{
   int i;
   const float v[3] = { 1.0, 0.0, 0.0 };
   cycles_t t0;
   cycles_t t1;

   glBegin(GL_TRIANGLE_STRIP);

   DO_FUNC( glColor3fv, (v) );
   DO_FUNC( glNormal3fv, (v) );
   DO_FUNC( glTexCoord2fv, (v) );
   DO_FUNC( glTexCoord3fv, (v) );
   DO_FUNC( glMultiTexCoord2fv, (GL_TEXTURE0, v) );
   DO_FUNC( glMultiTexCoord2f, (GL_TEXTURE0, 0.0, 0.0) );
   DO_FUNC( glFogCoordfvEXT, (v) );
   DO_FUNC( glFogCoordfEXT, (0.5) );

   glEnd();

   exit(0);
}


static void Reshape( int width, int height )
{
   Width = width;
   Height = height;
   glViewport( 0, 0, width, height );
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   glOrtho(0.0, width, 0.0, height, -1.0, 1.0);
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();
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


int main( int argc, char *argv[] )
{
   glutInit( &argc, argv );
   glutInitWindowSize( (int) Width, (int) Height );
   glutInitWindowPosition( 0, 0 );

   glutInitDisplayMode( GLUT_RGB );

   glutCreateWindow( argv[0] );
   gladLoaderLoadGL();

   if ( argc > 1 ) {
      count = strtoul( argv[1], NULL, 0 );
      if ( count == 0 ) {
	 fprintf( stderr, "Usage: %s [iterations]\n", argv[0] );
	 exit(1);
      }
   }

   glutReshapeFunc( Reshape );
   glutKeyboardFunc( Key );
   glutDisplayFunc( Display );
   glutIdleFunc( Idle );

   glutMainLoop();
   gladLoaderUnloadGL();
   return 0;
}
