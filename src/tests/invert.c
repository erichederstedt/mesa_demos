/*
 * (C) Copyright IBM Corporation 2005
 * All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/**
 * \file invert.c
 *
 * Simple test of GL_MESA_pack_invert functionality.  Three squares are
 * drawn.  The first two should look the same, and the third one should
 * look inverted.
 *
 * \author Ian Romanick <idr@us.ibm.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glad/gl.h"
#include "glut_wrap.h"

#include "readtex.h"
#include "data.h"

static int Width = 420;
static int Height = 150;
static const GLfloat Near = 5.0, Far = 25.0;

static GLubyte * image = NULL;
static GLubyte * temp_image = NULL;
static GLuint img_width = 0;
static GLuint img_height = 0;
static GLuint img_format = 0;



static void Display( void )
{
   GLint err;


   glClearColor(0.2, 0.2, 0.8, 0);
   glClear( GL_COLOR_BUFFER_BIT );


   /* This is the "reference" square.
    */

   glWindowPos2i( 5, 5 );
   glDrawPixels( img_width, img_height, img_format, GL_UNSIGNED_BYTE, image );

   glPixelStorei( GL_PACK_INVERT_MESA, GL_FALSE );
   err = glGetError();
   if ( err != GL_NO_ERROR ) {
      printf( "Setting PACK_INVERT_MESA to false generated an error (0x%04x).\n",
	      err );
   }

   glReadPixels( 5, 5, img_width, img_height, img_format, GL_UNSIGNED_BYTE, temp_image );
   glWindowPos2i( 5 + 1 * (10 + img_width), 5 );
   glDrawPixels( img_width, img_height, img_format, GL_UNSIGNED_BYTE, temp_image );

   glPixelStorei( GL_PACK_INVERT_MESA, GL_TRUE );
   err = glGetError();
   if ( err != GL_NO_ERROR ) {
      printf( "Setting PACK_INVERT_MESA to true generated an error (0x%04x).\n",
	      err );
   }

   glReadPixels( 5, 5, img_width, img_height, img_format, GL_UNSIGNED_BYTE, temp_image );
   glWindowPos2i( 5 + 2 * (10 + img_width), 5 );
   glDrawPixels( img_width, img_height, img_format, GL_UNSIGNED_BYTE, temp_image );

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
   printf("GL_RENDERER = %s\n", (char *) glGetString(GL_RENDERER));
   printf("GL_VERSION = %s\n", (char *) glGetString(GL_VERSION));

   if ( !glutExtensionSupported("GL_MESA_pack_invert") ) {
      printf("\nSorry, this program requires GL_MESA_pack_invert.\n");
      exit(1);
   }

   if ( !glutExtensionSupported("GL_ARB_window_pos") ) {
      printf("\nSorry, this program requires GL_ARB_window_pos.\n");
      exit(1);
   }

   /* Do this check as a separate if-statement instead of as an else in case
    * one of the required extensions is supported but glutGetProcAddress
    * returns NULL.
    */

   printf("\nThe left 2 squares should be the same color, and the right\n"
	  "square should look upside-down.\n");


   const char *image_file = data_file_path_static_buf("tree3.png");
   image = LoadRGBImage( image_file, (GLint *) & img_width, (GLint *) & img_height,
			 & img_format );
   if ( image == NULL ) {
      printf( "Could not open image file \"%s\".\n", image_file );
      exit(1);
   }

   temp_image = malloc( 3 * img_height * img_width );
   if ( temp_image == NULL ) {
      printf( "Could not allocate memory for temporary image.\n" );
      exit(1);
   }
}


int main( int argc, char *argv[] )
{
   glutInit( &argc, argv );
   glutInitWindowPosition( 0, 0 );
   glutInitWindowSize( Width, Height );
   glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
   glutCreateWindow( "GL_MESA_pack_invert test" );
   gladLoaderLoadGL();
   glutReshapeFunc( Reshape );
   glutKeyboardFunc( Key );
   glutDisplayFunc( Display );
   Init();
   glutMainLoop();
   gladLoaderUnloadGL();
   return 0;
}
