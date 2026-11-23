// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TES, TES::interiorBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TES::HasBufferedCell, gBufferedCellCount: GUESS(low); the global is at RVA 0x2077750
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectCELL;

extern std::uint32_t gBufferedCellCount;

class TES
{
public:
    bool HasBufferedCell(TESObjectCELL* cell);  // compared: 0x1ab430

    std::uint8_t pad00[0xC8];
    TESObjectCELL** interiorBuffer;  // 0xC8
};
