// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Matrix4d02350, Functiond02350, m, matrix: GUESS(low)
#pragma once

struct Matrix4d02350
{
    float m[4][4];  // 0x00
};
static_assert(sizeof(Matrix4d02350) == 0x40, "Matrix4d02350 size");

void Functiond02350(Matrix4d02350* matrix);
