// Source exposure: binary-analysis (pinned-image observations and image RTTI).
// Code origin: original polymorphic reconstruction with provisional method signatures.
// SPDX-License-Identifier: CC0-1.0
// Unk637820: STANDIN GUESS(low)
// Unk637820::Unk_00, Unk637820::Unk_01, Unk637820::Unk637820, Unk637820::unk08, Unk637820::unk10, Unk637820::unk18, Unk637820::unk20: GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
#include <Windows.h>

class Unk637820
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    Unk637820();
    void* unk08;
    void* unk10;
    std::uint32_t unk18;
    std::uint8_t unknown1c[4];
    void* unk20;
};
static_assert(offsetof(Unk637820, unk08) == 8, "member position");
static_assert(offsetof(Unk637820, unk10) == 16, "member position");
static_assert(offsetof(Unk637820, unk18) == 24, "member position");
static_assert(offsetof(Unk637820, unk20) == 32, "member position");
static_assert(sizeof(Unk637820) == 40, "observed class size");
