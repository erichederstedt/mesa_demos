# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

_deps_x11 = [dep_gles2, dep_egl, dep_x11]
executable(
  'es2_info',
  files('es2_info.c'),
  dependencies: _deps_x11,
  install: true,
)
executable(
  'es2gears',
  files('es2gears.c'),
  dependencies: [dep_gles2, idep_eglut, idep_util],
  install: true,
)
executable(
  'es2tri',
  files('es2tri.c'),
  dependencies: [dep_gles2, idep_eglut, idep_util],
  install: true,
)
executable(
  'texture_from_pixmap_glesv2',
  files('texture_from_pixmap_glesv2.c'),
  dependencies: [_deps_x11, idep_util],
)
