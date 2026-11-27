// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectLAND: EXE_RTTI
// TESObjectLAND::sub_140255420: CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectLAND::data, TESObjectLAND::parentCell, TESObjectCELL, TESObjectCELL::cellFlags, TESObjectCELL::worldSpace, TESWorldSpace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectLAND::unk00, TESObjectLAND::unk2C, TESObjectCELL::unk000, TESObjectCELL::unk041, TESWorldSpace::GetParentWorld: GUESS(low); offsets and call observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class TESWorldSpace
{
public:
    TESWorldSpace* GetParentWorld(bool a_arg1) const;
};

class TESObjectCELL
{
public:
    std::uint8_t   unk000[0x40];  // 000
    std::uint8_t   cellFlags;     // 040
    std::uint8_t   unk041[0xE7];  // 041
    TESWorldSpace* worldSpace;    // 128
};
static_assert(offsetof(TESObjectCELL, cellFlags) == 0x40, "TESObjectCELL::cellFlags offset");
static_assert(offsetof(TESObjectCELL, worldSpace) == 0x128, "TESObjectCELL::worldSpace offset");

class TESObjectLAND
{
public:
    void sub_140255420(TESObjectCELL* a_cell);

    std::uint8_t   unk00[0x28];  // 00
    std::uint32_t  data;         // 28
    std::uint32_t  unk2C;        // 2C
    TESObjectCELL* parentCell;   // 30
};
static_assert(offsetof(TESObjectLAND, data) == 0x28, "TESObjectLAND::data offset");
static_assert(offsetof(TESObjectLAND, parentCell) == 0x30, "TESObjectLAND::parentCell offset");
