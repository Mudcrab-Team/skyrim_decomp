// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers, sibling names).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none known. The origin check reports NiAVObject::IncRefCount as similar to the sibling bodies cited in the header (CC0-1.0); the draft states it was written from the pinned image listing.
// 0x2a36d0 ImageSpaceModifierInstanceForm::SetTarget
#include "ImageSpaceModifierInstanceForm_2a36d0.h"

bool ImageSpaceModifierInstanceForm::SetTarget(TESImageSpaceModifier* a_imod, float a_strength, float a_arg3, NiAVObject* a_target)
{
    if ((imod && imod->unk20) || (a_imod && a_imod->unk20)) {
        return false;
    }

    unk30 = imod;
    unk38 = strength;
    unk40 = target;
    age = g_defaultAge;
    unk48 = a_strength;
    strength = a_arg3;
    imod = a_imod;
    target = a_target;
    return true;
}
