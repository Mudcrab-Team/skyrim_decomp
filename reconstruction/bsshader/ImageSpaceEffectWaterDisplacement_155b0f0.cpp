// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none known. The origin check reports NiTPrimitiveArray::SetAt as similar to the sibling bodies cited in the header (CC0-1.0); the draft states it was written from the pinned image listing.
// 0x155b0f0 ImageSpaceEffectWaterDisplacement::Setup
#include "ImageSpaceEffectWaterDisplacement_155b0f0.h"

void ImageSpaceEffectWaterDisplacement::Setup(ImageSpaceManager* a_mgr, ImageSpaceEffectParam* /*a_param*/)
{
    Function1553df0(9);
    Function150b8f0(&effectTextures, 2);

    ImageSpaceShaderParam* p0 = new ImageSpaceShaderParam();
    TargetDerived* td0 = static_cast<TargetDerived*>(a_mgr->targets[0x56]);
    p0->Function150b630(td0->width - 1, td0->height);
    p0->unk0C = 0;
    effectParams.SetAt(0, p0);
    Function1554150(0, static_cast<TargetSub*>(td0), p0, 0);

    ImageSpaceShaderParam* p1 = new ImageSpaceShaderParam();
    TargetDerived* td1 = static_cast<TargetDerived*>(a_mgr->targets[0x57]);
    p1->Function150b630(td1->width - 1, td1->height);
    p1->unk0C = 0;
    effectParams.SetAt(1, p1);
    Function1554150(1, static_cast<TargetSub*>(td1), p1, 0);

    ImageSpaceShaderParam* p2 = new ImageSpaceShaderParam();
    TargetDerived* td2 = static_cast<TargetDerived*>(a_mgr->targets[0x58]);
    p2->Function150b630(td2->width - 1, td2->height);
    effectParams.SetAt(2, p2);
    Function1554150(2, static_cast<TargetSub*>(td2), p2, 0);

    ImageSpaceShaderParam* p3 = new ImageSpaceShaderParam();
    TargetDerived* td3 = static_cast<TargetDerived*>(a_mgr->targets[0x59]);
    p3->Function150b630(td3->width - 1, td3->height);
    effectParams.SetAt(3, p3);
    Function1554150(3, static_cast<TargetSub*>(td3), p3, 0);

    ImageSpaceShaderParam* p4 = new ImageSpaceShaderParam();
    TargetDerived* td4 = static_cast<TargetDerived*>(a_mgr->targets[0x5A]);
    p4->Function150b630(td4->width - 1, td4->height);
    effectParams.SetAt(4, p4);
    Function1554150(4, static_cast<TargetSub*>(td4), p4, 0);

    ImageSpaceShaderParam* p5 = new ImageSpaceShaderParam();
    TargetDerived* td5 = static_cast<TargetDerived*>(a_mgr->targets[0x5B]);
    p5->Function150b630(td5->width - 1, td5->height);
    effectParams.SetAt(5, p5);
    Function1554150(5, static_cast<TargetSub*>(td5), p5, 0);

    ImageSpaceShaderParam* p6 = new ImageSpaceShaderParam();
    TargetDerived* td6 = static_cast<TargetDerived*>(a_mgr->targets[0x5C]);
    p6->Function150b630(td6->width - 1, td6->height);
    p6->unk0C = 0;
    effectParams.SetAt(6, p6);
    Function1554150(6, static_cast<TargetSub*>(td6), p6, 0);

    ImageSpaceShaderParam* p7 = new ImageSpaceShaderParam();
    TargetDerived* td7 = static_cast<TargetDerived*>(a_mgr->targets[0x5D]);
    p7->Function150b630(td7->width - 1, td7->height);
    p7->unk0C = 0;
    effectParams.SetAt(7, p7);
    Function1554150(7, static_cast<TargetSub*>(td7), p7, 0);

    ImageSpaceShaderParam* p8 = new ImageSpaceShaderParam();
    TargetDerived* td8 = static_cast<TargetDerived*>(a_mgr->targets[0x5E]);
    p8->Function150b630(td8->width - 1, td8->height);
    p8->unk0C = 0;
    effectParams.SetAt(8, p8);
    Function1554150(8, static_cast<TargetSub*>(td8), p8, 0);
}
