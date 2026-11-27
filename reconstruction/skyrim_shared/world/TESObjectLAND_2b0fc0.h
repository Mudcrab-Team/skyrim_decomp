// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectLAND: EXE_RTTI
// TESObjectLAND::GetGeometry: CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectLAND::loadedData, LoadedLandData, NiNode, NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectLAND::unk00, LoadedLandData::mesh, NiNode::unk000, NiNode::childrenData, NiNode::childrenSize: GUESS(low); offsets observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class NiAVObject;

class NiNode
{
public:
    std::uint8_t  unk000[0x118];  // 000
    NiAVObject**  childrenData;   // 118
    std::uint16_t unk120;         // 120
    std::uint16_t childrenSize;   // 122
};
static_assert(offsetof(NiNode, childrenData) == 0x118, "NiNode::childrenData offset");
static_assert(offsetof(NiNode, childrenSize) == 0x122, "NiNode::childrenSize offset");

struct LoadedLandData
{
    NiNode* mesh[4];  // 00
};

class TESObjectLAND
{
public:
    NiAVObject* GetGeometry(std::uint32_t a_quad) const;

    std::uint8_t    unk00[0x40];  // 00
    LoadedLandData* loadedData;   // 40
};
static_assert(offsetof(TESObjectLAND, loadedData) == 0x40, "TESObjectLAND::loadedData offset");
