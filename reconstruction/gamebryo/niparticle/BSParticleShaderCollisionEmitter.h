// Source exposure: mixed (the pinned image listing; no community declaration for this function).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original; the pinned image listing only
// 0x1535f80 BSParticleShaderCollisionEmitter::Function1535f80
// Adapted bodies: none
// BSParticleShaderCollisionEmitter::Function1535f80, unk000, flagsEF2: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSParticleShaderCollisionEmitter
{
public:
    std::uint16_t Function1535f80() const;  // compared: 0x1535f80

    // unk000, flagsEF2: GUESS(low); only the returned word's offset is observed.
    std::uint8_t unk000[0xEF2];  // 000
    std::uint16_t flagsEF2;  // EF2
};
static_assert(sizeof(BSParticleShaderCollisionEmitter) == 0xEF4, "BSParticleShaderCollisionEmitter size");
