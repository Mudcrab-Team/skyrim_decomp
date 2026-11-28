// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// TESRegionObject258690: CRASHLOGGER_PDB(59818@2026.10.24)
// ChildList258690, RegionObjBase258690, childrenList: GUESS(low)
#pragma once

#include <cstdint>

class ChildList258690
{
public:
    virtual ~ChildList258690();
};

class RegionObjBase258690
{
public:
    virtual ~RegionObjBase258690()
    {
    }
};

class TESRegionObject258690 : public RegionObjBase258690
{
public:
    TESRegionObject258690();
    ~TESRegionObject258690() override;

    std::uint8_t unk08[0x38];       // 08
    ChildList258690* childrenList;  // 40
    std::uint64_t unk48;            // 48
};

static_assert(sizeof(TESRegionObject258690) == 0x50, "TESRegionObject258690 size");
