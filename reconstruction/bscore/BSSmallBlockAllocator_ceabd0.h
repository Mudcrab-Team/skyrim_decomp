// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSSmallBlockAllocator, MegaBlockPage, left, right, freeBlockPages, numFreeBlockPages, nextBlockPageAlloc, decommitted, blockPageCommitMin, blockPageCommit, megaBlockPageList, megaBlockCurrAlloc, totalFreeBlockPages, allowDecommits: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PopUnusedBlockPages: CRASHLOGGER_PDB(59818@2026.10.24)
// unk00, unk1FFFFD, unk1FFFFE, unk1265: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, std::size_t size, std::uint32_t freeType);

class BSSmallBlockAllocator
{
public:
    struct MegaBlockPage
    {
        std::uint8_t  unk00[0x1FFFE0];    // 000000
        MegaBlockPage* left;              // 1FFFE0
        MegaBlockPage* right;             // 1FFFE8
        void*          freeBlockPages;    // 1FFFF0
        std::uint16_t  numFreeBlockPages; // 1FFFF8
        std::uint16_t  nextBlockPageAlloc;// 1FFFFA
        bool           decommitted;       // 1FFFFC
        std::uint8_t   unk1FFFFD;         // 1FFFFD
        std::uint16_t  unk1FFFFE;         // 1FFFFE
    };
    static_assert(sizeof(MegaBlockPage) == 0x200000, "MegaBlockPage size");

    void PopUnusedBlockPages();

    std::uint8_t   unk00[0x1240];        // 0000
    char*          blockPageCommitMin;   // 1240
    char*          blockPageCommit;      // 1248
    MegaBlockPage* megaBlockPageList;    // 1250
    MegaBlockPage* megaBlockCurrAlloc;   // 1258
    std::uint32_t  totalFreeBlockPages;  // 1260
    bool           allowDecommits;       // 1264
    std::uint8_t   unk1265[0x3];         // 1265
};
static_assert(sizeof(BSSmallBlockAllocator) == 0x1268, "BSSmallBlockAllocator size");
static_assert(offsetof(BSSmallBlockAllocator, blockPageCommitMin) == 0x1240, "blockPageCommitMin offset");
