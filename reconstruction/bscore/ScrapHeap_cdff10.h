// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ScrapHeap, ScrapHeap::GetSuccessor, ScrapHeap::lastBlock: CRASHLOGGER_PDB(59818@2026.10.24)
// Block, sizeFlags, prev: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct Block
{
    std::size_t sizeFlags;
    Block* prev;
};

class ScrapHeap
{
public:
    Block* GetSuccessor(Block* a_block) const;

    std::uint8_t unk00[0x40];
    Block* lastBlock;
};

static_assert(sizeof(Block) == 0x10, "Block size");
static_assert(offsetof(ScrapHeap, lastBlock) == 0x40, "lastBlock offset");
