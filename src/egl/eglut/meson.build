# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

inc_glut = include_directories('.')

eglut_files = files('eglut.c', 'wsi/wsi.c')
wsi_deps = []
wsi_args = []

if dep_wayland.found()
  wsi_args += ['-DWAYLAND_SUPPORT']
  eglut_files += files('wsi/wayland.c')
  wsi_deps += [dep_wayland, dep_epoll, dep_libdecor]
endif

if dep_x11.found()
  wsi_args += ['-DX11_SUPPORT']
  eglut_files += files('wsi/x11.c')
  wsi_deps += dep_x11
endif

if wsi_deps.length() > 0
  _libeglut = static_library(
    'eglut',
    eglut_files,
    dependencies: [dep_egl, wsi_deps],
    c_args: wsi_args,
  )

  idep_eglut = declare_dependency(
    link_with: _libeglut,
    include_directories: inc_glut,
  )
else
  idep_eglut = disabler()
endif
