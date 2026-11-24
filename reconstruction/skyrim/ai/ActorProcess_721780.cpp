// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; NiRefObject reference-count helpers adapted as stated below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x721780 ActorProcess::Function721780
// Adapted bodies: NiRefObject::IncRefCount and DecRefCount (header) from momusdigital/f3_decomp@f5bac1b5 (CC0-1.0); Function721780 original
#include "ActorProcess_721780.h"

bool ActorProcess::Function721780(NiPointer<Held>& in)
{
    if (unk08) {
        unk08->unkF8 = in._ptr;
        return true;
    }
    return false;
}
