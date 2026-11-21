// Source exposure: mixed (local binary analysis and public names).
// Code origin: original reconstruction written for this project from the pinned image listing; no community or sibling body adapted.
// SPDX-License-Identifier: CC0-1.0
// NiHalfSpaceBV: EXE_RTTI
// Slot00, Slot01, Slot02: GUESS(low); unknown vtable slots ahead of Slot3, which the target reaches at vtable offset 0x18
// Slot3: GUESS(low); spelling from the generator's vtable-owner and slot guess, returning the type code the target compares with 5
// Functionf3a000: GUESS(low); placeholder method spelling supplied for RVA 0xf3a000
// coefficients: GUESS(low); four consecutive scalar plane coefficients read at 0x8, 0xC, 0x10 and 0x14
#pragma once
#include <cstdint>

class NiHalfSpaceBV
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual std::uint32_t Slot3() const;

    bool Functionf3a000(const NiHalfSpaceBV& other) const;

private:
    float coefficients[4];
};
static_assert(sizeof(NiHalfSpaceBV) == 0x18, "vtable pointer and four plane coefficients");
