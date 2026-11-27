// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// Adapted bodies: none known. The origin check reports NiTPrimitiveArray::GetAt, NiTPrimitiveArray::SetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00b80000_o2.cpp:3433
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niintegersextradata_o2_variant.cpp:205
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1550d20 ImageSpaceEffectDepthOfField::Setup
#include "ImageSpaceEffectDepthOfField_1550d20.h"

void ImageSpaceEffectDepthOfField::Setup(ImageSpaceManager* a_mgr, ImageSpaceEffectParam*)
{
    Function1553df0(kPassCount);

    ImageSpaceShaderParam* param = new ImageSpaceShaderParam();
    param->Function152b1e0();
    TargetDerived* shader = static_cast<TargetDerived*>(a_mgr->effects.GetAt(0x3A));
    param->Function150b630(shader->GetWidth() - 1, shader->GetHeight());
    param->Function152b1b0(kSlot2, &g_dofParams20d7410, kDofParamSize);
    Function1554150(kSlot0, shader, param, kSlot2);
    effectParams.SetAt(kSlot0, param);
    Function1554270(kSlot0, kSlot1, kSlot1);

    effectParams.SetAt(kSlot1, nullptr);
    Function1554310(kSlot1, kSlot2, kSlot3, kSlot0, kSlot0);
    Function1554150(kSlot1, a_mgr->effects.GetAt(0x0B), nullptr, kSlot2);

    param = new ImageSpaceShaderParam();
    shader = static_cast<TargetDerived*>(a_mgr->effects.GetAt(0x2D));
    param->Function150b630(shader->GetWidth() - 1, shader->GetHeight());
    effectParams.SetAt(kSlot2, param);
    Function1554480(kSlot2, kSlot1, kSlot2, kSlot4, kSlot5, kSlot0, kSlot1, kSlot0, kSlot0);
    Function1554150(kSlot2, shader, param, kSlot0);

    param = new ImageSpaceShaderParam();
    shader = static_cast<TargetDerived*>(a_mgr->effects.GetAt(0x2E));
    param->Function150b630(shader->GetWidth() - 1, shader->GetHeight());
    effectParams.SetAt(kSlot3, param);
    Function1554480(kSlot3, kSlot1, kSlot2, kSlot4, kSlot5, kSlot3, kSlot1, kSlot0, kSlot0);
    Function1554150(kSlot3, shader, param, kSlot0);

    param = new ImageSpaceShaderParam();
    shader = static_cast<TargetDerived*>(a_mgr->effects.GetAt(0x2F));
    param->Function150b630(shader->GetWidth() - 1, shader->GetHeight());
    effectParams.SetAt(kSlot4, param);
    Function1554550(kSlot4, kSlot1, kSlot2, kSlot4, kSlot5, kSlot6, kSlot3, kSlot1, kSlot0, kSlot0, kSlot0);
    Function1554150(kSlot4, shader, param, kSlot0);
}
