// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiObject::IncRefCount as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niscreentexture.cpp:538
// SPDX-License-Identifier: CC0-1.0
// NiObject, NiPointer, NiStream, NiControllerSequence: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiControllerSequence::LinkObject: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject::DeleteThis, NiObject::LinkObject, NiObject::IncRefCount, NiObject::DecRefCount, NiObject::refCount, NiObject::unk0C, NiPointer::_ptr, NiStream::ReadLinkID, NiStream::unk00, NiStream::version, NiControllerSequence::unk10, NiControllerSequence::textKeys, NiControllerSequence::unk40, NiControllerSequence::owner, NiControllerSequence::unk68, NiControllerSequence::animNotes, NiControllerSequence::numNotes: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class NiStream;

class NiObject
{
public:
    virtual ~NiObject();
    virtual void DeleteThis();
    void LinkObject(NiStream& a_stream);

    void IncRefCount()
    {
        // Increment the shared intrusive reference count atomically across threads.
        _InterlockedIncrement(&refCount);
    }

    void DecRefCount()
    {
        // Decrement the shared intrusive reference count atomically and destroy on the final release.
        std::uint32_t count = static_cast<std::uint32_t>(_InterlockedDecrement(&refCount));
        if (count == 0) {
            DeleteThis();
        }
    }

    long refCount;
    std::uint32_t unk0C;
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

class NiStream
{
public:
    NiObject* ReadLinkID();

    std::uint8_t unk00[0x08];
    std::uint32_t version;
};
static_assert(offsetof(NiStream, version) == 0x08, "version offset");

class NiControllerSequence : public NiObject
{
public:
    void LinkObject(NiStream& a_stream);

    std::uint8_t unk10[0x28];
    NiPointer<NiObject> textKeys;
    std::uint8_t unk40[0x20];
    NiObject* owner;
    std::uint8_t unk68[0x40];
    NiPointer<NiObject>* animNotes;
    std::uint16_t numNotes;
};
static_assert(offsetof(NiControllerSequence, textKeys) == 0x38, "textKeys offset");
static_assert(offsetof(NiControllerSequence, owner) == 0x60, "owner offset");
static_assert(offsetof(NiControllerSequence, animNotes) == 0xA8, "animNotes offset");
static_assert(offsetof(NiControllerSequence, numNotes) == 0xB0, "numNotes offset");
