// Source exposure: mixed (local binary analysis and public names).
// 0x80a2f0 compared function
// 0x80a280 compared function
// SPDX-License-Identifier: CC0-1.0
// Code origin: bodies written from the pinned image listing; class name from image RTTI
// Adapted bodies: none
// CombatAimController: EXE_RTTI
// Slot6, flags3C, aimValue, aimCount, gAimDefault: GUESS(low) STANDIN
#pragma once

#include <cstdint>

extern float gAimDefault;

class CombatAimController
{
public:
    virtual std::uint8_t Slot6() const;
    void Function80a280();   // compared: 0x80a280
    void Function80a2f0();   // compared: 0x80a2f0

    std::uint64_t unk08[6];  // 08 .. 37
    std::uint32_t unk38;     // 38 .. 3b
    std::uint32_t flags3C;   // 3c
    float aimValue;          // 40
    std::int32_t aimCount;   // 44
};
static_assert(sizeof(CombatAimController) == 0x48, "size observed from the listed member offsets");
