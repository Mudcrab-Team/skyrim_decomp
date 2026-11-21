// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; reconstructed from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x150a6b0 BSImagespaceShaderISDownsample::Unk_0D
// Adapted bodies: none
#include "BSImagespaceShaderISDownsample.h"

extern char gUnk0D_0[];
extern char gUnk0D_1[];
extern char gUnk0D_2[];

Unk0DInfo* BSImagespaceShaderISDownsample::Unk_0D(Unk0DInfo* a_out)
{
    a_out->f00 = gUnk0D_0;
    a_out->f08 = gUnk0D_1;
    a_out->f10 = gUnk0D_2;
    a_out->f18 = gUnk0D_1;
    a_out->f20 = nullptr;
    a_out->f28 = nullptr;
    return a_out;
}
