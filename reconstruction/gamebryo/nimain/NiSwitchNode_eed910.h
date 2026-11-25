// Source exposure: mixed (community declarations; local target observations).
// Code origin: original reconstruction.
// License: GPL-3.0 for the CommonLibSSE declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiNode: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); partial declaration using the base declaration kit.
// NiNode::AttachChild, NiNode::InsertChildAt, NiNode::DetachChild1, NiNode::DetachChild2, NiNode::DetachChildAt1, NiNode::DetachChildAt2, NiNode::SetAt1, NiNode::SetAt2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReferenceCountStorage, ReferenceCountStorage members, NiPointer::pointer: GUESS(low) STANDIN; reference-count prefix observed in the target.
#pragma once
#include <cstddef>
#include <intrin.h>
#include "declarations/NiAVObject.h"

struct ReferenceCountStorage
{
    void* vtable;
    // volatile: atomic intrusive ownership count observed in local target accesses.
    volatile long refCount;
};
static_assert(offsetof(ReferenceCountStorage, refCount) == 8, "reference count offset");

template <class T>
class NiPointer
{
public:
    NiPointer() : pointer(nullptr) {}
    ~NiPointer()
    {
        T* object = pointer;
        if (object) {
            auto* storage = reinterpret_cast<ReferenceCountStorage*>(object);
            // Shared scene objects release ownership atomically across threads.
            const long count = _InterlockedDecrement(&storage->refCount);
            if (count == 0) {
                object->DeleteThis();
            }
        }
    }
    T* pointer;
};

class NiNode : public NiAVObject
{
public:
    virtual void AttachChild(NiAVObject* child, bool firstAvailable = false);
    virtual void InsertChildAt(std::uint32_t index, NiAVObject* child);
    virtual void DetachChild1(NiAVObject* child, NiPointer<NiAVObject>& detached);
    virtual void DetachChild2(NiAVObject* child);
    virtual void DetachChildAt1(std::uint32_t index, NiPointer<NiAVObject>& detached);
    virtual void DetachChildAt2(std::uint32_t index);
    virtual void SetAt1(std::uint32_t index, NiAVObject* child, NiPointer<NiAVObject>& detached);
    virtual void SetAt2(std::uint32_t index, NiAVObject* child);
};

// NiSwitchNode, NiSwitchNode::DetachChildAt2: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); partial declaration with observed inherited slot.
class NiSwitchNode : public NiNode
{
public:
    void DetachChildAt2(std::uint32_t index) override;
};
