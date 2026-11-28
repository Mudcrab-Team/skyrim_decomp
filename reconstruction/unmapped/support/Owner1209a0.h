// Source exposure: binary-analysis
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: GString1209a0::~GString1209a0, treated as adapted: shaped like GString::DataDesc::Release (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/G/GString.cpp:24, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Heap1209a0, gHeap1209a0, RefData1209a0, GString1209a0, Owner1209a0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Heap1209a0
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

extern Heap1209a0* gHeap1209a0;

struct RefData1209a0
{
    std::uint64_t size;  // 0x00
    long refCount;       // 0x08
};

struct GString1209a0
{
    std::uintptr_t data;  // 0x00

    ~GString1209a0()
    {
        RefData1209a0* block = reinterpret_cast<RefData1209a0*>(data & ~static_cast<std::uintptr_t>(3));
        if (_InterlockedExchangeAdd(&block->refCount, -1) == 1)  // atomic refcount decrement
        {
            gHeap1209a0->Free(block);
        }
    }
};

struct Owner1209a0
{
    std::uint64_t unk00;  // 0x00
    std::uint64_t unk08;  // 0x08
    std::uint64_t unk10;  // 0x10
    GString1209a0 name;   // 0x18

    ~Owner1209a0();       // compared: 0x1209a0
};
