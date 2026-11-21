// Source exposure: mixed (the pinned image listing and local layout guesses).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// NiPSysBoundUpdateModifier, NiPSysBoundUpdateModifier::Functionfa8520: GUESS(low)
// Functionfa11c0: GUESS(low); declared only, takes the modifier and the new target
// unk00, m_boundTarget, BoundTargetLayout::flag: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct BoundTargetLayout
{
    std::uint8_t unknown[0x191];
    std::uint8_t flag;
};

class NiPSysBoundUpdateModifier
{
public:
    void Functionfa8520(std::uint8_t* a_target);  // compared: 0xfa8520
private:
    std::uint8_t unk00[0x20];
    BoundTargetLayout* m_boundTarget;
};
