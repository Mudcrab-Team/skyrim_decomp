// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xce60c0 CompactingStore::Store::RemoveFreeBlock
#include "Store_ce60c0.h"

// Unlinks a free block from its size bucket and clears its list pointers with a sentinel.
void CompactingStore::Store::RemoveFreeBlock(FreeBlock* block, std::size_t size)
{
    std::uint32_t bucket = static_cast<std::uint32_t>((size + 7) >> 3) - 1;
    FreeBlock** listHead = (bucket < 66) ? &smallFreeLists[bucket] : &largeFreeList;

    FreeBlock* nextBlock = block->next;
    if (nextBlock == block)
    {
        *listHead = nullptr;
    }
    else
    {
        nextBlock->prev = block->prev;
        block->prev->next = block->next;
        if (*listHead == block)
        {
            *listHead = block->next;
        }
        FreeBlock* sentinel = reinterpret_cast<FreeBlock*>(static_cast<std::uintptr_t>(0xDECAFBAD));
        block->next = sentinel;
        block->prev = sentinel;
    }

    --numFreeBlocks;
    if (block == currentFreeBlock)
    {
        currentFreeBlock = largeFreeList;
    }
}
