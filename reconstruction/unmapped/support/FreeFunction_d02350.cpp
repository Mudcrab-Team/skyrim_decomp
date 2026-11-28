// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xd02350 Functiond02350
// Adapted bodies: none
#include "FreeFunction_d02350.h"

// Sets matrix to the 4x4 identity matrix.
void Functiond02350(Matrix4d02350* matrix)
{
    matrix->m[0][1] = 0.0f;
    matrix->m[0][2] = 0.0f;
    matrix->m[0][3] = 0.0f;
    matrix->m[1][0] = 0.0f;
    matrix->m[1][2] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][0] = 0.0f;
    matrix->m[2][1] = 0.0f;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][0] = 0.0f;
    matrix->m[3][1] = 0.0f;
    matrix->m[3][2] = 0.0f;
    matrix->m[0][0] = 1.0f;
    matrix->m[1][1] = 1.0f;
    matrix->m[2][2] = 1.0f;
    matrix->m[3][3] = 1.0f;
}
