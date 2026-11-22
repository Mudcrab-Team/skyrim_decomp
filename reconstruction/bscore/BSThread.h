// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// 0xce4260 compared function
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSThread: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSThread::Unk_02, BSThread::Unk_01: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08, field30, g_threadCleanup: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSThread
{
public:
    virtual void Unk_02();  // compared: 0x60f1d0
    virtual std::uint32_t Unk_01();  // compared: 0xceb190
    void Functionce4260();  // compared: 0xce4260

    std::uint8_t unknown08[0x28];  // 08
    void* field30;  // 30
    std::uint8_t unknown38[0x18];  // 38
};
static_assert(sizeof(BSThread) == 0x50, "BSThread size");

extern void (*g_threadCleanup)(void* a_data);
