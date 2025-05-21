/*
 * Copyright (C) 1999-2014  Brian Paul   All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef GL_VERSIONS_H
#define GL_VERSIONS_H

/** list of known OpenGL versions */
static const struct { int major, minor; } gl_versions[] = {
   {4, 6},
   {4, 5},
   {4, 4},
   {4, 3},
   {4, 2},
   {4, 1},
   {4, 0},

   {3, 3},
   {3, 2},
   {3, 1},
   {3, 0},

   {2, 1},
   {2, 0},

   {1, 5},
   {1, 4},
   {1, 3},
   {1, 2},
   {1, 1},
   {1, 0},

   {0, 0} /* end of list */
};

#endif /* GL_VERSIONS_H */
