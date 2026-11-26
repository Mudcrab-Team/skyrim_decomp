// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sun, Sun::sunBaseNode, Sun::sunGlareNode, Sun::sunBase, Sun::sunQuery, Sun::sunGlare, Sun::light, Sun::cloudLight, Sun::glareScale, Sun::doOcclusionTests, Sun::sunAccumulator, SkyObject, SkyObject::root: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's offsets
// NiNode, NiBillboardNode, BSTriShape, NiDirectionalLight, BSShaderAccumulator: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reference-counted objects
// NiRefObject, NiRefObject::DeleteThis, NiRefObject::IncRefCount, NiRefObject::DecRefCount, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches
// NiRefObject::m_uiRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); the name only
// Adapted bodies: none. The origin check reports NiPointer::~NiPointer, NiRefObject::IncRefCount as similar to bodies cited below (sibling files, CC0-1.0); ours are short forms written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshaderpplightingproperty.cpp:2424
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell_ob1_variant.cpp:133
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();  // 01

    // hot path: the engine counts references atomically, as NiRefObject::IncRefCount does
    void IncRefCount() { _InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        // hot path: the engine releases references atomically, as NiRefObject::DecRefCount does
        const long count = _InterlockedDecrement(&m_uiRefCount);
        if (count == 0) {
            DeleteThis();
        }
    }

    // volatile: the count is changed atomically with interlocked operations
    volatile long m_uiRefCount;  // 08
    std::uint32_t unk0C;
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
    NiPointer& operator=(T* a_object)
    {
        if (_ptr != a_object) {
            if (a_object) {
                a_object->IncRefCount();
            }
            T* old = _ptr;
            _ptr = a_object;
            if (old) {
                old->DecRefCount();
            }
        }
        return *this;
    }

    T* _ptr;
};

class NiNode : public NiRefObject {};
class NiBillboardNode : public NiRefObject {};
class BSTriShape : public NiRefObject {};
class NiDirectionalLight : public NiRefObject {};
class BSShaderAccumulator : public NiRefObject {};

class SkyObject
{
public:
    SkyObject();
    virtual ~SkyObject();  // callee at 0x41a180, not compared here

    NiPointer<NiNode> root;  // 08
};

class Sun : public SkyObject
{
public:
    Sun();
    ~Sun() override;  // compared: 0x41afe0

    NiPointer<NiBillboardNode> sunBaseNode;       // 10
    NiPointer<NiBillboardNode> sunGlareNode;      // 18
    NiPointer<BSTriShape> sunBase;                // 20
    NiPointer<BSTriShape> sunQuery;               // 28
    NiPointer<BSTriShape> sunGlare;               // 30
    NiPointer<NiDirectionalLight> light;          // 38
    NiPointer<NiDirectionalLight> cloudLight;     // 40
    float glareScale;                             // 48
    bool doOcclusionTests;                        // 4C
    NiPointer<BSShaderAccumulator> sunAccumulator;  // 50
};
static_assert(sizeof(Sun) == 0x58, "Sun size");
