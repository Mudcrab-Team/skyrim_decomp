// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; NiRefObject reference-count helpers adapted as stated below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7217e0 ActorProcess::Function7217e0
// Adapted bodies: NiRefObject::IncRefCount and DecRefCount (header) from momusdigital/f3_decomp@f5bac1b5 (CC0-1.0); Function7217e0 original
#include "ActorProcess_7217e0.h"

bool ActorProcess::Function7217e0(NiPointer<Held>& out)
{
    if (unk08) {
        out = unk08->unk1A8._ptr;
    } else {
        out = nullptr;
    }
    return out._ptr != nullptr;
}
