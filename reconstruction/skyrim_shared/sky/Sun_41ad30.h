// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sun::GetSunOcclusionPercent: CRASHLOGGER_PDB(59818@2026.10.24); name only
// Sun, SunData, unk50, occlusion, g_threadMarker_tls_0x768: STANDIN GUESS(low); only what the function reads; the thread-local marker is a per-thread value at offset 0x768 of the thread block
#pragma once

#include <cstdint>
#include <cstddef>

struct SunData
{
    std::uint8_t unk00[0x68];
    float occlusion;  // 68
};

extern __declspec(thread) std::uint32_t g_threadMarker_tls_0x768;

class Sun
{
public:
    float GetSunOcclusionPercent();  // compared: 0x41ad30

    std::uint8_t unk00[0x50];
    SunData* unk50;  // 50
};
static_assert(offsetof(Sun, unk50) == 0x50, "layout");
