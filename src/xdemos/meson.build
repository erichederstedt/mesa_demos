# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

glx_deps = [dep_gl, dep_glx, dep_x11, dep_m]

progs = [
  'glsync',
  'glxdemo',
  'glxgears',
  'glxgears_pixmap',
  'glxcontexts',
  'glxheads',
  'glxpixmap',
  'glxpbdemo',
  'glxsnoop',
  'glxswapcontrol',
  'manywin',
  'multictx',
  'offset',
  'overlay',
  'shape',
  'sharedtex',
  'texture_from_pixmap',
  'wincopy',
  'xfont',
]
foreach p : progs
  executable(p, files(p + '.c'), dependencies: glx_deps, install: true)
endforeach

executable(
  'glxinfo',
  files('glxinfo.c'),
  dependencies: [glx_deps, idep_glad, idep_util],
  install: true,
)

executable(
  'xrotfontdemo',
  files('xrotfontdemo.c', 'xuserotfont.c'),
  dependencies: glx_deps,
  install: true,
)

_libpbutil = static_library('pbutil', files('pbutil.c'), dependencies: glx_deps)

pbutil_progs = ['glxgears_fbconfig', 'pbinfo', 'pbdemo']
foreach p : pbutil_progs
  executable(
    p,
    files(p + '.c'),
    dependencies: glx_deps,
    link_with: _libpbutil,
    install: true,
  )
endforeach

thread_progs = ['glthreads', 'sharedtex_mt']
foreach p : thread_progs
  executable(
    p,
    files(p + '.c'),
    dependencies: [glx_deps, dep_threads],
    install: true,
  )
endforeach
