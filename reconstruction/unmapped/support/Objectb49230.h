// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// PrimaryBaseb49230, SecondaryBaseb49230, Objectb49230, Slot0, unk08, unk0C, unk10, unk18, unk1C, unk28, unk29, arg1, arg2: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct PrimaryBaseb49230
{
    virtual ~PrimaryBaseb49230();

    std::uint32_t unk08;  // 0x08
    std::uint32_t unk0C;  // 0x0C
    void* unk10;          // 0x10
    std::uint32_t unk18;  // 0x18
    std::uint32_t unk1C;  // 0x1C
};
static_assert(sizeof(PrimaryBaseb49230) == 0x20, "PrimaryBaseb49230 size");

struct SecondaryBaseb49230
{
    virtual void Slot0();
};
static_assert(sizeof(SecondaryBaseb49230) == 0x8, "SecondaryBaseb49230 size");

class Objectb49230 : public PrimaryBaseb49230, public SecondaryBaseb49230
{
public:
    Objectb49230(std::uint32_t arg1, std::uint8_t arg2);

    std::uint8_t unk28;  // 0x28
    std::uint8_t unk29;  // 0x29
};
static_assert(offsetof(Objectb49230, unk28) == 0x28, "unk28 offset");
static_assert(offsetof(Objectb49230, unk29) == 0x29, "unk29 offset");
