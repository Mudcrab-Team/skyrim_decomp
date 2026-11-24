// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESObjectCELL, TESWorldSpace, TESForm, ExtraDataList, TESObjectCELL::IsInteriorCell, TESObjectCELL::kIsInteriorCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR::parentCell, TESObjectREFR::extraList, TESObjectCELL::cellFlags, TESObjectCELL::worldSpace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offsets read from the listing
// ExtraDataList::GetPersistentCell: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// TESObjectREFR::Function2f3d30, GetExteriorWorldSpace, GetWorldSpaceOrCell, pad00, pad42, pad68: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESForm
{
};

class TESWorldSpace : public TESForm
{
};

class TESObjectCELL : public TESForm
{
public:
    enum : std::uint16_t
    {
        kIsInteriorCell = 1 << 0
    };

    bool IsInteriorCell() const { return (cellFlags & kIsInteriorCell) != 0; }

    std::uint8_t pad00[0x40];
    std::uint16_t cellFlags;  // 040
    std::uint8_t pad42[0x128 - 0x42];
    TESWorldSpace* worldSpace;  // 128
};

class ExtraDataList
{
public:
    TESObjectCELL* GetPersistentCell() const;
};

class TESObjectREFR
{
public:
    TESForm* Function2f3d30() const;  // compared: 0x2f3d30

    std::uint8_t pad00[0x60];
    TESObjectCELL* parentCell;  // 60
    std::uint8_t pad68[8];
    ExtraDataList extraList;  // 70
};
static_assert(offsetof(TESObjectREFR, extraList) == 0x70, "TESObjectREFR::extraList offset");
