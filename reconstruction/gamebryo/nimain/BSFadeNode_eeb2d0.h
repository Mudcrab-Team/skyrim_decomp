// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiRefObject::IncRefCount as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:15
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiPointer, NiTimeController, BSFadeNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::DeleteThis, BSFadeNode::ExchangeControllerReference: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::refCount, NiRefObject::unk0C, NiRefObject::IncRefCount, NiRefObject::DecRefCount, NiPointer::_ptr, NiTimeController::unk10, NiTimeController::next, BSFadeNode::unk00, BSFadeNode::controllers: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    void IncRefCount()
    {
        // atomic reference count increment required by intrusive smart pointers
        _InterlockedIncrement(&refCount);
    }

    void DecRefCount()
    {
        // atomic reference count decrement required by intrusive smart pointers
        std::uint32_t count = static_cast<std::uint32_t>(_InterlockedDecrement(&refCount));
        if (count == 0) {
            DeleteThis();
        }
    }

    long refCount;
    std::uint32_t unk0C;
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

template <class T>
class NiPointer
{
public:
    NiPointer& operator=(T* a_rhs)
    {
        if (_ptr != a_rhs) {
            T* old = _ptr;
            if (a_rhs) {
                a_rhs->IncRefCount();
            }
            _ptr = a_rhs;
            if (old) {
                old->DecRefCount();
            }
        }
        return *this;
    }

    T* _ptr;
};

class NiTimeController : public NiRefObject
{
public:
    std::uint8_t unk10[0x30];
    NiPointer<NiTimeController> next;
};
static_assert(offsetof(NiTimeController, next) == 0x40, "next offset");

class BSFadeNode
{
public:
    void ExchangeControllerReference(NiTimeController* a_controller);

    std::uint8_t unk00[0x18];
    NiPointer<NiTimeController> controllers;
};
static_assert(offsetof(BSFadeNode, controllers) == 0x18, "controllers offset");
