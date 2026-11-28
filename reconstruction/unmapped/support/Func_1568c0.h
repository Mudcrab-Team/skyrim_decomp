// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// gGeneration1568c0: GUESS(low)
// gTlsGen1568c0_tls_0x10: GUESS(low)
// gTlsOwner1568c0_tls_0x18: GUESS(low)
// gTlsCache1568c0_tls_0x20: GUESS(low)
// Func_1568c0: GUESS(low)
#pragma once

#include <cstdint>

extern std::uint32_t gGeneration1568c0;
extern __declspec(thread) std::uint32_t gTlsGen1568c0_tls_0x10;
extern __declspec(thread) const void* gTlsOwner1568c0_tls_0x18;
extern __declspec(thread) std::uint8_t gTlsCache1568c0_tls_0x20[0x5B0];

struct Func_1568c0
{
    static void SyncCache();
};
