// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// ExtraMapMarker, BSExtraData, MapMarkerData, TESFullName, TESFullName::~TESFullName, mapData: CRASHLOGGER_PDB(59818@2026.10.24); listed name ExtraMapMarker::Create disagrees with destructor behavior
// next, unknown00, unknown10: GUESS(low)
#pragma once

#include <cstdint>

class TESFullName
{
public:
    ~TESFullName();

    std::uint64_t unknown00;
    std::uint64_t unknown08;
};

class MapMarkerData : public TESFullName
{
public:
    std::uint64_t unknown10;
};
static_assert(sizeof(MapMarkerData) == 0x18, "MapMarkerData size");

class BSExtraData
{
public:
    virtual ~BSExtraData() {}

    BSExtraData* next;  // 08
};

class ExtraMapMarker : public BSExtraData
{
public:
    ~ExtraMapMarker() override;  // compared: 0x181150

    MapMarkerData* mapData;  // 10
};
static_assert(sizeof(ExtraMapMarker) == 0x18, "ExtraMapMarker size");
