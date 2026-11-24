// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: ExtraMapMarker::~ExtraMapMarker follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp:1774
// ExtraMapMarker: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraMapMarker::~ExtraMapMarker: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSExtraData, BSExtraData::~BSExtraData, ::GetType, ::IsNotEqual, ::next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFullName, TESFullName::~TESFullName, ::fullName, MapMarkerData, MapMarkerData::locationName: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraMapMarker::mapData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10: GUESS(low); storage outside the cleanup view.
#pragma once

#include <cstdint>

void operator delete(void*, unsigned __int64) noexcept;

class BSExtraData
{
public:
    virtual ~BSExtraData() {}
    virtual std::uint32_t GetType() const;
    virtual bool IsNotEqual(const BSExtraData* rhs) const;

    BSExtraData* next;
};
static_assert(sizeof(BSExtraData) == 0x10, "BSExtraData size");

class TESFullName
{
public:
    virtual ~TESFullName();
    const char* fullName;
};

class MapMarkerData
{
public:
    TESFullName locationName;
    std::uint64_t unknown10;
};
static_assert(sizeof(MapMarkerData) == 0x18, "MapMarkerData size");

class ExtraMapMarker : public BSExtraData
{
public:
    ExtraMapMarker();
    ~ExtraMapMarker() override;

    MapMarkerData* mapData;
};
static_assert(sizeof(ExtraMapMarker) == 0x18, "ExtraMapMarker size");
