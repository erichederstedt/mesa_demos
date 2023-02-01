# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

objview_files = files('glm.c', 'glmdraw.c', 'objview.c', 'skybox.c')
executable(
  'objview',
  objview_files,
  dependencies: [
    dep_gl,
    dep_glu,
    dep_glut,
    dep_m,
    idep_glad,
    idep_util,
    idep_readtex,
  ],
)
