// Source exposure: mixed (the pinned image listing; no community declaration for this function).
// 0x1535f90 compared function
// SPDX-License-Identifier: CC0-1.0
// Code origin: original; the pinned image listing only
// 0x1535f80 BSParticleShaderCollisionEmitter::Function1535f80
// Adapted bodies: none
// ptrEE8 (pointer array), unk000, flagsEF2: GUESS(low)
// BSParticleShaderCollisionEmitter::Function1535f80, unk000, flagsEF2: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSParticleShaderCollisionEmitter
{
public:
    std::uint16_t Function1535f80() const;  // compared: 0x1535f80
    void* Function1535f90(std::uint32_t a_index);

    std::uint8_t unk000[0xEE8];  // 000
    // Pointer to an array of void* indexed by a_index; name is a guess from the load-then-index pattern.
    void** ptrEE8;  // EE8
    std::uint8_t unkEF0[2];  // EF0
    std::uint16_t flagsEF2;  // EF2
};
static_assert(sizeof(BSParticleShaderCollisionEmitter) == 0xEF8, "BSParticleShaderCollisionEmitter size");
