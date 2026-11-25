// Near miss: 97.67% | inline-set
// Exposure detail: (local binary analysis and community declarations).
// Source exposure: mixed
// Origin: original reconstruction; cleanup guard follows cookbook rule 67.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Cookbook: 67
// 0x7e9b40 Explosion::~Explosion

#include "include/7e9b40/Explosion_7e9b40.h"

// gArrayAllocatorStorage, AllocatorStorage, allocatorVftable, EmptyArrayStorage, target: GUESS(low)
struct AllocatorStorage { void* allocatorVftable; };
extern AllocatorStorage gArrayAllocatorStorage;

class EmptyArrayStorage
{
public:
    explicit EmptyArrayStorage(Explosion& value) : target(value) {}
    ~EmptyArrayStorage()
    {
        target.arrayData = nullptr;
        target.capacityAndFlags = (-2147483647 - 1);
    }
private:
    Explosion& target;
};

Explosion::~Explosion() noexcept
{
    arraySize = 0;
    if (capacityAndFlags >= 0) {
        const EmptyArrayStorage reset(*this);
        const std::int32_t capacity = capacityAndFlags & 0x3FFFFFFF;
        auto& allocator = reinterpret_cast<hkMemoryAllocator&>(gArrayAllocatorStorage);
        allocator.BufFree(arrayData, capacity * 16);
        return;
    }
    arrayData = nullptr;
    capacityAndFlags = (-2147483647 - 1);
}
