// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Entry2b9d90::~Entry2b9d90, RefCounted2b9d90::DecRef and Obj2b9d90::Function2b9d90, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount and BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base2b9d90, RefCounted2b9d90, Target2b9d90, Entry2b9d90, Array2b9d90, Obj2b9d90: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class Base2b9d90
{
public:
    virtual ~Base2b9d90();

    std::uint8_t unk08[0x18];  // 0x08
};

class RefCounted2b9d90
{
public:
    virtual ~RefCounted2b9d90();
    virtual void DeleteThis();

    void DecRef()
    {
        // atomic 10-bit reference count decrement
        if ((_InterlockedDecrement(&refCount) & 0x3FF) == 0) {
            DeleteThis();
        }
    }

    long refCount;  // 0x08
};

class Target2b9d90 : public Base2b9d90, public RefCounted2b9d90
{
};

struct Entry2b9d90
{
    std::uint64_t unk00;  // 0x00
    Target2b9d90* ptr08;  // 0x08

    ~Entry2b9d90()
    {
        if (ptr08) {
            ptr08->DecRef();
        }
    }
};

struct Array2b9d90
{
    Entry2b9d90* data;       // 0x00
    std::uint32_t capacity;  // 0x08
    std::uint32_t unk0C;     // 0x0C
    std::uint32_t size;      // 0x10
};

extern Array2b9d90 g_array2b9d90;

class Obj2b9d90
{
public:
    void Function2b9d90();
};

static_assert(sizeof(Base2b9d90) == 0x20, "Base2b9d90 size");
static_assert(sizeof(Entry2b9d90) == 0x10, "Entry2b9d90 size");
static_assert(offsetof(Array2b9d90, size) == 0x10, "size offset");
