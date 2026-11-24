// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TES, TES::SwapBufferedCell, gBufferedCellCount: GUESS(low)
// TES::interiorBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectCELL;

extern std::uint32_t gBufferedCellCount;

class TES
{
public:
    void SwapBufferedCell(TESObjectCELL* cell, std::uint32_t slot);  // compared: 0x1a2280

    std::uint8_t pad00[0xC8];
    TESObjectCELL** interiorBuffer;  // 0xC8
};
