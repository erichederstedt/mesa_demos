/*
 * Copyright (C) 1999-2014  Brian Paul   All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 */


/**
 * Common code shared by glxinfo and wglinfo.
 */

#ifndef GLINFO_COMMON_H
#define GLINFO_COMMON_H

#include "glad/gl.h"

#include "gl_versions.h"


/**
 * Ext functions needed in common code but must be provided by
 * the glinfo tool.
 */
struct ext_functions
{
   PFNGLGETPROGRAMIVARBPROC GetProgramivARB;
   PFNGLGETSTRINGIPROC GetStringi;
};


#define ELEMENTS(array) (sizeof(array) / sizeof(array[0]))


struct bit_info
{
   int bit;
   const char *name;
};


typedef enum
{
   Normal,
   Wide,
   Verbose,
   Brief
} InfoMode;


void
print_extension_list(const char *ext, GLboolean singleLine);

char *
build_core_profile_extension_list(const struct ext_functions *extfuncs);

GLboolean
extension_supported(const char *ext, const char *extensionsList);

void
print_limits(const char *oglstring, const struct ext_functions *extfuncs);

const char *
bitmask_to_string(const struct bit_info bits[], int numBits, int mask);

const char *
profile_mask_string(int mask);

const char *
context_flags_string(int mask);

void
print_gpu_memory_info(void);

#endif /* GLINFO_COMMON_H */
