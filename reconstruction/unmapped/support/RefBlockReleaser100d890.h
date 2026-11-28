// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Target100d890, RefBlock100d890, RefBlockReleaser100d890: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct Target100d890
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Release();
};

struct RefBlock100d890
{
    Target100d890* target;  // 0x00
    long refCount;          // 0x08
    std::uint32_t unk0C;    // 0x0C
};

struct RefBlockReleaser100d890
{
    void Release(RefBlock100d890* a_block);  // compared: 0x100d890
};
