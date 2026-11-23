// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESObjectCELL, TESWorldSpace, NiPoint3, ExtraDataList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// parentCell, worldSpace, cellFlags, extraList, NiPoint3::x, NiPoint3::y, NiPoint3::z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraDataList::GetPersistentCell: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// IsInteriorCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR::GetReferencePositionInSpace, GetCellSpace, ReferencePositionInSpace, position, space, unk00, unk20, unk41, unk68: GUESS(low)
#pragma once

#include "declarations/TESForm.h"

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct ReferencePositionInSpace
{
    NiPoint3 position;
    TESForm* space;
};

class TESWorldSpace : public TESForm {};

class TESObjectCELL : public TESForm
{
public:
    bool IsInteriorCell() const { return (cellFlags & 1) != 0; }

    TESForm* GetCellSpace();

    std::uint8_t unk20[0x20];
    std::uint8_t cellFlags;
    std::uint8_t unk41[0xE7];
    TESWorldSpace* worldSpace;
};

class ExtraDataList
{
public:
    TESObjectCELL* GetPersistentCell() const;
    std::uint8_t unk00[8];
};

class TESObjectREFR
{
public:
    static ReferencePositionInSpace& GetReferencePositionInSpace(const TESObjectREFR& a_ref, ReferencePositionInSpace& a_out);

    std::uint8_t unk00[0x54];
    NiPoint3 position;
    TESObjectCELL* parentCell;
    std::uint8_t unk68[8];
    ExtraDataList extraList;
};
