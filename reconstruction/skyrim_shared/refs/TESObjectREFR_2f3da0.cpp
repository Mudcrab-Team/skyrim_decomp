// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2f3da0 TESObjectREFR::Function2f3da0
// Adapted bodies: none
#include "TESObjectREFR_2f3da0.h"

bool TESObjectREFR::Function2f3da0() const
{
    bool result = true;
    if (parentCell) {
        result &= parentCell->cellFlags;
    } else {
        TESObjectCELL* cell = GetSaveParentCell();
        if (cell && !(cell->cellFlags & 1) && cell->worldSpace) {
            result = false;
        }
    }
    return result;
}
