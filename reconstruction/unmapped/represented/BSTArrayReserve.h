// Source exposure: mixed (pinned image and community allocator declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original capacity guard and allocator model. Adapted bodies: none.
// BSTArrayAllocatorFunctor, BSTArrayHeapAllocator, BSScrapArrayAllocator: EXE_RTTI
// IAllocatorFunctor and its virtual interface: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReserveAdditional, SetCapacity, BSTArrayReserve, element types and field names: GUESS(low) STANDIN
#pragma once

namespace array_reserve
{
    struct IAllocatorFunctor
    {
        virtual bool Allocate(unsigned count, unsigned elementSize) = 0;
        virtual bool Reallocate(unsigned minimum, unsigned frontCount, unsigned shiftCount,
                                unsigned backCount, unsigned elementSize) = 0;
        virtual void Deallocate() = 0;
        virtual ~IAllocatorFunctor() {}
    };

    struct ArrayBase
    {
        unsigned size;
        void SetCapacity(IAllocatorFunctor& allocator, unsigned capacity, unsigned minimum, unsigned elementSize);
    };

    struct BSTArrayHeapAllocator
    {
        void* buffer;
        unsigned capacity;
    };

    struct BSScrapArrayAllocator
    {
        void* arena;
        void* buffer;
        unsigned capacity;
    };

    template <class Storage>
    struct BSTArrayAllocatorFunctor : IAllocatorFunctor
    {
        explicit BSTArrayAllocatorFunctor(Storage& owner) : storage(owner) {}
        bool Allocate(unsigned count, unsigned elementSize) override;
        bool Reallocate(unsigned minimum, unsigned frontCount, unsigned shiftCount,
                        unsigned backCount, unsigned elementSize) override;
        void Deallocate() override;
        ~BSTArrayAllocatorFunctor() override {}

        Storage& storage;
    };

    template <class Element, class Storage>
    struct BSTArrayReserve : Storage, ArrayBase
    {
        void ReserveAdditional(unsigned count);
    };
}
