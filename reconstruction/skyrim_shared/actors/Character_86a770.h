// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// Character, Character::sub_1407BE6E0: CRASHLOGGER_PDB(59818@2026.10.24)
// BoundsData86a770, BoundsData86a770::Apply, Character::GetBoundsData: GUESS(low)
#pragma once

#include <cstdint>

struct BoundsData86a770
{
    void Apply(void* a_arg);

    std::uint64_t unk00[4];
};
static_assert(sizeof(BoundsData86a770) == 0x20, "BoundsData86a770 size");

class Character
{
public:
    void GetBoundsData(BoundsData86a770& a_out) const;
    void sub_1407BE6E0(void* a_arg) const;
};
