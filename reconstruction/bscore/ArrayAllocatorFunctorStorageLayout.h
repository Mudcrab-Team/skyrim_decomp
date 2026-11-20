// Source exposure: mixed (community declarations and pinned image analysis).
// IAllocatorFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ArrayAllocatorFunctorLayout, allocator: GUESS(medium) STANDIN
// BSTArrayAllocatorFunctor: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted from published p106 represented declaration reconstruction/bsengine/ArrayAllocatorFunctorLayout.h.
// IAllocatorFunctorStorageLayout, ArrayAllocatorFunctorStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class IAllocatorFunctorStorageLayout {
public:
    virtual bool Allocate(std::uint32_t count, std::uint32_t elementSize) = 0;
    virtual bool Reallocate(std::uint32_t minimum, std::uint32_t frontCount,
                            std::uint32_t shiftCount, std::uint32_t backCount,
                            std::uint32_t elementSize) = 0;
    virtual void Deallocate() = 0;
    virtual ~IAllocatorFunctorStorageLayout();
};
template<class Allocator>
class ArrayAllocatorFunctorStorageLayout : public IAllocatorFunctorStorageLayout {
public:
    bool Allocate(std::uint32_t count, std::uint32_t elementSize) override;
    bool Reallocate(std::uint32_t minimum, std::uint32_t frontCount,
                    std::uint32_t shiftCount, std::uint32_t backCount,
                    std::uint32_t elementSize) override;
    void Deallocate() override;
    ~ArrayAllocatorFunctorStorageLayout() override;
    Allocator* allocator;
};
static_assert(sizeof(IAllocatorFunctorStorageLayout) == 8, "allocator interface");
static_assert(sizeof(ArrayAllocatorFunctorStorageLayout<void>) == 16, "allocator functor");
static_assert(offsetof(ArrayAllocatorFunctorStorageLayout<void>, allocator) == 8, "allocator reference");
}
