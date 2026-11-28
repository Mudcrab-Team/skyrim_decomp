// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// ChildList257bf0, RegionObjBase257bf0, RegionObj257bf0, childrenList: GUESS(low)
#pragma once

#include <cstdint>

class ChildList257bf0
{
public:
    virtual ~ChildList257bf0();
};

class RegionObjBase257bf0
{
public:
    virtual ~RegionObjBase257bf0()
    {
    }
};

class RegionObj257bf0 : public RegionObjBase257bf0
{
public:
    ~RegionObj257bf0() override;

    std::uint8_t unk08[0x38];       // 08
    ChildList257bf0* childrenList;  // 40
    std::uint64_t unk48;            // 48
};

static_assert(sizeof(RegionObj257bf0) == 0x50, "RegionObj257bf0 size");
