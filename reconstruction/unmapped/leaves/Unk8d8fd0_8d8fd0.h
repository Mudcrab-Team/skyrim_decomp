// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk8d8fd0: STANDIN GUESS(low)
// Unk8d8fd0::Function8d8fd0: GUESS(low)
// Unk8d8fd0::state: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk8d8fd0
{
public:
    virtual void Unknown0();
    virtual void Unknown1();
    virtual void Unknown2();
    virtual void Unknown3();
    virtual void Unknown4();
    virtual void Unknown5();
    virtual void Unknown6();
    virtual void Unknown7();
    virtual void Unknown8();
    virtual void Unknown9();
    virtual std::uint8_t Query();
    void Function8d8fd0();
    std::uint8_t unknown8[12];
    std::uint32_t state;
};
static_assert(offsetof(Unk8d8fd0, state) == 20, "field offset");
