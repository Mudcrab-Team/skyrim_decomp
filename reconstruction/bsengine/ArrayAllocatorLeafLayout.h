// Source exposure: mixed (community declarations and local target analysis).
// Code origin: declarations adapted from the public allocator interface and p106 published represented pointer layout. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSTArray.h; represented starting point reconstruction/bsengine/ArrayAllocatorFunctorLayout.h from p106.
// AllocatorLeafInterface, ArrayAllocatorLeafLayout: GUESS(medium) STANDIN; aliases with unrecovered concrete template arguments.
// allocator: GUESS(medium); allocator object reference at offset8, not allocation-size storage.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class AllocatorLeafInterface {
public:
    virtual bool Allocate(std::uint32_t count, std::uint32_t elementSize) = 0;
    virtual bool Reallocate(std::uint32_t minimum, std::uint32_t frontCount,
                            std::uint32_t shiftCount, std::uint32_t backCount,
                            std::uint32_t elementSize) = 0;
    virtual void Deallocate() = 0;
    virtual ~AllocatorLeafInterface();
};
template<class Allocator>
class ArrayAllocatorLeafLayout : public AllocatorLeafInterface {
public:
    bool Allocate(std::uint32_t count, std::uint32_t elementSize) override;
    bool Reallocate(std::uint32_t minimum, std::uint32_t frontCount,
                    std::uint32_t shiftCount, std::uint32_t backCount,
                    std::uint32_t elementSize) override;
    void Deallocate() override;
    ~ArrayAllocatorLeafLayout() override;
    Allocator* allocator;
};
static_assert(sizeof(AllocatorLeafInterface) == 8, "allocator interface");
static_assert(sizeof(ArrayAllocatorLeafLayout<void>) == 16, "allocator functor");
static_assert(offsetof(ArrayAllocatorLeafLayout<void>, allocator) == 8, "allocator reference");
}
