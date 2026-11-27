// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none known. The origin check reports NiTPrimitiveArray::SetAt as similar to the sibling bodies cited in the header (CC0-1.0); the draft states it was written from the pinned image listing.
// 0x1585440 ImageSpaceEffectNoise::Setup
#include "ImageSpaceEffectNoise_1585440.h"

void ImageSpaceEffectNoise::Setup(ImageSpaceManager* a_mgr, ImageSpaceEffectParam* /*a_param*/)
{
    Function1553df0(2);
    textures.SetSize(4);

    if (!unk330) {
        Function1585a20();
    }

    ImageSpaceShaderParam* p0 = new ImageSpaceShaderParam();
    TargetDerived* td0 = static_cast<TargetDerived*>(a_mgr->targets[0x5F]);
    p0->Function150b630(td0->width - 1, td0->height);
    effectParams.SetAt(0, p0);
    Function1554150(0, static_cast<TargetSub*>(td0), p0, 0);

    ImageSpaceShaderParam* p1 = new ImageSpaceShaderParam();
    TargetDerived* td1 = static_cast<TargetDerived*>(a_mgr->targets[0x60]);
    p1->Function150b630(td1->width - 1, td1->height);
    effectParams.SetAt(1, p1);
    Function1554150(1, static_cast<TargetSub*>(td1), p1, 0);
}
