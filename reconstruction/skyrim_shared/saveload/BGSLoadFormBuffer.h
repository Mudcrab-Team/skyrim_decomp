// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BGSLoadFormBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSLoadFormBuffer::GetVersion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown28: GUESS(low)
#pragma once

#include <cstdint>
#include "BGSLoadGameBuffer.h"

class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
public:
    virtual std::uint8_t GetVersion();  // compared: 0x637580

    std::uint8_t unknown28[0x23];  // 28
    // version: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint8_t version;  // 4b
    std::uint8_t unknown4c[0x4];  // 4c
};
static_assert(sizeof(BGSLoadFormBuffer) == 0x50, "BGSLoadFormBuffer size");
