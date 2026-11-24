// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7e9ad0 Explosion::~Explosion
// Adapted bodies: none
#include "Explosion_7e9ad0.h"

// gArrayAllocatorStorage, AllocatorStorage, allocatorVftable, kNoOwnedStorage, kArrayCapacityMask, kElementSize, EmptyArrayStorage, EmptyArrayStorage::target: GUESS(low)
struct AllocatorStorage
{
    void* allocatorVftable;
};

extern AllocatorStorage gArrayAllocatorStorage;
constexpr std::int32_t kNoOwnedStorage = (-2147483647 - 1);
constexpr std::int32_t kArrayCapacityMask = 0x3FFFFFFF;
constexpr int kElementSize = 64;

class EmptyArrayStorage
{
public:
    explicit EmptyArrayStorage(Explosion& a_target) : target(a_target) {}

    ~EmptyArrayStorage()
    {
        target.arrayData = nullptr;
        target.capacityAndFlags = kNoOwnedStorage;
    }

private:
    Explosion& target;
};

Explosion::~Explosion() noexcept
{
    arraySize = 0;
    if (capacityAndFlags >= 0) {
        const EmptyArrayStorage reset(*this);
        const int capacity = capacityAndFlags & kArrayCapacityMask;
        // The concrete allocator is shared by the array-storage implementation.
        auto& allocator = reinterpret_cast<hkMemoryAllocator&>(gArrayAllocatorStorage);
        allocator.BufFree(arrayData, capacity * kElementSize);
        return;
    }
    arrayData = nullptr;
    capacityAndFlags = kNoOwnedStorage;
}
