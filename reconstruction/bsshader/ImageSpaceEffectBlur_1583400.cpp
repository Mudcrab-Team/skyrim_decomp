// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none known. The origin check reports NiTPrimitiveArray::SetAt as similar to the sibling bodies cited in the header (CC0-1.0); the draft states it was written from the pinned image listing.
// 0x1583400 ImageSpaceEffectBlur::Setup
#include "ImageSpaceEffectBlur_1583400.h"

void ImageSpaceEffectBlur::Setup(ImageSpaceManager* a_mgr, ImageSpaceEffectParam* /*a_param*/)
{
    Function1553df0(2);
    if (unk94) {
        Function150b8f0(&effectTextures, 4);
    } else {
        Function150b8f0(&effectTextures, 3);
    }

    std::int32_t base = unk90;
    std::int32_t off1 = unk95 ? 0x41 : 0x48;
    std::int32_t off2 = unk94 ? 0x4F : off1;
    std::uint32_t idx0 = static_cast<std::uint32_t>(base - 1 + off2);
    std::uint32_t idx1 = static_cast<std::uint32_t>(base - 1 + off1);

    ImageSpaceShaderParam* p0 = new ImageSpaceShaderParam();
    TargetDerived* td0 = static_cast<TargetDerived*>(a_mgr->targets[idx0]);
    p0->Function150b630(td0->width - 1, td0->height);
    p0->Function152b1e0();
    effectParams.SetAt(0, p0);

    if (unk94) {
        Function1554310(0, 1, 3, 0, 0);
    } else {
        Function1554270(0, 1, 0);
    }
    Function1554150(0, static_cast<TargetSub*>(td0), p0, 2);

    ImageSpaceShaderParam* p1 = new ImageSpaceShaderParam();
    TargetDerived* td1 = static_cast<TargetDerived*>(a_mgr->targets[idx1]);
    p1->Function150b630(td1->width - 1, td1->height);
    p1->Function152b1e0();
    effectParams.SetAt(1, p1);
    Function1554270(1, 2, 0);
    Function1554150(1, static_cast<TargetSub*>(td1), p1, 0);
}
