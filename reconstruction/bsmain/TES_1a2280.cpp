// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1a2280 TES::SwapBufferedCell
// Adapted bodies: none
#include "TES_1a2280.h"

void TES::SwapBufferedCell(TESObjectCELL* cell, std::uint32_t slot)
{
    std::uint32_t count = gBufferedCellCount;
    if (slot < count) {
        for (std::uint32_t i = 0; i < count; ++i) {
            if (interiorBuffer[i] == cell) {
                if (i != slot) {
                    interiorBuffer[i] = interiorBuffer[slot];
                    interiorBuffer[slot] = cell;
                }
                return;
            }
        }
    }
}
