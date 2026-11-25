// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xefcd40 BSGeometry::Functionefcd40
// Adapted bodies: none
#include "BSGeometry_efcd40.h"

void BSGeometry::Functionefcd40(void* a_dest, uint32_t a_count)
{
    uint32_t size = a_count * 8;
    a_count = 8;
    unk08 += unk18(this, a_dest, size, &a_count, 1);
}
