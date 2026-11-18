// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BSThread: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSThread::Unk_02, BSThread::Unk_01: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSThread
{
public:
    virtual void Unk_02();  // compared: 0x60f1d0
    virtual std::uint32_t Unk_01();  // compared: 0xceb190

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown08[0x48];  // 08
};
static_assert(sizeof(BSThread) == 0x50, "BSThread size");
