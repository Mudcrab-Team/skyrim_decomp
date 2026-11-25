// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xefc7a0 BSGeometry::Functionefc7a0
// Adapted bodies: none
#include "BSGeometry_efc7a0.h"

void BSGeometry::Functionefc7a0(void* a_arg)
{
    if (TestBit(unkF4, 18)) {
        if (unk128 && unk128->unk18) {
            unk128->vfunc26(a_arg);
        }

        if (unk120 && unk120->unk18) {
            unk120->vfunc26(a_arg);
        }
    }
}
