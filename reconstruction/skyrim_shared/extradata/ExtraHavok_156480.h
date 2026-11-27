// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraHavok: EXE_RTTI
// ExtraHavok::~ExtraHavok: CRASHLOGGER_PDB(59818@2026.10.24)
// BSExtraData, BSExtraData::next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HavokRefObject, HavokRefPtr, ExtraHavok::world, ExtraHavok::refObj: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class BSExtraData
{
public:
    virtual ~BSExtraData() {}

    BSExtraData* next;
};
static_assert(sizeof(BSExtraData) == 0x10, "BSExtraData size");

class HavokRefObject
{
public:
    virtual ~HavokRefObject();
    virtual void DeleteThis();

    void DecRefCount()
    {
        // intrusive ref-count: atomic release
        const long count = _InterlockedDecrement(&refCount);
        if (count == 0) {
            DeleteThis();
        }
    }

    long refCount;
};
static_assert(offsetof(HavokRefObject, refCount) == 0x08, "HavokRefObject::refCount offset");

struct HavokRefPtr
{
    ~HavokRefPtr()
    {
        if (ptr) {
            ptr->DecRefCount();
        }
    }

    HavokRefObject* ptr;
};

class ExtraHavok : public BSExtraData
{
public:
    ExtraHavok();

    HavokRefPtr world;
    HavokRefPtr refObj;
};
static_assert(offsetof(ExtraHavok, world) == 0x10, "ExtraHavok::world offset");
static_assert(offsetof(ExtraHavok, refObj) == 0x18, "ExtraHavok::refObj offset");
static_assert(sizeof(ExtraHavok) == 0x20, "ExtraHavok size");
