// Source exposure: mixed (local pinned-image analysis and community PDB and CommonLibSSE-NG declarations).
// Code origin: original reconstruction from the contributor-owned image. The release idiom also occurs in both public siblings.
// NiPointer::~NiPointer: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0) SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535 (NiPointer destructor similarity).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513 (NiPointer destructor similarity).
// BSParabolicCullingProcess: EXE_RTTI
// BSCullingProcess, NiCamera, BSShaderAccumulator, NiPlane, NiPoint3, backHemisphereAccumulator, lightCamera: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPointer, _ptr, unk301F8, equatorialPlane, lightPosition, lightRadius: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject, DecRefCount, DeleteThis, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

#include <intrin.h>
#include "../../generated/crashlogger_pdb/types/NiPoint3.h"

struct NiPlane {
    NiPoint3 normal;
    float constant;
};

struct NiRefObject {
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long _refCount;

    void DecRefCount()
    {
        // Only the thread releasing the last reference destroys the object.
        const unsigned int remaining = _InterlockedDecrement(&_refCount);
        if (remaining == 0) {
            DeleteThis();
        }
    }
};

struct NiCamera : NiRefObject {};
struct BSShaderAccumulator : NiRefObject {};

template<class T>
class NiPointer {
public:
    ~NiPointer()
    {
        if (_ptr) {
            _ptr->DecRefCount();
        }
    }

private:
    T* _ptr = nullptr;
};

struct BSCullingProcess {
    virtual ~BSCullingProcess();
    unsigned char unknown08[0x301F0];
};

struct BSParabolicCullingProcess : BSCullingProcess {
    ~BSParabolicCullingProcess() override;
    float unk301F8;
    NiPointer<BSShaderAccumulator> backHemisphereAccumulator;
    NiPlane equatorialPlane;
    NiPoint3 lightPosition;
    float lightRadius;
    NiPointer<NiCamera> lightCamera;
};
