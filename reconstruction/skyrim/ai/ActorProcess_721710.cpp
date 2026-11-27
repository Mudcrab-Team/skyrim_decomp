// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; NiRefObject reference-count helpers adapted as stated below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x721710 ActorProcess::Function721710
// Adapted bodies: NiRefObject::IncRefCount and DecRefCount (header) from momusdigital/f3_decomp@f5bac1b5 (CC0-1.0); Function721710 original
#include "ActorProcess_721710.h"

bool ActorProcess::Function721710(NiPointer<Held>& out)
{
    if (unk08) {
        out = unk08->unkF8._ptr;
        if (out._ptr) {
            return true;
        }
    }
    return false;
}
