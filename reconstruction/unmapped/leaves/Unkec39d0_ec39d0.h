// Source exposure: binary-analysis (pinned-image observations and image RTTI).
// Code origin: original polymorphic reconstruction with provisional method signatures.
// SPDX-License-Identifier: CC0-1.0
// Unkec39d0: STANDIN GUESS(low)
// Unkec39d0::~Unkec39d0, Unkec39d0::Unk_01, Unkec39d0::Unk_02, Unkec39d0::Unk_03, Unkec39d0::Unk_04, Unkec39d0::Unk_05, Unkec39d0::Unk_06, Unkec39d0::Unk_07, Unkec39d0::Unk_08, Unkec39d0::Unk_09, Unkec39d0::~Unkec39d0, Unkec39d0::handle: GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
#include <Windows.h>

class Unkec39d0
{
public:
    virtual ~Unkec39d0();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    std::uint8_t unknown8[8];
    HANDLE handle;
    std::uint8_t unknown18[8];
};
static_assert(offsetof(Unkec39d0, handle) == 16, "member position");
static_assert(sizeof(Unkec39d0) == 32, "observed class size");
