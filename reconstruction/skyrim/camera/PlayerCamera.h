// Code origin: original camera-mode bodies from the pinned image and community declarations.
// CreateRefHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); output parameter declaration adapted from include/RE/M/Misc.h; target callee identity remains inferred.
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// PlayerCamera::SetCameraTarget: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/PlayerCamera.cpp:272
// PlayerCamera, TESCamera, BSHandleRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/P/PlayerCamera.h, include/RE/T/TESCamera.h, include/RE/T/TESObjectREFR.h, include/RE/B/BSHandleRefObject.h and include/RE/B/BSPointerHandle.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

#include <cstddef>
#include <cstdint>
class Component { public: virtual ~Component(); };
class TESForm : public Component { public: void* files; unsigned flags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2; };
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount, pad; };
class BSHandleRefObject : public NiRefObject {};
class TESObjectREFR : public TESForm, public BSHandleRefObject {};
class Actor : public TESObjectREFR {};

extern unsigned nullHandle;
void CreateRefHandle(unsigned&, TESObjectREFR*);
struct Point2 { float x,y; }; struct Point3 { float x,y,z; };
// TESCameraState, CameraState, CameraStates, kFirstPerson, kThirdPerson, kTotal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// id, camera, currentState, SetState, cameraStates, tempReturnStates, ThirdPersonState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetFirstPersonMode, PrepareThirdPerson: GUESS(low); camera mode helpers.
// pad0c, pad1c: GUESS(low); unknown words beside the state fields.
class TESCamera;
struct CameraStates {
    enum CameraState : std::uint32_t { kFirstPerson = 0, kThirdPerson = 9, kTotal = 13 };
};
using CameraState = CameraStates::CameraState;
class TESCameraState {
public:
    virtual ~TESCameraState();
    unsigned refCount;
    unsigned pad0c;
    TESCamera* camera;
    CameraState id;
    unsigned pad1c;
};
static_assert(offsetof(TESCameraState, id) == 0x18, "camera state ID offset");

class ThirdPersonState : public TESCameraState {
public:
    void PrepareThirdPerson(bool a_wasDrawn, bool a_isDrawn);
};

class TESCamera {
public:
    virtual ~TESCamera();
    void SetState(TESCameraState* a_state);

    Point2 rotationInput;
    Point3 translationInput;
    float zoomInput;
    void* cameraRoot;
    TESCameraState* currentState;
    bool enabled;
    unsigned char pad31;
    unsigned short pad32;
    unsigned pad34;
};
class Singleton {};

// CameraReturnStates: GUESS(low); layout view of the pinned small array's allocator and size.
// BSTSmallArrayHeapAllocator::_capacity, BSTSmallArrayHeapAllocator::_local: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTArrayBase::_size: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// internal, external: GUESS(low)
struct CameraReturnStates {
    std::uint32_t _capacity : 31;
    std::uint32_t _local : 1;
    union {
        TESCameraState* internal[CameraStates::kTotal];
        TESCameraState** external;
    };
    std::uint32_t _size;
};
static_assert(sizeof(CameraReturnStates) == 0x78, "temporary camera state array size");

class PlayerCamera : public TESCamera, public Singleton {
public:
    unsigned char pad39;
    unsigned short pad3a;
    unsigned cameraTarget;
    CameraReturnStates tempReturnStates;
    TESCameraState* cameraStates[CameraStates::kTotal];

    void SetCameraTarget(Actor*);
    // GetCurrentNormalFOV: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
    // ForceFirstPerson, ForceThirdPerson: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    float GetCurrentNormalFOV() const;
    void ForceFirstPerson();
    void ForceThirdPerson();
    void SetFirstPersonMode();
};
static_assert(offsetof(PlayerCamera, cameraTarget) == 0x3c, "camera target offset");
static_assert(offsetof(PlayerCamera, cameraStates) == 0xb8, "camera states offset");
