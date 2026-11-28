// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj28e3b0, Obj28e3b0::Function28e3b0, g_allocContext_tls_0x768, Payload28e3b0: GUESS(low)
#pragma once

#include <cstdint>

extern __declspec(thread) std::uint32_t g_allocContext_tls_0x768;

struct Payload28e3b0
{
    std::uint8_t unk00[0x1C];  // 0x00
};

static_assert(sizeof(Payload28e3b0) == 0x1C, "Payload28e3b0 size");

class Obj28e3b0
{
public:
    void Function28e3b0();

    Payload28e3b0* payload;  // 0x00
};
