// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InnerArray1805a0 and OuterArray1805a0 destructors, treated as adapted: shaped like BSTArray::~BSTArray and BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTArray.h:427, include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ArrayAlloc1805a0, ArrayBase1805a0, InnerArray1805a0, OuterArray1805a0, OuterBase1805a0, OuterObj1805a0, Deallocate, Data: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ArrayAlloc1805a0
{
    ~ArrayAlloc1805a0();
    void Deallocate();

    void* data;              // 00
    std::uint32_t capacity;  // 08
    std::uint32_t unk0C;     // 0C
};

struct ArrayBase1805a0
{
    ~ArrayBase1805a0();

    std::uint32_t size;  // 00
};

struct InnerArray1805a0
{
    ~InnerArray1805a0()
    {
        if (alloc.data) {
            alloc.Deallocate();
            base.size = 0;
        }
    }

    ArrayAlloc1805a0 alloc;  // 00
    ArrayBase1805a0 base;    // 10
    std::uint32_t unk14;     // 14
    std::uint64_t unk18;     // 18
};

struct OuterArray1805a0
{
    ~OuterArray1805a0()
    {
        if (alloc.data) {
            alloc.Deallocate();
            base.size = 0;
        }
    }

    InnerArray1805a0** Data()
    {
        return static_cast<InnerArray1805a0**>(alloc.data);
    }

    ArrayAlloc1805a0 alloc;  // 00
    ArrayBase1805a0 base;    // 10
};

class OuterBase1805a0
{
public:
    virtual ~OuterBase1805a0() {}

    void* next;           // 08
    std::uint64_t unk10;  // 10
    std::uint64_t unk18;  // 18
};

class OuterObj1805a0 : public OuterBase1805a0
{
public:
    ~OuterObj1805a0() override;  // compared: 0x1805a0

    OuterArray1805a0 items;  // 20
};
