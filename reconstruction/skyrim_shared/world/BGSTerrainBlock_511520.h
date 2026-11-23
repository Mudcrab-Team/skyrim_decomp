// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSTerrainBlock, BGSTerrainBlock::GetBlockData: GUESS(low)
// BlockNode, BlockObject, BlockData, NiRTTI, unk00, node, object, data, unk00, unk01, rttiTarget, pad00, pad78, pad48, first, second: GUESS(low); minimal stand-ins, members from the listing
#pragma once

#include <cstdint>

class NiRTTI
{
};

extern NiRTTI rttiTarget;

class BlockObject
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual const NiRTTI* GetRTTI() const;

    std::uint8_t pad00[0x70];
    struct BlockData* data;
};

struct BlockData
{
    std::uint8_t pad00[0x48];
    void* first;
    std::uint8_t pad50[0x8];
    void* second;
};

struct BlockNode
{
    std::uint8_t pad00[0x128];
    BlockObject* object;
};

class BGSTerrainBlock
{
public:
    void* GetBlockData(std::uint32_t a_which);  // compared: 0x511520

    std::uint64_t unk00;
    BlockNode* node;
};
