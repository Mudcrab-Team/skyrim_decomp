// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CompactingStore, Store: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RemoveFreeBlock: CRASHLOGGER_PDB(59818@2026.10.24)
// FreeBlock, prev, next, smallFreeLists, largeFreeList, currentFreeBlock, numFreeBlocks, unk00, unk258, unk294: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

namespace CompactingStore
{
    struct FreeBlock
    {
        std::uint64_t unk00;  // 00
        FreeBlock*    prev;   // 08
        FreeBlock*    next;   // 10
    };

    class Store
    {
    public:
        void RemoveFreeBlock(FreeBlock* block, std::size_t size);

        std::uint8_t  unk00[0x38];         // 000
        FreeBlock*    smallFreeLists[66];  // 038
        FreeBlock*    largeFreeList;       // 248
        FreeBlock*    currentFreeBlock;    // 250
        std::uint8_t  unk258[0x38];        // 258
        std::uint32_t numFreeBlocks;       // 290
        std::uint8_t  unk294[0xC];         // 294
    };
    static_assert(sizeof(Store) == 0x2A0, "CompactingStore::Store size");
    static_assert(offsetof(Store, largeFreeList) == 0x248, "largeFreeList offset");
    static_assert(offsetof(Store, numFreeBlocks) == 0x290, "numFreeBlocks offset");
}
