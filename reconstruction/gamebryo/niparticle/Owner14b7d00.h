// Source exposure: mixed (the pinned image listing; no community declaration for this function).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original; the pinned image listing only Stamped as a twin of matched 0x1535f80 (gamebryo/niparticle/BSParticleShaderCollisionEmitter): source copied, names replaced by placeholders.
// Function14b7d00, Owner14b7d00: GUESS(low) STANDIN
// unk000, flagsEF2: GUESS(low) STANDIN
#pragma once
#include "BSParticleShaderCollisionEmitter.h"

class Owner14b7d00
{
public:
    std::uint16_t Function14b7d00() const;
    void* Function1535f90(std::uint32_t a_index);

    std::uint8_t unk000[0x94b0];  // 000
    std::uint16_t flagsEF2;  // EF2
};
static_assert(sizeof(Owner14b7d00) == 0x94b2, "Owner14b7d00 size");
