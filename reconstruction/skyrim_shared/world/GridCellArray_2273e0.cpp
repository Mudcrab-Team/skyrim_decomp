// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GridCell.cpp:210
// 0x2273e0 GridCellArray::MoveItem
// CI hash: 0x2273e0 ?MoveItem@GridCellArray@@UEAAXIIII@Z
#include "GridCellArray_2273e0.h"

void GridCellArray::MoveItem(std::uint32_t a_fromX, std::uint32_t a_fromY, std::uint32_t a_toX, std::uint32_t a_toY)
{
    std::uint32_t dimension = length;
    TESObjectCELL** src = a_fromX >= dimension || a_fromY >= dimension ? nullptr : &cells[a_fromY + dimension * a_fromX];
    if (a_toX < dimension && a_toY < dimension) {
        if (src)
            cells[a_toY + a_toX * dimension] = *src;
        else
            ClearItem(a_toX, a_toY);
    }
}
