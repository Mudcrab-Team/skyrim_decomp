// Build id: sse-steam-1-7-104. Source exposure: mixed (community declarations; FNV sibling shapes; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Labels: v2
// TESWorldSpace, parentUseFlags, parentWorld, model: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); file-local view with padding in place of the bases
// TESModel, GetModel: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); virtual slot 04, slots 00 to 03 are placeholders
// Slot01, Slot02, Slot03: GUESS(low); placeholders that keep GetModel on slot 04
// GetParentWorld, GetParentUseFlag: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); same-named FNV methods, here with a bit-index flag argument
// GetMapModel: GUESS(low); the skeleton name; the sibling's same-role method is GetWorldMapData
// kDefaultMapModel: GUESS(low); default model path array read by address
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesworldspace.cpp:75
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesworldspace.cpp:880
#pragma once

#include <cstdint>

class TESModel
{
public:
    virtual ~TESModel();  // 00
    virtual void Slot01();  // 01
    virtual void Slot02();  // 02
    virtual void Slot03();  // 03
    virtual const char* GetModel() const;  // 04

    std::uint8_t pad08[0x18];
};
static_assert(sizeof(TESModel) == 0x20, "TESModel size");

extern const char kDefaultMapModel[];

class TESWorldSpace
{
public:
    const char* GetMapModel();
    TESWorldSpace* GetParentWorld(std::uint32_t a_flag);
    bool GetParentUseFlag(std::uint32_t a_flag) const;

    std::uint8_t   pad00[0x30];
    TESModel       model;  // 30
    std::uint8_t   pad50[0x52];
    std::uint16_t  parentUseFlags;  // A2
    std::uint8_t   padA4[0xB4];
    TESWorldSpace* parentWorld;  // 158
};
static_assert(sizeof(TESWorldSpace) == 0x160, "TESWorldSpace file-local view size");
