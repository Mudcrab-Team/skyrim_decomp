// MemoryHeap: GUESS(low) STANDIN
/*
 * MemoryHeap: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0xce8a10 30 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis, community-headers.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); unverified against this build.
 * No external body adapted. Stand-ins are unverified.
 */
#pragma once

/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#include <cstddef>
#include <cstdint>
// IMemoryStoreBase, IMemoryStore, IMemoryHeap, AbstractHeap, MemoryHeap, BSCriticalSection, CRITICAL_SECTION: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// MemoryHeap::Functionce8a10, LargeFreeIndex: GUESS(low) STANDIN
struct MemoryStats; struct HeapStats; class HeapBlock; class HeapBlockFreeHead;
enum class MEM_CONTEXT : std::int32_t;
struct CRITICAL_SECTION { void* debugInfo; std::int32_t lockCount; std::int32_t recursionCount; void* owningThread; void* lockSemaphore; std::uintptr_t spinCount; };
class BSCriticalSection { public: CRITICAL_SECTION criticalSection; };
class IMemoryStoreBase { public: virtual ~IMemoryStoreBase(); virtual std::size_t Size(const void*) const = 0; virtual void GetMemoryStats(MemoryStats*) = 0; virtual bool ContainsBlockImpl(const void*) const = 0; };
class IMemoryStore : public IMemoryStoreBase { public: ~IMemoryStore() override; virtual void* AllocateAlignImpl(std::size_t, std::uint32_t) = 0; virtual void DeallocateAlignImpl(void*&) = 0; virtual void* TryAllocateImpl(std::size_t, std::uint32_t); };
class IMemoryHeap : public IMemoryStore { public:
    ~IMemoryHeap() override;
    bool ContainsBlockImpl(const void*) const override; void* AllocateAlignImpl(std::size_t, std::uint32_t) override; void DeallocateAlignImpl(void*&) override;
    virtual const char* GetName() const = 0; virtual void* Allocate(std::size_t, std::uint32_t) = 0; virtual void Deallocate(void*, std::uint32_t) = 0;
    virtual bool PointerInHeap(const void*) const = 0; virtual std::size_t TotalSize(const void*) const = 0; virtual void GetHeapStats(HeapStats*, bool) = 0;
    virtual bool ShouldTrySmallBlockPools(std::size_t, MEM_CONTEXT) = 0; virtual std::uint32_t GetPageSize() const = 0;
};
class AbstractHeap : public IMemoryHeap { public:
    ~AbstractHeap() override;
    void GetMemoryStats(MemoryStats*) override; void* AllocateAlignImpl(std::size_t, std::uint32_t) override; void* TryAllocateImpl(std::size_t, std::uint32_t) override;
    const char* GetName() const override; bool PointerInHeap(const void*) const override; void GetHeapStats(HeapStats*, bool) override;
    bool ShouldTrySmallBlockPools(std::size_t, MEM_CONTEXT) override; std::uint32_t GetPageSize() const override;
    virtual void* DoHeapAllocation(std::size_t, std::size_t) = 0; virtual void DoHeapFree(void*) = 0; virtual std::size_t CreateMorePages(void*, std::size_t, std::size_t);
    virtual std::size_t CleanExtraPages(void*, std::size_t, std::size_t); virtual void DecommitPages(HeapBlock*); virtual void CommitPages(HeapBlock*, std::size_t);
    BSCriticalSection criticalSection; const char* name; std::size_t minFreeBlockSize; std::uint32_t pageSize; std::uint32_t pageSizeFlag;
    std::size_t memHeapSize; std::size_t initialSize; std::size_t currentSize; std::size_t wastedMemory; std::size_t memAllocated; std::size_t memAllocatedHigh; std::size_t blockMemAllocated;
    char* memHeap; std::int32_t numBlocks; std::uint32_t pad08C; HeapBlock* blockHead; HeapBlock* blockTail; std::int32_t numFreeBlocks; bool allowDecommits; bool supportsSwapping;
    std::uint16_t pad0A0; HeapBlock* smallFreeLists[32]; HeapBlockFreeHead* largeFreeTrees[32];
};
class MemoryHeap : public AbstractHeap { public:
    ~MemoryHeap() override; std::size_t Size(const void*) const override; void* Allocate(std::size_t, std::uint32_t) override; void Deallocate(void*, std::uint32_t) override;
    std::size_t TotalSize(const void*) const override; void GetHeapStats(HeapStats*, bool) override; void* DoHeapAllocation(std::size_t, std::size_t) override; void DoHeapFree(void*) override;
    std::size_t CreateMorePages(void*, std::size_t, std::size_t) override; std::size_t CleanExtraPages(void*, std::size_t, std::size_t) override; void DecommitPages(HeapBlock*) override;
    HeapBlockFreeHead* Functionce8a10(std::uint32_t);
    bool deletingHeap; std::uint8_t pad2A9; std::uint16_t pad2AA; std::uint32_t pad2AC;
};
std::size_t LargeFreeIndex(std::uint32_t);
static_assert(sizeof(AbstractHeap) == 0x2a8, "AbstractHeap size");
static_assert(sizeof(MemoryHeap) == 0x2b0, "MemoryHeap size");
// IMemoryStoreBase::Size, IMemoryStoreBase::GetMemoryStats, IMemoryStoreBase::ContainsBlockImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// IMemoryStore::AllocateAlignImpl, IMemoryStore::DeallocateAlignImpl, IMemoryStore::TryAllocateImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// IMemoryHeap::ContainsBlockImpl, IMemoryHeap::AllocateAlignImpl, IMemoryHeap::DeallocateAlignImpl, IMemoryHeap::GetName, IMemoryHeap::Allocate, IMemoryHeap::Deallocate, IMemoryHeap::PointerInHeap, IMemoryHeap::TotalSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// IMemoryHeap::GetHeapStats, IMemoryHeap::ShouldTrySmallBlockPools, IMemoryHeap::GetPageSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// AbstractHeap::GetMemoryStats, AbstractHeap::AllocateAlignImpl, AbstractHeap::TryAllocateImpl, AbstractHeap::GetName, AbstractHeap::PointerInHeap, AbstractHeap::GetHeapStats, AbstractHeap::ShouldTrySmallBlockPools, AbstractHeap::GetPageSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// AbstractHeap::DoHeapAllocation, AbstractHeap::DoHeapFree, AbstractHeap::CreateMorePages, AbstractHeap::CleanExtraPages, AbstractHeap::DecommitPages, AbstractHeap::CommitPages, AbstractHeap::criticalSection, AbstractHeap::name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// AbstractHeap::minFreeBlockSize, AbstractHeap::pageSize, AbstractHeap::pageSizeFlag, AbstractHeap::memHeapSize, AbstractHeap::initialSize, AbstractHeap::currentSize, AbstractHeap::wastedMemory, AbstractHeap::memAllocated: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// AbstractHeap::memAllocatedHigh, AbstractHeap::blockMemAllocated, AbstractHeap::memHeap, AbstractHeap::numBlocks, AbstractHeap::pad08C, AbstractHeap::blockHead, AbstractHeap::blockTail, AbstractHeap::numFreeBlocks: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// AbstractHeap::allowDecommits, AbstractHeap::supportsSwapping, AbstractHeap::pad0A0, AbstractHeap::smallFreeLists, AbstractHeap::largeFreeTrees: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// MemoryHeap::Size, MemoryHeap::Allocate, MemoryHeap::Deallocate, MemoryHeap::TotalSize, MemoryHeap::GetHeapStats, MemoryHeap::DoHeapAllocation, MemoryHeap::DoHeapFree, MemoryHeap::CreateMorePages: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// MemoryHeap::CleanExtraPages, MemoryHeap::DecommitPages, MemoryHeap::deletingHeap, MemoryHeap::pad2A9, MemoryHeap::pad2AA, MemoryHeap::pad2AC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CRITICAL_SECTION::debugInfo, CRITICAL_SECTION::lockCount, CRITICAL_SECTION::recursionCount, CRITICAL_SECTION::owningThread, CRITICAL_SECTION::lockSemaphore, CRITICAL_SECTION::spinCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSCriticalSection::criticalSection: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
