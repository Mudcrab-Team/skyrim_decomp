// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2ad240 TESObjectLAND::sub_140255420
// Adapted bodies: none
#include "TESObjectLAND_2ad240.h"

// Sets the parent cell and updates the land flag bit based on whether its exterior worldspace has a parent.
void TESObjectLAND::sub_140255420(TESObjectCELL* a_cell)
{
    parentCell = a_cell;
    if (!a_cell) {
        return;
    }
    if ((a_cell->cellFlags & 1) == 0 && a_cell->worldSpace && a_cell->worldSpace->GetParentWorld(false)) {
        data |= 0x400;
    } else {
        data &= ~0x400u;
    }
}
