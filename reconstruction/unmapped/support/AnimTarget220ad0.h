// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// TargetSlot220ad0, TargetEntry220ad0, AnimTarget220ad0, FindTargetFlag, flag19, name, count, slots, entries: GUESS(low)
#pragma once

#include <cstdint>

extern "C" __declspec(dllimport) int __cdecl _stricmp(const char* lhs, const char* rhs);

struct TargetSlot220ad0
{
    std::uint8_t unk00[0x19];  // 00
    std::uint8_t flag19;       // 19
    std::uint8_t unk1A[6];     // 1A
};

static_assert(sizeof(TargetSlot220ad0) == 0x20, "TargetSlot220ad0 size");

struct TargetEntry220ad0
{
    const char* name;         // 00
    std::uint64_t unk08[4];   // 08
};

static_assert(sizeof(TargetEntry220ad0) == 0x28, "TargetEntry220ad0 size");

class AnimTarget220ad0
{
public:
    std::uint8_t FindTargetFlag(const char* targetName, std::uint32_t* outIndex) const;

    std::uint8_t unk00[0x18];    // 00
    std::uint32_t count;         // 18
    TargetSlot220ad0* slots;     // 20
    TargetEntry220ad0* entries;  // 28
};
