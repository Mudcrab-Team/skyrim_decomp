// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSTerrainBlock, BGSTerrainBlock::SetBlockFlag: GUESS(low)
// BlockNode, unk00, node0, node1, pad00, flags: GUESS(low); minimal stand-ins, members at 0x8, 0x10 and 0xF4 from the listing
#pragma once

#include <cstdint>

struct BlockNode
{
    std::uint8_t pad00[0xF4];
    std::uint32_t flags;
};

class BGSTerrainBlock
{
public:
    void SetBlockFlag();  // compared: 0x5117b0

    std::uint64_t unk00;
    BlockNode* node0;
    BlockNode* node1;
};
