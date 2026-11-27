// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraGuardedRefData: EXE_RTTI
// ExtraGuardedRefData::~ExtraGuardedRefData: CRASHLOGGER_PDB(59818@2026.10.24)
// BSExtraData, BSExtraData::next, BSTArrayBase, BSTArrayHeapAllocator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTArrayHeapAllocator::data, BSTArrayHeapAllocator::capacity, BSTArrayHeapAllocator::Deallocate, BSTArrayBase::size, BSTArray, ExtraGuardedRefData::guards: GUESS(low); subobject layout and destructor calls observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class BSExtraData
{
public:
    virtual ~BSExtraData() {}  // 00

    BSExtraData* next;  // 08
};
static_assert(sizeof(BSExtraData) == 0x10, "BSExtraData size");

struct BSTArrayHeapAllocator
{
    ~BSTArrayHeapAllocator();
    void Deallocate();

    void*         data;      // 00
    std::uint32_t capacity;  // 08
};
static_assert(sizeof(BSTArrayHeapAllocator) == 0x10, "BSTArrayHeapAllocator size");

struct BSTArrayBase
{
    ~BSTArrayBase();

    std::uint32_t size;  // 00
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

class ExtraGuardedRefData : public BSExtraData
{
public:
    ExtraGuardedRefData();

    BSTArray guards;  // 10
};
static_assert(sizeof(ExtraGuardedRefData) == 0x28, "ExtraGuardedRefData size");
