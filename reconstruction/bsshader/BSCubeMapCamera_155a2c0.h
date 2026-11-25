// DeleteThis, DecRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Cookbook: 0x155a2c0 29
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// BSCubeMapCamera, NiCamera, NiPointer, NiRefObject, BSShaderAccumulator, scenes, accumulator, secondAccumulator, unk1B0, silhouetteColor: CRASHLOGGER_PDB(59818@2026.10.24)
// SceneArray: GUESS(low)
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
    ~NiPointer()
    {
        if (ptr) {
            ptr->DecRefCount();
        }
    }
};

class NiCamera : public NiRefObject
{
public:
    ~NiCamera() override;
    unsigned char unknown10[0x178];
};
class BSShaderAccumulator : public NiRefObject {};
class SceneArray
{
public:
    ~SceneArray();
    unsigned char storage[0x18];
};

class BSCubeMapCamera : public NiCamera
{
public:
    ~BSCubeMapCamera() override;

    SceneArray scenes;
    NiPointer<BSShaderAccumulator> accumulator;
    NiPointer<BSShaderAccumulator> secondAccumulator;
    NiPointer<NiCamera> unk1B0;
    float silhouetteColor[4];
};
static_assert(sizeof(NiCamera) == 0x188, "camera base size");
static_assert(sizeof(BSCubeMapCamera) == 0x1c8, "cube map camera size");
