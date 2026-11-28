// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// ExtraOcclusionPlaneRefData, ExtraOcclusionPlaneRefData::~ExtraOcclusionPlaneRefData, BSExtraData, OcclusionPlaneLinkedRefData, data: CRASHLOGGER_PDB(59818@2026.10.24)
// next, unknown00: GUESS(low)
#pragma once

#include <cstdint>

struct OcclusionPlaneLinkedRefData
{
    std::uint64_t unknown00[2];
};
static_assert(sizeof(OcclusionPlaneLinkedRefData) == 0x10, "size");

class BSExtraData
{
public:
    virtual ~BSExtraData() {}

    BSExtraData* next;  // 08
};

class ExtraOcclusionPlaneRefData : public BSExtraData
{
public:
    ~ExtraOcclusionPlaneRefData() override;  // compared: 0x186320

    OcclusionPlaneLinkedRefData* data;  // 10
};
static_assert(sizeof(ExtraOcclusionPlaneRefData) == 0x18, "size");
