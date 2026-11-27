// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraFriendHits: EXE_RTTI
// ExtraFriendHits::~ExtraFriendHits: CRASHLOGGER_PDB(59818@2026.10.24)
// BSExtraData, BSExtraData::next, BSTArrayBase, BSTArrayHeapAllocator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTArrayHeapAllocator::data, BSTArrayHeapAllocator::capacity, BSTArrayHeapAllocator::Deallocate, BSTArrayBase::size, BSTArray, ExtraFriendHits::hits: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

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

class ExtraFriendHits : public BSExtraData
{
public:
    ExtraFriendHits();

    BSTArray hits;
};
static_assert(sizeof(ExtraFriendHits) == 0x28, "ExtraFriendHits size");
