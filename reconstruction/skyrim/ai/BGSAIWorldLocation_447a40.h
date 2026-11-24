// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAIWorldLocation, Function447a40, unk00, unk08, unk10, unk18, unk20, unk28, unk30, unk38, GetCell, GetLocationWorldSpace, unk40: GUESS(low)
// TESObjectREFR, TESObjectCELL: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR::parentCell, TESObjectCELL::cellFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED
// TESObjectREFR::GetWorldSpace: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include <cstdint>
#include <cstddef>

class TESWorldSpace;

class TESObjectCELL
{
public:
    std::uint8_t unk00[0x40];
    std::uint8_t cellFlags;
};

class TESObjectREFR
{
public:
    std::uint8_t unk00[0x60];
    TESObjectCELL* parentCell;

    TESWorldSpace* GetWorldSpace() const;
};

class BGSAIWorldLocation
{
public:
    virtual void unk00();
    virtual void unk08();
    virtual void unk10();
    virtual void unk18();
    virtual void unk20();
    virtual void unk28();
    virtual void unk30();
    virtual void unk38();
    virtual TESObjectCELL* GetCell() const;
    virtual TESWorldSpace* GetLocationWorldSpace() const;

    bool Function447a40(const TESObjectREFR* a_ref) const;  // compared: 0x447a40
};
