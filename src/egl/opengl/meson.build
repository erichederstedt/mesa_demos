# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

_deps = [dep_gl, dep_m, idep_util]

if target_machine.system() == 'linux'
  executable(
    'dmabufshare',
    files('dmabufshare.c'),
    dependencies: [_deps, idep_glad, idep_eglut],
    install: true,
  )
endif
executable(
  'eglgears',
  files('eglgears.c'),
  dependencies: [dep_glu, _deps, idep_eglut],
  install: true,
)
executable(
  'egltri',
  files('egltri.c'),
  dependencies: [dep_glu, _deps, idep_eglut],
  install: true,
)
executable(
  'xeglgears',
  files('xeglgears.c'),
  dependencies: [dep_glu, _deps, dep_egl, dep_x11],
  install: true,
)
executable(
  'xeglthreads',
  files('xeglthreads.c'),
  dependencies: [_deps, dep_egl, dep_x11],
  install: true,
)

executable(
  'eglkms',
  'eglkms.c',
  dependencies: [_deps, dep_drm, dep_gbm, dep_egl],
  install: true,
)

executable(
  'peglgears',
  'peglgears.c',
  dependencies: [dep_glu, dep_gl, dep_egl, dep_m, idep_util],
  install: true,
)

