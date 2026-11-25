// DeleteThis, DecRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Cookbook: 0xeef3f0 29
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// NiCamera, NiPointer, NiAVObject, LinkObject, NiStream, NiRefObject: CRASHLOGGER_PDB(59818@2026.10.24)
// ReadLinkID, ReadLinkIDCount: GUESS(low)
#pragma once

#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long refCount;

    void DecRefCount()
    {
        // Only the last thread releasing a reference destroys the object.
        const unsigned remaining = _InterlockedDecrement(&refCount);
        if (!remaining) {
            DeleteThis();
        }
    }
};

template<class T>
struct NiPointer
{
    T* ptr;
    NiPointer(T* object) : ptr(object)
    {
        if (ptr) {
            // A streamed reference can be shared between threads.
            _InterlockedIncrement(&object->refCount);
        }
    }
    ~NiPointer()
    {
        if (ptr) {
            ptr->DecRefCount();
        }
    }
};

class NiStream
{
public:
    NiRefObject* ReadLinkID();
    unsigned ReadLinkIDCount();
};
class NiAVObject : public NiRefObject
{
public:
    void LinkObject(NiStream& stream);
};
class NiCamera : public NiAVObject
{
public:
    void LinkObject(NiStream& stream);
};
