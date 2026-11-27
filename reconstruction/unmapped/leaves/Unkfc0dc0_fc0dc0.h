// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unkfc0dc0: STANDIN GUESS(low)
// Unkfc0dc0::Functionfc0dc0: GUESS(low)
// Unkfc0dc0::unk30, Unkfc0dc0::unk38, Unkfc0dc0::unk3c, Unkfc0dc0::unk40, Unkfc0dc0::unk44, Unkfc0dc0::unk48: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unkfc0dc0;
extern void CopyEmitterBase(Unkfc0dc0*, Unkfc0dc0*);
class Unkfc0dc0
{
public:
    void Functionfc0dc0(Unkfc0dc0* target);
    std::uint8_t unknown0[48];
    std::uint64_t unk30;
    std::uint32_t unk38;
    std::uint32_t unk3c;
    std::uint8_t unk40;
    std::uint8_t unknown41[3];
    std::uint32_t unk44;
    std::uint32_t unk48;
};
static_assert(offsetof(Unkfc0dc0, unk30) == 48, "field offset");
static_assert(offsetof(Unkfc0dc0, unk38) == 56, "field offset");
static_assert(offsetof(Unkfc0dc0, unk3c) == 60, "field offset");
static_assert(offsetof(Unkfc0dc0, unk40) == 64, "field offset");
static_assert(offsetof(Unkfc0dc0, unk44) == 68, "field offset");
static_assert(offsetof(Unkfc0dc0, unk48) == 72, "field offset");
