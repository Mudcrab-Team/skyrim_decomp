// Code origin: original drafting by Hinkiii from a local listing of the pinned image; class layout, member names and Stamped as a twin of matched 0xcea710 (bscore/BSSmallBlockAllocator): source copied, names replaced by placeholders.
// declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IMemoryStoreBase::Size, IMemoryStoreBase::GetMemoryStats, IMemoryStoreBase::ContainsBlockImpl, IMemoryStore::AllocateAlignImpl, IMemoryStore::DeallocateAlignImpl, IMemoryStore::TryAllocateImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// MemoryStats: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSCriticalSection, BSSmallBlockAllocatorUtil::BlockPage, BSSmallBlockAllocatorUtil::Pool: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Ownercea520: GUESS(low) STANDIN
// IMemoryStore, BlockPageInternal: GUESS(low) STANDIN
#pragma once
#include "BSSmallBlockAllocator.h"

class Ownercea520 : public IMemoryStore
{
public:
    struct Pool : public BSSmallBlockAllocatorUtil::Pool
    {
    };
    static_assert(sizeof(Pool) == 0x48, "Pool size");

    struct MegaBlockPage
    {
        char mem[sizeof(BlockPageInternal[255]) * 256];  // 000000
        BlockPageInternal blockPages[255];  // 1FE000
        MegaBlockPage* left;  // 1FFFE0
        MegaBlockPage* right;  // 1FFFE8
        BSSmallBlockAllocatorUtil::BlockPage* freeBlockPages;  // 1FFFF0
        std::uint16_t numFreeBlockPages;  // 1FFFF8
        std::uint16_t nextBlockPageAlloc;  // 1FFFFA
        bool decommitted;  // 1FFFFC
        std::uint8_t pad1FFFFD;  // 1FFFFD
        std::uint16_t pad1FFFFE;  // 1FFFFE
    };
    static_assert(sizeof(MegaBlockPage) == 0x200000, "MegaBlockPage size");

    ~Ownercea520() override;  // 00
    std::size_t Size(const void* a_block) const override;  // 01, compared: 0xcea3f0
    void GetMemoryStats(MemoryStats* a_stats) override;  // 02
    bool ContainsBlockImpl(const void* a_block) const override;  // 03, compared: 0xcea710
    void* AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) override;  // 04
    void DeallocateAlignImpl(void*& a_freeBlock) override;  // 05
    void* TryAllocateImpl(std::size_t a_size, std::uint32_t a_alignment) override;  // 06, compared: 0xcea5a0

    // address 0xcea730: the allocation routine TryAllocateImpl tail-jumps to (name and fourth argument are guesses)
    void* AllocateInternal(std::size_t a_size, std::uint32_t a_alignment, bool a_flag);

    Pool pools[64];  // 0008
    BSCriticalSection lock;  // 1208
    std::uint32_t addressSpaceSize;  // 1230
    std::uint32_t pad1234;  // 1234
    char* allocBase;  // 1238
    char* blockPageCommitMin;  // 1240
    char* blockPageCommit;  // 1248
    MegaBlockPage* megaBlockPageList;  // 1250
    MegaBlockPage* megaBlockCurrAlloc;  // 1258
    std::uint32_t totalFreeBlockPages;  // 1260
    bool allowDecommits;  // 1264
    std::uint8_t pad1265;  // 1265
    std::uint16_t pad1266;  // 1266
};
static_assert(sizeof(Ownercea520) == 0x1268, "Ownercea520 size");
static_assert(offsetof(Ownercea520, allocBase) == 0x1238, "allocBase offset");
static_assert(offsetof(Ownercea520, blockPageCommit) == 0x1248, "blockPageCommit offset");
