// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1ab430 TES::HasBufferedCell
// Adapted bodies: none
#include "TES_1ab430.h"

bool TES::HasBufferedCell(TESObjectCELL* cell)
{
    for (std::uint32_t i = 0; i < gBufferedCellCount; ++i) {
        if (interiorBuffer[i] == cell) {
            return true;
        }
    }
    return false;
}
