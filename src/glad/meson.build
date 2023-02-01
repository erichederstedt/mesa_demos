# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

inc_glad = include_directories('include')

_libglad_files = files('src/gl.c')
if get_option('egl').allowed()
  _libglad_files += files('src/egl.c')
endif
if host_machine.system() == 'windows'
  _libglad_files += files('src/wgl.c')
endif

_libglad = static_library('glad', _libglad_files, include_directories: inc_glad)

idep_glad = declare_dependency(
  link_with: _libglad,
  dependencies: dep_dl,
  include_directories: inc_glad,
)
