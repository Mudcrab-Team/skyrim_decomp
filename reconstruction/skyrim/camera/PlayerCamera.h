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
// BaseFormComponent, TESForm, TESForm::sourceFiles, formFlags, formID, inGameFormFlags, formType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the form layout up to 0x20
// NiRefObject, BSHandleRefObject, TESObjectREFR, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the bases and the count the compared code reads
// refCount, unknown1B, unknown1C, unknown0C: GUESS(low); the reference count and unresolved words at their offsets
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent {
public:
    void*          sourceFiles;      // 08
    std::uint32_t  formFlags;        // 10
    std::uint32_t  formID;           // 14
    std::uint16_t  inGameFormFlags;  // 18
    std::uint8_t   formType;         // 1A
    std::uint8_t   unknown1B;        // 1B
    std::uint32_t  unknown1C;        // 1C
};
static_assert(sizeof(TESForm) == 0x20, "form size");
class NiRefObject {
public:
    virtual ~NiRefObject();
    std::uint32_t refCount;    // 08
    std::uint32_t unknown0C;   // 0C
};
class BSHandleRefObject : public NiRefObject {};
class TESObjectREFR : public TESForm, public BSHandleRefObject {};
class Actor : public TESObjectREFR {};

extern unsigned nullHandle;
void CreateRefHandle(unsigned&, TESObjectREFR*);
// BSTPoint2, BSTPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct Point2 {
    float x;
    float y;
};
struct Point3 {
    float x;
    float y;
    float z;
};
// TESCameraState, CameraState, CameraStates, kFirstPerson, kThirdPerson, kTotal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// id, camera, currentState, SetState, cameraStates, tempReturnStates, ThirdPersonState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetFirstPersonMode, PrepareThirdPerson: GUESS(low); camera mode helpers.
// unknown0C, unknown1C: GUESS(low); unknown words beside the state fields.
class TESCamera;
struct CameraStates {
    enum CameraState : std::uint32_t { kFirstPerson = 0, kThirdPerson = 9, kTotal = 13 };
};
using CameraState = CameraStates::CameraState;
class TESCameraState {
public:
    virtual ~TESCameraState();
    std::uint32_t refCount;    // 08
    std::uint32_t unknown0C;   // 0C
    TESCamera*    camera;      // 10
    CameraState   id;          // 18
    std::uint32_t unknown1C;   // 1C
};
static_assert(offsetof(TESCameraState, id) == 0x18, "camera state ID offset");

class ThirdPersonState : public TESCameraState {
public:
    void PrepareThirdPerson(bool a_wasDrawn, bool a_isDrawn);
};

// unknown31, unknown32, unknown34: GUESS(low); unknown words after the enabled flag.
class TESCamera {
public:
    virtual ~TESCamera();
    void SetState(TESCameraState* a_state);

    Point2          rotationInput;     // 08
    Point3          translationInput;  // 10
    float           zoomInput;         // 1C
    void*           cameraRoot;        // 20
    TESCameraState* currentState;      // 28
    bool            enabled;           // 30
    std::uint8_t    unknown31;         // 31
    std::uint16_t   unknown32;         // 32
    std::uint32_t   unknown34;         // 34
};
static_assert(sizeof(TESCamera) == 0x38, "camera size");

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

// unknown38, unknown39, unknown3A: GUESS(low); the storage of the singleton base and the words before the target handle.
class PlayerCamera : public TESCamera {
public:
    std::uint8_t  unknown38;    // 38
    std::uint8_t  unknown39;    // 39
    std::uint16_t unknown3A;    // 3A
    unsigned cameraTarget;      // 3C
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
