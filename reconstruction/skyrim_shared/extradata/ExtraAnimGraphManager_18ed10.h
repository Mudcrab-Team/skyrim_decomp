// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraAnimGraphManager, ExtraAnimGraphManager::animGraphMgr, ::~ExtraAnimGraphManager: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSExtraData, BSExtraData::next, BSAnimationGraphManager, BSTSmartPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); partial, only what the destructor touches
// BSAnimationGraphManager::DecRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; here an atomic decrement of the count at +08 of the pointee
// BSAnimationGraphManager::refCount, BSTSmartPointerAnimGraphManager: GUESS(low)
// ExtraAnimGraphManager::ExtraAnimGraphManager: SIBLING(fo4-private@1b765c70, author-permission); name only
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class BSExtraData
{
public:
    virtual ~BSExtraData() {}

    BSExtraData* next;
};

class BSAnimationGraphManager
{
public:
    virtual ~BSAnimationGraphManager();

    std::uint32_t DecRef()
    {
        // atomic release of the intrusive count, as the engine does
        return static_cast<std::uint32_t>(_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&refCount), -1));
    }

    std::uint32_t refCount;  // 08
};

class BSTSmartPointerAnimGraphManager
{
public:
    ~BSTSmartPointerAnimGraphManager()
    {
        BSAnimationGraphManager* object = ptr;
        if (object && object->DecRef() == 1) {
            delete object;
        }
    }

    BSAnimationGraphManager* ptr;
};

class ExtraAnimGraphManager : public BSExtraData
{
public:
    ExtraAnimGraphManager();
    ~ExtraAnimGraphManager() override = default;

    BSTSmartPointerAnimGraphManager animGraphMgr;  // 10
};
static_assert(sizeof(ExtraAnimGraphManager) == 0x18, "ExtraAnimGraphManager size");
