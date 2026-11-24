// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2f3d30 TESObjectREFR::Function2f3d30
// Adapted bodies: none
#include "TESObjectREFR_2f3d30.h"

namespace
{
    // The worldspace of an exterior cell; an interior cell has none.
    TESWorldSpace* GetExteriorWorldSpace(const TESObjectCELL* a_cell)
    {
        return a_cell->IsInteriorCell() ? nullptr : a_cell->worldSpace;
    }

    // An interior cell stands for its own space.
    TESForm* GetWorldSpaceOrCell(TESObjectCELL* a_cell)
    {
        TESWorldSpace* space = GetExteriorWorldSpace(a_cell);
        return space == nullptr ? static_cast<TESForm*>(a_cell) : space;
    }
}

// The reference's worldspace, or its cell when the cell is interior; an unloaded
// reference falls back to its persistent cell's worldspace.
TESForm* TESObjectREFR::Function2f3d30() const
{
    if (parentCell) {
        return GetWorldSpaceOrCell(parentCell);
    }
    TESObjectCELL* persistent = extraList.GetPersistentCell();
    if (persistent) {
        return GetExteriorWorldSpace(persistent);
    }
    return nullptr;
}
