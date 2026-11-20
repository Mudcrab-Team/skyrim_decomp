// Source exposure: mixed (community declarations and pinned image analysis).
// IAllocatorFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ArrayAllocatorFunctorLayout, allocator: GUESS(medium) STANDIN
// BSTArrayAllocatorFunctor: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class IAllocatorFunctor {
public:
    virtual bool Allocate(std::uint32_t count, std::uint32_t elementSize) = 0;
    virtual bool Reallocate(std::uint32_t minimum, std::uint32_t frontCount,
                            std::uint32_t shiftCount, std::uint32_t backCount,
                            std::uint32_t elementSize) = 0;
    virtual void Deallocate() = 0;
    virtual ~IAllocatorFunctor();
};
template<class Allocator>
class ArrayAllocatorFunctorLayout : public IAllocatorFunctor {
public:
    bool Allocate(std::uint32_t count, std::uint32_t elementSize) override;
    bool Reallocate(std::uint32_t minimum, std::uint32_t frontCount,
                    std::uint32_t shiftCount, std::uint32_t backCount,
                    std::uint32_t elementSize) override;
    void Deallocate() override;
    ~ArrayAllocatorFunctorLayout() override;
    Allocator* allocator;
};
static_assert(sizeof(IAllocatorFunctor) == 8, "allocator interface");
static_assert(sizeof(ArrayAllocatorFunctorLayout<void>) == 16, "allocator functor");
static_assert(offsetof(ArrayAllocatorFunctorLayout<void>, allocator) == 8, "allocator reference");
}
