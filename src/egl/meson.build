# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

subdir('eglut')
subdir('common')

if dep_gl.found()
  subdir('opengl')
endif

if dep_gles1.found()
  subdir('opengles1')
endif

if dep_gles2.found()
  subdir('opengles2')
endif
