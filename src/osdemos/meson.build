# Copyright © 2022 Collabora Ltd
# SPDX-License-Identifier: MIT

progs = ['osdemo', 'osdemo16', 'osdemo32']
foreach p : progs
  executable(
    p,
    files(p + '.c'),
    dependencies: [dep_osmesa, dep_m, idep_util],
    install: true,
  )
endforeach

