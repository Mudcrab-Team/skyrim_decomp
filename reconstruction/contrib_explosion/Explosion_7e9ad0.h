// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Explosion: STANDIN GUESS(low); placeholder owner, modelled as the array storage at entry
// hkMemoryAllocator, BlockAlloc, BlockFree, BufAlloc, BufFree: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// Explosion::~Explosion, arrayData, arraySize, capacityAndFlags: GUESS(low)
#pragma once

#include <cstdint>

class hkMemoryAllocator
{
public:
    virtual ~hkMemoryAllocator();
    virtual void* BlockAlloc(int a_size);
    virtual void BlockFree(void* a_data, int a_size);
    virtual void* BufAlloc(int* a_size);
    virtual void BufFree(void* a_data, int a_size);
};

class Explosion
{
public:
    ~Explosion() noexcept;

    void* arrayData;
    std::int32_t arraySize;
    std::int32_t capacityAndFlags;
};
