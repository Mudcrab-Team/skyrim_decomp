// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/ExtraData/MapMarkerData.cpp:54
// Base form: shared header declarations/BaseFormComponent.h for BaseFormComponent.
// MapMarkerData, MapMarkerData::locationName, MapMarkerData::flags, MapMarkerData::type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// MapMarkerData::Compare, TESFullName::CompareComponent: SIBLING(fo4-private@1b765c70, author-permission)
// TESFullName, TESFullName::fullName: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/BaseFormComponent.h"

class TESFullName : public BaseFormComponent
{
public:
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(BaseFormComponent* a_rhs) override;
    virtual std::uint32_t GetFullNameLength() const;
    virtual const char* GetFullName() const;
    bool CompareComponent(const TESFullName* a_rhs) const;

    const char* fullName;  // 08
};
static_assert(sizeof(TESFullName) == 0x10, "TESFullName size");

class MapMarkerData
{
public:
    bool Compare(const MapMarkerData* a_rhs) const;

    TESFullName locationName;  // 00
    std::uint8_t flags;        // 10
    std::uint8_t pad11;        // 11
    std::uint16_t type;        // 12
    std::uint32_t pad14;       // 14
};
static_assert(sizeof(MapMarkerData) == 0x18, "MapMarkerData size");
