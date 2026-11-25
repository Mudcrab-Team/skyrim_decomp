// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSSmallBlockAllocator, BSSmallBlockAllocator::Functionceab70: GUESS(low)
// unk00, unk08, unk10, unk18, guard, InitializeCriticalSection: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct SmallLock
{
    unsigned char data[0x28];
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(SmallLock* a_section);

class BSSmallBlockAllocator
{
public:
    BSSmallBlockAllocator();

    void* unk00;
    void* unk08;
    void* unk10;
    void* unk18;
    SmallLock guard;
};
