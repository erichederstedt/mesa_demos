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

glsl_data = [
  'blinking-teapot.frag',
  'blinking-teapot.vert',
  'CH06-brick.frag',
  'CH06-brick.vert',
  'CH11-bumpmap.frag',
  'CH11-bumpmaptex.frag',
  'CH11-bumpmap.vert',
  'CH11-toyball.frag',
  'CH11-toyball.vert',
  'CH18-mandel.frag',
  'CH18-mandel.vert',
  'convolution.frag',
  'convolution.vert',
  'cubemap.frag',
  'multitex.frag',
  'multitex.vert',
  'reflect.vert',
  'shadowtex.frag',
  'simple.vert',
  'simplex-noise.glsl',
  'skinning.frag',
  'skinning.vert',
]

install_data(glsl_data, install_dir: get_option('datadir') / 'mesa-demos')
