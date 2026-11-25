// Source exposure: mixed (pinned image listings, project form units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations from the pinned listings using the cited layouts. Stamped as a twin of matched 0x3c90c0 (skyrim_shared/actors/TESNPC_276cc0): source copied, names replaced by placeholders.
// 0x3c97b0 Owner3c97b0::Function3c97b0
#include "Owner3c97b0.h"
#include <new>

// HeadPartBlock, HeadPartList, entries, count, next, headPartBlocks_3c97b0: GUESS(low) STANDIN
struct HeadPartBlock
{
    HeadPartBlock* next;
    std::uint8_t padding[0x1F8];
};

extern HeadPartBlock* headPartBlocks_3c97b0;

// guess: same compiled code as matched 0x3c90c0 apart from relocated fields; its role here is not established.
void Owner3c97b0::Function3c97b0()
{
    while (auto* block = headPartBlocks_3c97b0) {
        headPartBlocks_3c97b0 = block->next;
        ::operator delete(block, sizeof(HeadPartBlock));
    }
}
