// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1582fc0 ImageSpaceEffectGetHit::BorrowTextures
#include "ImageSpaceEffectGetHit_1582fc0.h"

void ImageSpaceEffectGetHit::BorrowTextures(ImageSpaceEffectParam* /*a_param*/)
{
    tex98.Function1554f40(0x13);
    effectTextures.SetAt(2, &tex98);
    texB8.Function1554f40(0x13);
    effectTextures.SetAt(3, &texB8);
    texD8.Function1554f40(0x14);
    effectTextures.SetAt(4, &texD8);
}
