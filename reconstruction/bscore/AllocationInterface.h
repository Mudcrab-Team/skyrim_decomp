// Source exposure: mixed
// NiAllocator::Allocate, NiAllocator::Deallocate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AllocationInterface, AllocationManager, allocatorManager: GUESS(low) STANDIN; allocator dispatch and singleton storage
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "NiAllocator.h"
class AllocationInterface : public NiAllocator {
public:
    virtual void* Allocate(std::size_t&, std::size_t&, int, bool, const char*, int, const char*);
    virtual void Deallocate(void*, int, std::size_t);
};
struct AllocationManager { AllocationInterface* allocator; };
extern AllocationManager* allocatorManager;
