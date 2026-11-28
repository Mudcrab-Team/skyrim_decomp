// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// gGeneration156860: GUESS(low)
// gTlsGen156860_tls_0x10: GUESS(low)
// gTlsOwner156860_tls_0x18: GUESS(low)
// gTlsCache156860_tls_0x20: GUESS(low)
// Func_156860: GUESS(low)
#pragma once

#include <cstdint>

extern std::uint32_t gGeneration156860;
extern __declspec(thread) std::uint32_t gTlsGen156860_tls_0x10;
extern __declspec(thread) const void* gTlsOwner156860_tls_0x18;
extern __declspec(thread) std::uint8_t gTlsCache156860_tls_0x20[0x5B0];

struct Func_156860
{
    static void InvalidateCache(const void* owner);
};
