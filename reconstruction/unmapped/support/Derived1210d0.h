// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: GString1210d0::~GString1210d0, treated as adapted: shaped like GString::DataDesc::Release (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/G/GString.cpp:24, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Heap1210d0, gHeap1210d0, RefData1210d0, GString1210d0, Base1210d0, Derived1210d0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Heap1210d0
{
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Free(void* a_ptr) = 0;
};

extern Heap1210d0* gHeap1210d0;

struct RefData1210d0
{
    std::uint64_t size;  // 0x00
    long refCount;       // 0x08
};

struct GString1210d0
{
    std::uintptr_t data;  // 0x00

    ~GString1210d0()
    {
        RefData1210d0* block = reinterpret_cast<RefData1210d0*>(data & ~static_cast<std::uintptr_t>(3));
        if (_InterlockedExchangeAdd(&block->refCount, -1) == 1)  // atomic refcount decrement
        {
            gHeap1210d0->Free(block);
        }
    }
};

struct Base1210d0
{
    std::uint64_t unk00;  // 0x00
    std::uint64_t unk08;  // 0x08

    ~Base1210d0();
};

struct Derived1210d0 : Base1210d0
{
    GString1210d0 name;   // 0x10

    ~Derived1210d0();     // compared: 0x1210d0
};
