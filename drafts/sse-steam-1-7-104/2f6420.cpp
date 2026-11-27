// Near miss: 2.0 alignment distance | register-schedule
// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; observed flag update and virtual-call boundary
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x2f6420 TESObjectREFR::Function2f6420

#include "include/2f6420/TESObjectREFR_2f6420.h"

bool TESObjectREFR::Function2f6420()
{
    if (!loadedData)
        return AddChange(2);
    bool changed = loadedData->changeRecorded;
    if (!changed) {
        changed = AddChange(2);
        if (changed)
            loadedData->changeRecorded = true;
    }
    return changed;
}
