# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

subdir('glad')

subdir('util')

if dep_glut.found()
  subdir('demos')
  subdir('tests')
  subdir('trivial')
  subdir('redbook')
  subdir('samples')
  subdir('objviewer')

  subdir('glsl')
  subdir('fpglsl')
  subdir('vpglsl')
  subdir('tools')
endif

if dep_egl.found()
  subdir('egl')
endif

if dep_x11.found()
  subdir('xdemos')
endif

if dep_osmesa.found()
  subdir('osdemos')
endif

if dep_vulkan.found()
  subdir('vulkan')
endif

if host_machine.system() == 'windows'
  subdir('wgl')
endif

subdir('data')
