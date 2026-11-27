// DeleteThis, DecRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Cookbook: 0xeef3f0 29
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the pinned image. Both cited siblings use the same null-checked release in ~NiPointer.
// NiPointer::~NiPointer: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0) SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535 (same null-checked release)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36 (same null-checked release)
// NiCamera, NiPointer, NiAVObject, LinkObject, NiStream, NiRefObject: CRASHLOGGER_PDB(59818@2026.10.24)
// GetObjectFromLinkID, GetNumberOfLinkIDs: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCamera::LinkObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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
    explicit NiPointer(T* object) : ptr(object)
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
    NiRefObject* GetObjectFromLinkID();
    unsigned GetNumberOfLinkIDs();
};
// A qualified call to the base is the only dispatch used by this unit.
class NiAVObject : public NiRefObject
{
public:
    void LinkObject(NiStream& stream);

private:
    unsigned char unknown10[0x100];
};
static_assert(sizeof(NiAVObject) == 0x110, "scene object base size");

class NiCamera : public NiAVObject
{
public:
    ~NiCamera() override;
    void LinkObject(NiStream& stream);

private:
    unsigned char unknown110[0x78];
};
static_assert(sizeof(NiCamera) == 0x188, "camera base size");
