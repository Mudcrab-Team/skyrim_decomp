// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: Stand-in declarations and intrusive reference helpers adapted for the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiGeometryData, NiGeometryData::LinkObject, additionalGeomData, _ptr, _pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream, NiObject, NiAdditionalGeometryData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream::ReadLinkID: SYMBOLS(tesv-2013-map)
// unk10: GUESS(low)
// Adapted bodies: NiPointer::operator= follows momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderconstantmap.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderconstantmap.cpp:248
#pragma once

#include <cstdint>
#include <intrin.h>

// NiRefObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject::DeleteThis, NiRefObject::IncRefCount, NiRefObject::DecRefCount, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    void IncRefCount()
    {
        // Intrusive references can be retained concurrently.
        _InterlockedIncrement(&_refCount);
    }

    void DecRefCount()
    {
        // The final atomic release owns object deletion.
        const long count = _InterlockedDecrement(&_refCount);
        if (count == 0)
            DeleteThis();
    }

private:
    volatile long _refCount;
    std::uint32_t _pad0C;
};

class NiStream;

class NiObject : public NiRefObject
{
public:
    virtual void LinkObject(NiStream& stream);
};

class NiStream
{
public:
    NiObject* ReadLinkID();
};

class NiAdditionalGeometryData : public NiObject
{
};

// NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
template <class T>
class NiPointer
{
public:
    NiPointer& operator=(T* object)
    {
        T* old = _ptr;
        if (old != object)
        {
            if (object)
                object->IncRefCount();
            _ptr = object;
            if (old)
                old->DecRefCount();
        }
        return *this;
    }

private:
    T* _ptr;
};

class NiGeometryData : public NiObject
{
public:
    void LinkObject(NiStream& stream) override;

private:
    std::uint8_t unk10[0x48];
    NiPointer<NiAdditionalGeometryData> additionalGeomData;
};
