// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Entry156770: GUESS(low)
// Func_156770: GUESS(low)
#pragma once

#include <cstdint>

struct Entry156770
{
    virtual void VFunc00() {}
    virtual std::uint32_t GetSlotIndex() = 0;
};

extern __declspec(thread) void* g_tlsOwner156770_tls_0x18;
extern __declspec(thread) Entry156770* g_tlsSlots156770_tls_0x20[182];

struct Func_156770
{
    static void CacheEntry(void* owner, Entry156770* entry);
};
