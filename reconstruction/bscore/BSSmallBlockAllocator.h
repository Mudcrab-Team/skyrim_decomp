// Code origin: original drafting by Hinkiii with claude-sonnet-5-5 from a local listing of the pinned image; class layout, member names and
// declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSSmallBlockAllocator, BSSmallBlockAllocator::TryAllocateImpl, BSSmallBlockAllocator::ContainsBlockImpl, BSSmallBlockAllocator::Size, BSSmallBlockAllocator::~BSSmallBlockAllocator, BSSmallBlockAllocator::GetMemoryStats, BSSmallBlockAllocator::AllocateAlignImpl, BSSmallBlockAllocator::DeallocateAlignImpl, IMemoryStoreBase::~IMemoryStoreBase, IMemoryStoreBase::Size, IMemoryStoreBase::GetMemoryStats, IMemoryStoreBase::ContainsBlockImpl, IMemoryStore::~IMemoryStore, IMemoryStore::AllocateAlignImpl, IMemoryStore::DeallocateAlignImpl, IMemoryStore::TryAllocateImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// IMemoryStoreBase, IMemoryStore, MemoryStats: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSCriticalSection, CRITICAL_SECTION, BSSmallBlockAllocatorUtil::FreeBlock, BSSmallBlockAllocatorUtil::BlockPage, BSSmallBlockAllocatorUtil::Pool, BlockPageInternal, BSSmallBlockAllocator::Pool, BSSmallBlockAllocator::MegaBlockPage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSSmallBlockAllocator::pools, BSSmallBlockAllocator::lock, BSSmallBlockAllocator::addressSpaceSize, BSSmallBlockAllocator::pad1234, BSSmallBlockAllocator::allocBase, BSSmallBlockAllocator::blockPageCommitMin, BSSmallBlockAllocator::blockPageCommit, BSSmallBlockAllocator::megaBlockPageList, BSSmallBlockAllocator::megaBlockCurrAlloc, BSSmallBlockAllocator::totalFreeBlockPages, BSSmallBlockAllocator::allowDecommits, BSSmallBlockAllocator::pad1265, BSSmallBlockAllocator::pad1266: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSSmallBlockAllocator::AllocateInternal: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct MemoryStats;

struct CRITICAL_SECTION
{
    void* debugInfo;
    std::int32_t lockCount;
    std::int32_t recursionCount;
    void* owningThread;
    void* lockSemaphore;
    std::uintptr_t spinCount;
};

class BSCriticalSection
{
public:
    CRITICAL_SECTION criticalSection;  // 00
};
static_assert(sizeof(BSCriticalSection) == 0x28, "BSCriticalSection size");

class IMemoryStoreBase
{
public:
    virtual ~IMemoryStoreBase();  // 00
    virtual std::size_t Size(const void* a_mem) const = 0;  // 01
    virtual void GetMemoryStats(MemoryStats* a_stats) = 0;  // 02
    virtual bool ContainsBlockImpl(const void* a_block) const = 0;  // 03
};
static_assert(sizeof(IMemoryStoreBase) == 0x8, "IMemoryStoreBase size");

class IMemoryStore : public IMemoryStoreBase
{
public:
    ~IMemoryStore() override;  // 00
    virtual void* AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) = 0;  // 04
    virtual void DeallocateAlignImpl(void*& a_block) = 0;  // 05
    virtual void* TryAllocateImpl(std::size_t a_size, std::uint32_t a_alignment);  // 06
};
static_assert(sizeof(IMemoryStore) == 0x8, "IMemoryStore size");

namespace BSSmallBlockAllocatorUtil
{
    struct FreeBlock
    {
        FreeBlock* next;  // 0
    };
    static_assert(sizeof(FreeBlock) == 0x8, "FreeBlock size");

    struct BlockPage
    {
        BlockPage* left;  // 00
        BlockPage* right;  // 08
        FreeBlock* blocks;  // 10
        std::uint16_t totalElem;  // 18
        std::uint16_t freeElem;  // 1A
        std::uint32_t pad1C;  // 1C
    };
    static_assert(sizeof(BlockPage) == 0x20, "BlockPage size");

    struct Pool
    {
        BlockPage* pageList;  // 00
        BlockPage* currAlloc;  // 08
        std::uint32_t totalFreeBlocks;  // 10
        std::uint32_t totalAllocatedBlocks;  // 14
        std::uint32_t totalBytes;  // 18
        std::uint32_t elementSize;  // 1C
        BSCriticalSection lock;  // 20
    };
    static_assert(sizeof(Pool) == 0x48, "Pool size");
}

struct BlockPageInternal
{
    BlockPageInternal* left;  // 00
    BlockPageInternal* right;  // 08
    BSSmallBlockAllocatorUtil::FreeBlock* blocks;  // 10
    std::uint16_t totalElem;  // 18
    std::uint16_t freeElem;  // 1A
    std::uint16_t elemSize;  // 1C
    std::uint16_t check;  // 1E
};
static_assert(sizeof(BlockPageInternal) == 0x20, "BlockPageInternal size");

class BSSmallBlockAllocator : public IMemoryStore
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

    ~BSSmallBlockAllocator() override;  // 00
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
static_assert(sizeof(BSSmallBlockAllocator) == 0x1268, "BSSmallBlockAllocator size");
static_assert(offsetof(BSSmallBlockAllocator, allocBase) == 0x1238, "allocBase offset");
static_assert(offsetof(BSSmallBlockAllocator, blockPageCommit) == 0x1248, "blockPageCommit offset");
