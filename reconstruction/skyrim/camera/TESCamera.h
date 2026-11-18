// Code origin: names, bases, virtual slots and member offsets from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the body is written from the listing of the pinned image
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESCamera, TESCamera::~TESCamera, ::SetCameraRoot, ::Update, ::rotationInput, ::translationInput, ::zoomInput, ::cameraRoot, ::currentState, ::enabled, ::pad31, ::pad32, ::pad34: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESCamera::GetNode: STANDIN GUESS(low); NG declares no such function, the name comes from the target's symbol context and its signature and body are written from the listing
// NiPointer, NiPointer::operator=, NiRefObject, NiRefObject::DeleteThis, NiRefObject::_refCount, NiNode, BSTPoint2, BSTPoint3, BSTSmartPointer, TESCameraState: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to the members the code needs, NiNode only as a reference-counted target
// NiRefObject::pad0C: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class TESCameraState;

class NiRefObject
{
public:
    virtual ~NiRefObject();  // 00
    virtual void DeleteThis();  // 01

    std::uint32_t _refCount;  // 08
    std::uint32_t pad0C;      // 0C
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiNode : public NiRefObject
{
};

template <class T>
class NiPointer
{
public:
    NiPointer& operator=(const NiPointer& a_rhs)
    {
        T* old = pointer;
        T* object = a_rhs.pointer;
        if (old != object) {
            if (object) {
                // Locked refcount increment, as the compared NiPointer assignment does.
                _InterlockedIncrement(reinterpret_cast<volatile long*>(&object->_refCount));
            }
            pointer = object;
            if (old) {
                // Locked refcount decrement, as the compared NiPointer assignment does.
                if (_InterlockedDecrement(reinterpret_cast<volatile long*>(&old->_refCount)) == 0) {
                    old->DeleteThis();
                }
            }
        }
        return *this;
    }

    T* pointer;  // 00
};
static_assert(sizeof(NiPointer<NiNode>) == 0x8, "NiPointer size");

struct BSTPoint2
{
    float x;  // 00
    float y;  // 04
};

struct BSTPoint3
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};

template <class T>
class BSTSmartPointer
{
public:
    T* ptr;  // 00
};

class TESCamera
{
public:
    virtual ~TESCamera();  // 00
    virtual void SetCameraRoot(NiPointer<NiNode> a_root);  // 01
    virtual void Update();  // 02
    bool GetNode(NiPointer<NiNode>& a_out);  // compared: 0x558e10

    BSTPoint2                       rotationInput;     // 08
    BSTPoint3                       translationInput;  // 10
    float                           zoomInput;         // 1C
    NiPointer<NiNode>               cameraRoot;        // 20
    BSTSmartPointer<TESCameraState> currentState;      // 28
    bool                            enabled;           // 30
    std::uint8_t                    pad31;             // 31
    std::uint16_t                   pad32;             // 32
    std::uint32_t                   pad34;             // 34
};
static_assert(sizeof(TESCamera) == 0x38, "TESCamera size");
static_assert(offsetof(TESCamera, cameraRoot) == 0x20, "TESCamera::cameraRoot offset");
