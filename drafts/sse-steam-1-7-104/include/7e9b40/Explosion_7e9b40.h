// Exposure detail: (local binary analysis and community declarations).
// Source exposure: mixed
// Origin: original reconstruction; cleanup guard follows cookbook rule 67.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Explosion: STANDIN GUESS(low); assigned owner models only the array storage at entry
// hkMemoryAllocator, BlockAlloc, BlockFree, BufAlloc, BufFree: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// arrayData, arraySize, capacityAndFlags: GUESS(low); storage roles inferred from cleanup

#pragma once
#include <cstdint>
#include <cstddef>

class hkMemoryAllocator
{
public:
    virtual ~hkMemoryAllocator();
    virtual void* BlockAlloc(std::int32_t size);
    virtual void BlockFree(void* data, std::int32_t size);
    virtual void* BufAlloc(std::int32_t& size);
    virtual void BufFree(void* data, std::int32_t size);
};

class Explosion
{
public:
    ~Explosion() noexcept;
    void* arrayData;
    std::int32_t arraySize;
    std::int32_t capacityAndFlags;
};
static_assert(offsetof(Explosion, arraySize) == 8, "array size offset");
static_assert(offsetof(Explosion, capacityAndFlags) == 12, "capacity offset");
