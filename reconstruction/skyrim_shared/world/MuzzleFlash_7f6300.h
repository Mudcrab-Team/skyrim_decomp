// Source exposure: mixed (the listing of the pinned image; names from the sibling declarations used by the adapted body).
// Code origin: names and member usage adapted from the sibling; offsets and the callee checked against the listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/MuzzleFlash.cpp:186
// MuzzleFlash, MuzzleFlash::DetachLight, MuzzleFlash::spLight, ShadowSceneNode::RemoveLight, NiPointer::m_pObject: SIBLING(fo4-private@1b765c70, author-permission)
// NiLight, NiLight::DeleteThis, ShadowSceneNode: STANDIN SIBLING(fo4-private@1b765c70, author-permission); only what the function uses is modelled
// pShadowSceneNode: GUESS(low); the global shadow scene node pointer the function reads
#pragma once

#include <intrin.h>

class NiLight
{
public:
    virtual ~NiLight();         // 00
    virtual void DeleteThis();  // 01

    // The reference count is atomic: lights are shared between the scene and the effect.
    void DecRefCount()
    {
        if (_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)) == 0) {  // atomic refcount decrement
            DeleteThis();
        }
    }

    unsigned int refCount;  // 08
};

template <class T>
class NiPointer
{
public:
    NiPointer& operator=(T* a_object)
    {
        if (m_pObject != a_object) {
            T* old = m_pObject;
            m_pObject = a_object;
            if (old) {
                old->DecRefCount();
            }
        }
        return *this;
    }

    T* m_pObject;
};

class ShadowSceneNode
{
public:
    void RemoveLight(NiLight* a_light);  // bound: 0x150cff0
};

extern ShadowSceneNode* pShadowSceneNode;

class MuzzleFlash
{
public:
    void DetachLight();  // compared: 0x7f6300

    unsigned char unk00[0x20];  // 00
    NiPointer<NiLight> spLight;  // 20
};
