// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageDataCustom.cpp:192
// TESCustomPackageData, TESCustomPackageData::GetName, BGSPackageDataList::GetUIDForData, BGSPackageDataNameMap::GetName: SIBLING(fo4-private@1b765c70, author-permission)
// TESCustomPackageData::data, TESCustomPackageData::nameMap, BGSPackageDataList, BGSPackageDataNameMap, TESPackageData, IPackageData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); nameMap is a raw pointer here where NG has a smart pointer
// unknown00, unknown10, unknown2c, unknown30: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class IPackageData;

class TESPackageData
{
public:
    virtual ~TESPackageData();  // 00
};

class BGSPackageDataList
{
public:
    std::uint8_t GetUIDForData(const IPackageData* a_data) const;

    std::uint8_t unknown00[0x18];  // 00
};
static_assert(sizeof(BGSPackageDataList) == 0x18, "BGSPackageDataList size");

class BGSPackageDataNameMap
{
public:
    const char* GetName(std::uint8_t a_uid) const;
};

class TESCustomPackageData : public TESPackageData
{
public:
    const char* GetName(const IPackageData* a_data) const;

    BGSPackageDataList data;           // 08
    std::uint8_t unknown20[0x8];       // 20
    BGSPackageDataNameMap* nameMap;    // 28
    std::uint8_t unknown30[0x10];      // 30
};
static_assert(sizeof(TESCustomPackageData) == 0x40, "TESCustomPackageData size");
