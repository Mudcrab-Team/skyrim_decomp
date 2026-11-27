// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// CombatAnimation: STANDIN GUESS(low)
// CombatAnimation::Function80e1a0: GUESS(low)
// CombatAnimation::state: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class CombatAnimation
{
public:
    // Only the observed virtual prefix is declared; remaining slots are unknown.
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    void Function80e1a0();
    std::uint8_t unknown08[80];
    std::uint32_t state;
};
static_assert(offsetof(CombatAnimation, state) == 88, "field offset");
