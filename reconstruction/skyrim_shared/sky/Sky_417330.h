// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sky, SkyHolder, SkyTarget, SkyOther, g_skyHolder, g_skyOther, unkC0, unk48, GetSkyTargetValue: GUESS(low)
// Sky::Function417330: CRASHLOGGER_PDB(59818@2026.10.24); size and prototype shape only
#pragma once

#include <cstdint>
#include <cstddef>

struct SkyTarget;

struct SkyHolder
{
    std::uint8_t pad00[0xC0];
    SkyTarget* unkC0;  // 0xC0
};

struct SkyOther
{
    std::uint8_t pad00[0x48];
    std::int64_t unk48;  // 0x48
};

extern SkyHolder* g_skyHolder;
extern SkyOther* g_skyOther;

std::int64_t GetSkyTargetValue(SkyTarget* a_target);

class Sky
{
public:
    static std::int64_t Function417330();  // compared: 0x417330
};
