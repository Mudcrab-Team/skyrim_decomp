// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSSmallBlockAllocator, BlockPageInternal, MegaBlockPage, left, right, blocks, totalElem, freeElem, elemSize, check, freeBlockPages, numFreeBlockPages, nextBlockPageAlloc, decommitted, megaBlockPageList, megaBlockCurrAlloc, totalFreeBlockPages: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PushFreeBlockPage, unk00, unk1FFFFD, unk1FFFFE, unk1264: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BSSmallBlockAllocator
{
public:
    struct BlockPageInternal
    {
        BlockPageInternal* left;       // 00
        BlockPageInternal* right;      // 08
        void*              blocks;     // 10
        std::uint16_t      totalElem;  // 18
        std::uint16_t      freeElem;   // 1A
        std::uint16_t      elemSize;   // 1C
        std::uint16_t      check;      // 1E
    };
    static_assert(sizeof(BlockPageInternal) == 0x20, "BlockPageInternal size");

    struct MegaBlockPage
    {
        std::uint8_t       unk00[0x1FFFE0];    // 000000
        MegaBlockPage*     left;               // 1FFFE0
        MegaBlockPage*     right;              // 1FFFE8
        BlockPageInternal* freeBlockPages;     // 1FFFF0
        std::uint16_t      numFreeBlockPages;  // 1FFFF8
        std::uint16_t      nextBlockPageAlloc; // 1FFFFA
        bool               decommitted;        // 1FFFFC
        std::uint8_t       unk1FFFFD;          // 1FFFFD
        std::uint16_t      unk1FFFFE;          // 1FFFFE
    };
    static_assert(sizeof(MegaBlockPage) == 0x200000, "MegaBlockPage size");

    void PushFreeBlockPage(BlockPageInternal* page, MegaBlockPage* megaPage);

    std::uint8_t   unk00[0x1250];        // 0000
    MegaBlockPage* megaBlockPageList;    // 1250
    MegaBlockPage* megaBlockCurrAlloc;   // 1258
    std::uint32_t  totalFreeBlockPages;  // 1260
    std::uint32_t  unk1264;              // 1264
};
static_assert(sizeof(BSSmallBlockAllocator) == 0x1268, "BSSmallBlockAllocator size");
static_assert(offsetof(BSSmallBlockAllocator, megaBlockPageList) == 0x1250, "megaBlockPageList offset");
