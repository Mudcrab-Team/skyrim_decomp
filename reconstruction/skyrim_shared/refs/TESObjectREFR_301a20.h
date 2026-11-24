// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESObjectREFR::extraList, TESObjectREFR::GetBaseObject, TESBoundObject, BSExtraData, ExtraDataList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR::Function301a20, ExtraDataList::GetMultiBoundMarkerData, MarkerBases, MarkerBases::IsMarkerBase, MarkerBases::first, MarkerBases::second, gMarkerBases, pad00, pad48, pad08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESBoundObject;
class BSExtraData;

class ExtraDataList
{
public:
    BSExtraData* GetMultiBoundMarkerData() const;
};

// Two base forms 16 bytes apart in one data object.
struct MarkerBases
{
    bool IsMarkerBase(const TESBoundObject* a_base) const { return a_base == first || a_base == second; }

    TESBoundObject* first;  // 00
    std::uint8_t pad08[8];
    TESBoundObject* second;  // 10
};

extern MarkerBases gMarkerBases;  // data at 0x31df240

class TESObjectREFR
{
public:
    TESBoundObject* GetBaseObject() const { return objectReference; }
    BSExtraData* Function301a20() const;  // compared: 0x301a20

    std::uint8_t pad00[0x40];
    TESBoundObject* objectReference;  // 40
    std::uint8_t pad48[0x28];
    ExtraDataList extraList;  // 70
};
static_assert(offsetof(TESObjectREFR, extraList) == 0x70, "TESObjectREFR::extraList offset");
