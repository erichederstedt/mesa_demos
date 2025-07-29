/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright © 2022 Collabora Ltd
 */

#ifndef DATA_H
#define DATA_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Create a file-path relative to the configured data-directory.
 *
 * Warning: this function returns a static buffer, which means that it
 * clobbers previously returned paths. Callers needs to either take care to
 * only handle one path at the time, or strdup the result.
 */

static inline char *
data_file_path(const char *filename)
{
    static char path[PATH_MAX];

    if (snprintf(path, sizeof(path), "%s/%s", DEMOS_DATA_DIR, filename) < 0) {
        perror("snprintf failed");
        abort();
    }

    return path;
}

#endif /* DATA_H */
