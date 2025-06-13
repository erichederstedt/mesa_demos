# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

inc_util = include_directories('.')

files_libutil = files(
  'glinfo_common.c',
  'matrix.c',
  'shaderutil.c',
  'showbuffer.c',
  'trackball.c',
  'uuid.c'
)

_deps = [dep_m]

_libutil = static_library(
  'util',
  files_libutil,
  include_directories: inc_glad,
  dependencies: _deps,
)

idep_util = declare_dependency(
  link_with: _libutil,
  include_directories: inc_util,
)

_libreadtex = static_library(
  'readtex',
  files('readtex.c'),
  include_directories: inc_glad,
  dependencies: _deps + [dep_glu, dep_png],
  build_by_default: false,
)
idep_readtex = declare_dependency(
  link_with: [_libreadtex],
  include_directories: inc_util,
)
