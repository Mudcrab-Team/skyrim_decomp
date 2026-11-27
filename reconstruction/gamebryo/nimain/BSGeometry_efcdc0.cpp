// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xefcdc0 BSGeometry::Functionefcdc0
// Adapted bodies: none
#include "BSGeometry_efcdc0.h"

void BSGeometry::Functionefcdc0(void* a_dest)
{
    uint32_t elemSize = 8;
    Sink* out = sink;
    out->unk08 += out->unk18(out, a_dest, 8, &elemSize, 1);
}
