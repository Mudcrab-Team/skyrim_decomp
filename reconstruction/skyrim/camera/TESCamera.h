// Code origin: names, bases, virtual slots and member offsets from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the body is written from the listing of the pinned image
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESCamera, TESCamera::~TESCamera, ::SetCameraRoot, ::Update, ::rotationInput, ::translationInput, ::zoomInput, ::cameraRoot, ::currentState, ::enabled, ::pad31, ::pad32, ::pad34: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESCamera::SetState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESCamera::GetNode: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); signature from the pinned image
// TESCamera::Function9969f0, TESCamera::unk4C, TESCamera::pad38: GUESS(low); the body is written from the listing
// NiPointer, NiPointer::operator=, NiRefObject, NiRefObject::DeleteThis, NiRefObject::_refCount, NiNode, BSTPoint2, BSTPoint3, BSTSmartPointer, TESCameraState: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to the members the code needs, NiNode only as a reference-counted target
// NiRefObject::pad0C: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class TESCameraState;
template <class T> class BSTSmartPointer;

// TESCameraState, TESCameraState::Begin, TESCameraState::End: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESCameraState::Release, TESCameraState::refCount, TESCameraState::unk0C: GUESS(low); slot 0, called with 1 when the last reference is dropped
class TESCameraState
{
public:
    virtual void Release(std::uint32_t a_free) noexcept;  // 00
    virtual void Begin();               // 01
    virtual void End();                 // 02
    // Update: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState);  // 03

    std::uint32_t refCount;  // 08
    std::uint32_t unk0C;     // 0C
};
static_assert(sizeof(TESCameraState) == 0x10, "TESCameraState size");

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

// gNeutralCameraRotationInput, gNeutralCameraTranslationInput: GUESS(low)
extern const BSTPoint2 gNeutralCameraRotationInput;
extern const BSTPoint3 gNeutralCameraTranslationInput;

template <class T>
class BSTSmartPointer
{
public:
    ~BSTSmartPointer()
    {
        T* object = ptr;
        // Atomically drop the owned reference and test whether it was the last one.
        if (object && _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&object->refCount), -1) == 1) {
            object->Release(1);
        }
    }

    BSTSmartPointer& operator=(T* a_rhs)
    {
        T* old = ptr;
        if (a_rhs != old) {
            if (a_rhs) {
                // Locked refcount increment, as the compared assignment does.
                _InterlockedIncrement(reinterpret_cast<volatile long*>(&a_rhs->refCount));
            }
            ptr = a_rhs;
            // Locked refcount decrement with release, as the compared assignment does.
            if (old && _InterlockedDecrement(reinterpret_cast<volatile long*>(&old->refCount)) == 0) {
                old->Release(1);
            }
        }
        return *this;
    }

    T* ptr;  // 00
};

class TESCamera
{
public:
    virtual ~TESCamera();  // 00
    virtual void SetCameraRoot(NiPointer<NiNode> a_root);  // 01
    // noinline: kept out of line so Function9969f0 tail-jumps to Update as the game does, not an inlined copy.
    __declspec(noinline) virtual void Update();  // 02
    bool GetNode(NiPointer<NiNode>& a_out);  // compared: 0x558e10
    void SetState(TESCameraState* a_state);  // compared: 0x558f90
    void Function9969f0(float a_value);  // compared: 0x9969f0

    BSTPoint2                       rotationInput;     // 08
    BSTPoint3                       translationInput;  // 10
    float                           zoomInput;         // 1C
    NiPointer<NiNode>               cameraRoot;        // 20
    BSTSmartPointer<TESCameraState> currentState;      // 28
    bool                            enabled;           // 30
    std::uint8_t                    pad31;             // 31
    std::uint16_t                   pad32;             // 32
    std::uint32_t                   pad34;             // 34
    std::uint8_t                    pad38[0x14];       // 38 (unused filler)
    float                           unk4C;             // 4C
};
static_assert(sizeof(TESCamera) == 0x50, "TESCamera size");
static_assert(offsetof(TESCamera, cameraRoot) == 0x20, "TESCamera::cameraRoot offset");

