// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x418540 Sky::Function418540
// Adapted bodies: TestBit (header), momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422, CC0-1.0
#include "Sky_418540.h"

bool Sky::Function418540()
{
    SkyOwner* owner = g_skyOwner;
    if (owner) {
        SkyData* data = owner->unk48;
        if (data) {
            SkyInner* inner = data->unk8D0;
            if (inner) {
                if (TestBit(inner->unk30, 2)) {
                    return true;
                }
            }
        }
    }
    return false;
}
