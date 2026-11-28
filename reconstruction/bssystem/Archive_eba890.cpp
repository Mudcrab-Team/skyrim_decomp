// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: reconstruction from pinned-image observations; see Adapted bodies.
// Adapted bodies: TestBit, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// SPDX-License-Identifier: CC0-1.0
// Archive, Archive::QLoadStrings: CRASHLOGGER_PDB(59818@2026.10.24)
// TestBit, CheckStringMode: GUESS(low)
// 0xeba890 Archive::QLoadStrings
#include "Archive_eba890.h"

namespace
{
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

inline bool CheckStringMode(std::int32_t a_mode, std::uint32_t a_flags, std::uint32_t a_bit)
{
    bool enabled;
    if (a_mode == 1)
    {
        enabled = TestBit(a_flags, a_bit);
    }
    else
    {
        enabled = (a_mode != 0);
    }
    return enabled;
}
}

// Determines whether the archive should load its string tables.
bool Archive::QLoadStrings() const
{
    if (gForceLoadStrings || gForceLoadStrings2)
    {
        return true;
    }

    std::uint32_t flags = archiveFlags;
    if (TestBit(flags, 7))
    {
        return true;
    }
    if (CheckStringMode(gStringMode1, flags, 3))
    {
        return true;
    }
    if (CheckStringMode(gStringMode2, flags, 4))
    {
        return true;
    }
    if (CheckStringMode(gStringMode3, flags, 5))
    {
        return true;
    }
    return false;
}
