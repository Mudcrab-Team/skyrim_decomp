// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraCellGrassData: EXE_RTTI
// ExtraCellGrassData::~ExtraCellGrassData: CRASHLOGGER_PDB(59818@2026.10.24)
// BSExtraData, BSExtraData::next, BSTArrayBase, BSTArrayBase::size, BSTArrayHeapAllocator, BSTArrayHeapAllocator::data, BSTArrayHeapAllocator::capacity, BSTArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTArrayHeapAllocator::Deallocate, GrassRefObject, GrassRefPtr, ExtraCellGrassData::grassData, ExtraCellGrassData::grassRef: GUESS(low) STANDIN
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

struct BSTArrayHeapAllocator
{
    ~BSTArrayHeapAllocator();
    void Deallocate();

    void* data;
    std::uint32_t capacity;
};
static_assert(sizeof(BSTArrayHeapAllocator) == 0x10, "BSTArrayHeapAllocator size");

struct BSTArrayBase
{
    ~BSTArrayBase();

    std::uint32_t size;
};

struct BSTArray : BSTArrayHeapAllocator, BSTArrayBase
{
    ~BSTArray()
    {
        if (data) {
            Deallocate();
            size = 0;
        }
    }
};
static_assert(sizeof(BSTArray) == 0x18, "BSTArray size");

class GrassRefObject
{
public:
    virtual ~GrassRefObject();

    long refCount;
};
static_assert(offsetof(GrassRefObject, refCount) == 0x08, "GrassRefObject::refCount offset");

struct GrassRefPtr
{
    ~GrassRefPtr()
    {
        GrassRefObject* obj = ptr;
        if (obj) {
            // intrusive ref-count: atomic release
            const long count = _InterlockedDecrement(&obj->refCount);
            if (count == 0) {
                delete obj;
            }
        }
    }

    GrassRefObject* ptr;
};

class ExtraCellGrassData : public BSExtraData
{
public:
    ExtraCellGrassData();

    BSTArray grassData;
    GrassRefPtr grassRef;
};
static_assert(offsetof(ExtraCellGrassData, grassData) == 0x10, "ExtraCellGrassData::grassData offset");
static_assert(offsetof(ExtraCellGrassData, grassRef) == 0x28, "ExtraCellGrassData::grassRef offset");
static_assert(sizeof(ExtraCellGrassData) == 0x30, "ExtraCellGrassData size");
