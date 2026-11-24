// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2f3da0 TESObjectREFR::IsInInteriorOrOutsideWorld
// Adapted bodies: none
#include "TESObjectREFR_2f3da0.h"

bool TESObjectREFR::IsInInteriorOrOutsideWorld() const
{
    bool result = true;
    if (const auto* cell = parentCell) {
        result &= cell->cellFlags;
    } else if (const auto* saveCell = GetSaveParentCell()) {
        if (!saveCell->IsInteriorCell() && saveCell->worldSpace) {
            result = false;
        }
    }
    return result;
}
