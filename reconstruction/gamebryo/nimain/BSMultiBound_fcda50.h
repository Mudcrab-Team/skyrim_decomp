// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiPointer::~NiPointer as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiObject, NiPointer, BSMultiBoundShape, BSMultiBound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::DeleteThis, NiRefObject::ms_totalObjects, BSMultiBound::unk10, BSMultiBound::data: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::refCount, NiRefObject::unk0C, NiRefObject::DecRefCount, NiPointer::_ptr, BSMultiBound::unk14: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject()
    {
        // atomic decrement of global live object counter on destruction
        _InterlockedDecrement(&ms_totalObjects);
    }
    virtual void DeleteThis();

    void DecRefCount()
    {
        // atomic reference count decrement required by intrusive smart pointers
        std::uint32_t count = static_cast<std::uint32_t>(_InterlockedDecrement(&refCount));
        if (count == 0) {
            DeleteThis();
        }
    }

    static long ms_totalObjects;

    long refCount;
    std::uint32_t unk0C;
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiObject : public NiRefObject
{
public:
    ~NiObject() override = default;
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

template <class T>
class NiPointer
{
public:
    ~NiPointer()
    {
        if (_ptr) {
            _ptr->DecRefCount();
        }
    }

    NiPointer& operator=(std::nullptr_t)
    {
        if (_ptr) {
            T* old = _ptr;
            _ptr = nullptr;
            old->DecRefCount();
        }
        return *this;
    }

    T* _ptr;
};

class BSMultiBoundShape : public NiObject
{
};

class BSMultiBound : public NiObject
{
public:
    BSMultiBound();
    ~BSMultiBound() override;

    std::uint32_t unk10;
    std::uint32_t unk14;
    NiPointer<BSMultiBoundShape> data;
};
static_assert(offsetof(BSMultiBound, data) == 0x18, "data offset");
static_assert(sizeof(BSMultiBound) == 0x20, "BSMultiBound size");
