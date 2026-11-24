// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2f0b70 TESObjectREFR::GetReferencePositionInSpace
// Adapted bodies: none
#include "TESObjectREFR_2f0b70.h"

// SelectSpace: GUESS(low)
inline TESForm* SelectSpace(TESForm* a_world, TESForm* a_cell)
{
    return a_world == nullptr ? a_cell : a_world;
}

TESForm* TESObjectCELL::GetCellSpace()
{
    return SelectSpace(IsInteriorCell() ? nullptr : worldSpace, this);
}

ReferencePositionInSpace& TESObjectREFR::GetReferencePositionInSpace(const TESObjectREFR& a_ref, ReferencePositionInSpace& a_out)
{
    TESForm* space;
    if (auto* cell = a_ref.parentCell) {
        space = cell->GetCellSpace();
    } else {
        const auto* persistent = a_ref.extraList.GetPersistentCell();
        space = persistent && !persistent->IsInteriorCell() ? persistent->worldSpace : nullptr;
    }

    a_out.position.x = a_ref.position.x;
    a_out.position.y = a_ref.position.y;
    a_out.position.z = a_ref.position.z;
    a_out.space = space;
    return a_out;
}
