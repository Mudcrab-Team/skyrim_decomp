// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xefcd00 BSGeometry::Functionefcd00
// Adapted bodies: none
#include "BSGeometry_efcd00.h"

void BSGeometry::Functionefcd00(void* a_dest, uint32_t a_count)
{
    uint32_t size = a_count * 8;
    a_count = 8;
    unk08 += unk10(this, a_dest, size, &a_count, 1);
}
