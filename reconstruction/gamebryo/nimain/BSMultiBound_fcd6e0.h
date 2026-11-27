// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiRefObject::IncRefCount as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:15
// SPDX-License-Identifier: CC0-1.0
// NiStream, NiRefObject, NiObject, NiPointer, BSMultiBoundShape, BSMultiBound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiStream::ReadLinkID, NiRefObject::DeleteThis, NiObject::LinkObject, BSMultiBound::LinkObject, BSMultiBound::unk10, BSMultiBound::data: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::refCount, NiRefObject::unk0C, NiRefObject::IncRefCount, NiRefObject::DecRefCount, NiPointer::_ptr, BSMultiBound::unk14: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class NiObject;

class NiStream
{
public:
    NiObject* ReadLinkID();
};

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

class NiObject : public NiRefObject
{
public:
    void LinkObject(NiStream& a_stream);
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

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

class BSMultiBoundShape : public NiObject
{
};

class BSMultiBound : public NiObject
{
public:
    void LinkObject(NiStream& a_stream);

    std::uint32_t unk10;
    std::uint32_t unk14;
    NiPointer<BSMultiBoundShape> data;
};
static_assert(offsetof(BSMultiBound, data) == 0x18, "data offset");
static_assert(sizeof(BSMultiBound) == 0x20, "BSMultiBound size");
