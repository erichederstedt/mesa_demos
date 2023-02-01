# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

progs = [
  ['accum', []],
  ['bitmap1', []],
  ['bitmap2', []],
  ['blendeq', []],
  ['blendxor', []],
  ['copy', []],
  ['cursor', []],
  ['depth', []],
  ['eval', []],
  ['fog', []],
  ['font', []],
  ['line', []],
  ['logo', []],
  ['nurb', []],
  ['olympic', []],
  ['overlay', []],
  ['point', []],
  ['prim', []],
  ['quad', []],
  ['select', []],
  ['shape', []],
  ['sphere', [idep_readtex]],
  ['star', []],
  ['stencil', []],
  ['stretch', []],
  ['texture', []],
  ['tri', []],
  ['wave', []],
]
base_deps = [dep_gl, dep_glu, dep_glut, dep_m, idep_glad, idep_util]
foreach pair : progs
  p = pair[0]
  extra_deps = pair[1]
  executable(p, files(p + '.c'), dependencies: base_deps + extra_deps)
endforeach
