# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

progs = [
  'wglthreads',
  'wglcontext',
  'wglfontbitmaps',
  'wglfontoutlines',
  'wglgears',
]
foreach p : progs
  executable(
    p,
    files(p + '.c'),
    dependencies: [dep_gl, dep_glu, idep_glad, dep_winmm],
    install: true,
  )
endforeach

executable(
  'wgl_sharedtex_mt',
  files('sharedtex_mt.c'),
  dependencies: [dep_gl, idep_glad],
  install: true,
)

executable(
  'wglinfo',
  files('wglinfo.c'),
  include_directories: include_directories('../xdemos'),
  dependencies: [dep_gl, idep_glad, idep_util],
  install: true,
)

executable(
  'wincopy',
  files('wglutil.c', 'wincopy.c'),
  dependencies: [dep_gl, idep_glad],
  win_subsystem: 'windows',
  install: true,
)
