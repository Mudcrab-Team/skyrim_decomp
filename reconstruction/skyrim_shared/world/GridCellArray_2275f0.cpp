// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GridCell.cpp:224
// 0x2275f0 GridCellArray::UpdateDistantLandBlending
// CI hash: 0x2275f0 ?UpdateDistantLandBlending@GridCellArray@@QEAAXXZ
#include "GridCellArray_2275f0.h"

void GridCellArray::UpdateDistantLandBlending()
{
    std::uint32_t dimension = length;
    for (std::uint32_t i = 0; i < dimension; ++i) {
        for (std::uint32_t j = 0; j < dimension; ++j) {
            std::uint32_t currentDimension = length;
            if (i < currentDimension && j < currentDimension) {
                TESObjectCELL** cell = &cells[j + i * currentDimension];
                if (cell && *cell) {
                    TESObjectLAND* land = (*cell)->GetLand();
                    land->InitDistantTextureBlending();
                }
            }
        }
    }
}
