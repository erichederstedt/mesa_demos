# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

progs = [
  ['array', []],
  ['bitmap', []],
  ['brick', []],
  ['bump', [idep_readtex]],
  ['blinking-teapot', []],
  ['convolutions', [idep_readtex]],
  ['deriv', []],
  ['fragcoord', []],
  ['fsraytrace', []],
  ['geom-outlining-150', []],
  ['identity', []],
  ['linktest', []],
  ['mandelbrot', []],
  ['multinoise', []],
  ['multitex', [idep_readtex]],
  ['noise2', []],
  ['noise', []],
  ['pointcoord', []],
  ['points', []],
  ['samplers', []],
  ['shadow_sampler', []],
  ['simplex-noise', []],
  ['skinning', []],
  ['texaaline', []],
  ['texdemo1', [idep_readtex]],
  ['toyball', []],
  ['trirast', []],
  ['twoside', []],
  ['vert-or-frag-only', []],
  ['vert-tex', []],
  ['vsraytrace', []],
]
base_deps = [dep_gl, dep_glu, dep_glut, dep_m, idep_glad, idep_util]
foreach pair : progs
  p = pair[0]
  extra_deps = pair[1]
  executable(
    p,
    files(p + '.c'),
    dependencies: base_deps + extra_deps,
    install: true,
  )
endforeach

executable(
  'gsraytrace',
  files('gsraytrace.cpp'),
  dependencies: [dep_gl, dep_glu, dep_glut, dep_m, idep_glad, idep_util],
  install: true,
)

executable(
  'samplers_array',
  files('samplers.c'),
  c_args: '-DSAMPLERS_ARRAY',
  dependencies: [dep_gl, dep_glu, dep_glut, dep_m, idep_glad, idep_util],
  install: true,
)
