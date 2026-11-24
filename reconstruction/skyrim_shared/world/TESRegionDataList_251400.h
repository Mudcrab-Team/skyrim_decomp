// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegionDataList.cpp:200
// TESRegionDataList, TESRegionDataList::Find: SIBLING(fo4-private@1b765c70, author-permission)
// TESRegionData, TESRegionData::GetType, TESRegionData::LoadData, TESRegionData::IsLoaded: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to the slots the list calls
// TESRegion: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque
// m_item, m_pkNext: GUESS(low); the node layout of a singly linked list, names as the sibling body uses them
// RegionDataType, kNone, a_region: GUESS(low); the id enumeration of the sibling, reduced to a stand-in
// unk20, unk28, unk30: GUESS(low)
#pragma once

#include <cstdint>

class TESRegion;

enum class RegionDataType : std::uint32_t
{
    kNone = 0
};

class TESRegionData
{
public:
    virtual ~TESRegionData();                    // 00
    virtual bool LoadDataHeader(void* a_arg1);   // 01
    virtual void LoadData(TESRegion* a_region);  // 02; NG declares TESForm*
    virtual RegionDataType GetType() const;      // 03
    virtual void unk20();                        // 04
    virtual void unk28();                        // 05
    virtual void unk30();                        // 06
    virtual bool IsLoaded() const;               // 07
};

class TESRegionDataList
{
public:
    TESRegionData* Find(RegionDataType aFind);

    TESRegionData*     m_item;    // 00
    TESRegionDataList* m_pkNext;  // 08
};
static_assert(sizeof(TESRegionDataList) == 0x10, "TESRegionDataList size");
