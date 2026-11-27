// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiPointer::~NiPointer as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiObject, NiPointer, NiTimeController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::DeleteThis, NiRefObject::ms_totalObjects: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::refCount, NiRefObject::unk0C, NiRefObject::DecRefCount, NiPointer::_ptr, NiTimeController::unk10, NiTimeController::next: GUESS(low)
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
        if (_InterlockedExchangeAdd(&refCount, -1) == 1) {
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

    T* _ptr;
};

class NiTimeController : public NiObject
{
public:
    NiTimeController();
    ~NiTimeController() override;

    std::uint8_t unk10[0x30];
    NiPointer<NiTimeController> next;
};
static_assert(offsetof(NiTimeController, next) == 0x40, "next offset");
static_assert(sizeof(NiTimeController) == 0x48, "NiTimeController size");
