// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: reconstruction from pinned-image observations; see Adapted bodies.
// Adapted bodies: TestBit, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// SPDX-License-Identifier: CC0-1.0
// Archive, Archive::QLoadStrings: CRASHLOGGER_PDB(59818@2026.10.24)
// archiveFlags, gForceLoadStrings, gForceLoadStrings2, gStringMode1, gStringMode2, gStringMode3: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

extern bool gForceLoadStrings;
extern bool gForceLoadStrings2;
extern std::int32_t gStringMode1;
extern std::int32_t gStringMode2;
extern std::int32_t gStringMode3;

class Archive
{
public:
    bool QLoadStrings() const;

    std::uint8_t unk00[0x19C];
    std::uint32_t archiveFlags;
};

static_assert(offsetof(Archive, archiveFlags) == 0x19C, "archiveFlags offset");
