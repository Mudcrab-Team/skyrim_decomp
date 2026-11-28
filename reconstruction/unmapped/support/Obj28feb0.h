// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Slot28feb0, Obj28feb0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern const char g_defaultStrA28feb0[];
extern const char g_defaultStrB28feb0[];
extern const char g_defaultStrC28feb0[];
extern const char g_defaultStrD28feb0[];

struct Slot28feb0
{
    void Init(const char* a_name)
    {
        field0C = 0;
        field10 = 0;
        field14 = 0;
        name18 = a_name;
        field28 = 0;
    }

    std::uint8_t unk00[0x0C];  // 0x00
    std::uint32_t field0C;     // 0x0C
    std::uint32_t field10;     // 0x10
    std::uint32_t field14;     // 0x14
    const char* name18;        // 0x18
    std::uint8_t unk20[0x08];  // 0x20
    std::uint64_t field28;     // 0x28
};

class Obj28feb0
{
public:
    Obj28feb0();

    Slot28feb0 slot00;         // 0x00
    Slot28feb0 slot30;         // 0x30
    Slot28feb0 slot60;         // 0x60
    std::uint64_t field90;     // 0x90
    Slot28feb0 slot98;         // 0x98
    Slot28feb0 slotC8;         // 0xC8
};

static_assert(sizeof(Slot28feb0) == 0x30, "Slot28feb0 size");
static_assert(offsetof(Obj28feb0, slot30) == 0x30, "slot30 offset");
static_assert(offsetof(Obj28feb0, slot60) == 0x60, "slot60 offset");
static_assert(offsetof(Obj28feb0, field90) == 0x90, "field90 offset");
static_assert(offsetof(Obj28feb0, slot98) == 0x98, "slot98 offset");
static_assert(offsetof(Obj28feb0, slotC8) == 0xC8, "slotC8 offset");
