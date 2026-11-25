// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GridCell.cpp:70
// 0x227190 GridCellArray::Set
// CI hash: 0x227190 ?Set@GridCellArray@@QEAAXIIPEAVTESObjectCELL@@@Z
#include "GridCellArray_227190.h"

void GridCellArray::Set(std::uint32_t a_x, std::uint32_t a_y, TESObjectCELL* a_cell)
{
    if (a_cell) {
        std::uint32_t dimension = length;
        TESObjectCELL** slot;
        if (a_x >= dimension || a_y >= dimension)
            slot = nullptr;
        else
            slot = &cells[a_y + dimension * a_x];
        *slot = a_cell;
    } else {
        ClearItem(a_x, a_y);
    }
}
