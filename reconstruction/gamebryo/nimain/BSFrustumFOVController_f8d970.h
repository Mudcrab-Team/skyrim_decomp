// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// Adapted bodies: NiRefObject::DecRefCount, NiPointer::~NiPointer (sibling ref-count idioms noted below).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e include/NiRefObject_inline.h:32 (NiRefObject::DecRefCount).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:7827 (NiRefObject::DecRefCount).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535 (NiPointer::~NiPointer).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshaderpplightingproperty.cpp:2278 (NiPointer::~NiPointer).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFrustumFOVController, NiTimeController, NiInterpController, NiInterpolator, NiRefObject, NiPointer: CRASHLOGGER_PDB(59818@2026.10.24)
// DeleteThis, DecRefCount, NiSingleInterpController, NiFloatInterpController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// refCount, activeInterpolator: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

void operator delete(void* object, std::size_t size) noexcept;

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    long refCount;  // 08
    std::uint32_t unk0C;  // 0C

    void DecRefCount()
    {
        // Atomic reference count decrement shared across threads.
        if (_InterlockedDecrement(&refCount) == 0) {
            DeleteThis();
        }
    }
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

template <class T>
struct NiPointer
{
    T* object;

    ~NiPointer()
    {
        if (object) {
            object->DecRefCount();
        }
    }
};

class NiInterpolator : public NiRefObject
{
};

class NiObject : public NiRefObject
{
};

class NiTimeController : public NiObject
{
public:
    ~NiTimeController() override;

    std::uint8_t unk10[0x38];  // 10
};
static_assert(sizeof(NiTimeController) == 0x48, "NiTimeController size");

class NiInterpController : public NiTimeController
{
};

class NiSingleInterpController : public NiInterpController
{
public:
    NiPointer<NiInterpolator> activeInterpolator;  // 48
};
static_assert(sizeof(NiSingleInterpController) == 0x50, "NiSingleInterpController size");

class NiFloatInterpController : public NiSingleInterpController
{
};

class BSFrustumFOVController : public NiFloatInterpController
{
public:
    BSFrustumFOVController();
};
static_assert(sizeof(BSFrustumFOVController) == 0x50, "BSFrustumFOVController size");
