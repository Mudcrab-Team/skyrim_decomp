// Source exposure: mixed (pinned image and the cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial camera declarations follow the existing PlayerCamera unit and the cited public headers.
// PlayerCamera, TESCamera, cameraTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstddef>
#include <cstdint>
// Actor: EXE_RTTI
class Actor {
public:
    bool Function6abb10() const;
};

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
// unknown0C, unknown1C: GUESS(low); unknown words beside the state fields.
class TESCamera;
struct CameraStates {
    enum CameraState : std::uint32_t {
        kFirstPerson = 0,
        kAutoVanity = 1,
        kVATS = 2,
        kIronSights = 4,
        kTween = 7,
        kThirdPerson = 9,
        kMount = 10,
        kDragon = 12,
        kTotal = 13
    };
};
using CameraState = CameraStates::CameraState;
class TESCameraState {
public:
    virtual ~TESCameraState();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual void FunctionSlot03();
    virtual void FunctionSlot04();
    virtual void FunctionSlot05();
    virtual void FunctionSlot06();
    virtual void FunctionSlot07();
    virtual void FunctionSlot08();
    std::uint32_t refCount;    // 08
    std::uint32_t unknown0C;   // 0C
    TESCamera*    camera;      // 10
    CameraState   id;          // 18
    std::uint32_t unknown1C;   // 1C
};
static_assert(offsetof(TESCameraState, id) == 0x18, "camera state ID offset");

// ThirdPersonState::GetFreeRotationMode, freeRotation, toggleAnimCam, thirdPersonCameraObj: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FirstPersonState, firstPersonCameraObj, kAutoVanity, kVATS, kIronSights, kTween, kMount, kDragon: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FirstPersonState::overrideFlags, flag88, flag89, unknown8A, flag8B: GUESS(low); observed accesses with unresolved individual meanings.
// CameraSceneObject, IronSightsState, IronSightsState::cameraObject, VATSCameraState, TweenCameraState, PlayerCameraInput: STANDIN GUESS(low)
// localTranslateZ: GUESS(medium); offset agrees with NiAVObject::local.translate.z.
struct CameraSceneObject {
    std::uint8_t padding00[0x74];
    float localTranslateZ;
};

class FirstPersonState : public TESCameraState {
public:
    void Function8f5370(Actor* actor);

    std::uint8_t padding20[0x58 - 0x20];
    CameraSceneObject* firstPersonCameraObj;
    std::uint8_t padding60[0x84 - 0x60];
    std::uint32_t overrideFlags;
    bool flag88;
    bool flag89;
    std::uint8_t unknown8A;
    bool flag8B;
};

class ThirdPersonState : public TESCameraState {
public:
    virtual void FunctionSlot09();
    virtual void FunctionSlot0A();
    virtual void FunctionSlot0B();
    virtual bool GetFreeRotationMode() const;

    void Function8fda40(Point3& result, bool configured);

    std::uint8_t padding20[0x10];
    CameraSceneObject* thirdPersonCameraObj;
    std::uint8_t padding38[0xD4 - 0x38];
    Point2 freeRotation;
    std::uint8_t paddingDC[4];
    bool toggleAnimCam;
};

class IronSightsState : public TESCameraState {
public:
    CameraSceneObject* cameraObject;
};

class VATSCameraState : public TESCameraState {
public:
    void Function9002a0(const Point3& position);
    void Function900280(float x, float y, float z);
};

class TweenCameraState : public TESCameraState {
public:
    void Function8ff750(std::uint32_t mode);
    void Function8ff880();
};

class PlayerCameraInput {
public:
    bool Function7ae030() const;
};

// ActorHandle: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorHandle::value, ActorHandle::GetTarget, FunctionSlot declarations, padding, Function declarations: STANDIN GUESS(low)
// ActorPointer, ActorPointer::pointer: STANDIN GUESS(medium)
struct ActorPointer {
    Actor* pointer;
};

struct ActorHandle {
    bool GetTarget(ActorPointer& target) const;
    unsigned value;
};
static_assert(sizeof(ActorHandle) == 4, "actor handle size");

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
    ActorHandle cameraTarget;      // 3C
    CameraReturnStates tempReturnStates;
    TESCameraState* cameraStates[CameraStates::kTotal];

    // worldFOV, firstPersonFOV, idleTimer, allowAutoVanityMode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint8_t unknown120[0x13C - 0x120];
    float worldFOV;
    float firstPersonFOV;
    std::uint8_t unknown144[0x150 - 0x144];
    float idleTimer;
    std::uint8_t unknown154[0x160 - 0x154];
    bool allowAutoVanityMode;

    bool Function8fc810() const;
    void Function8fc920(CameraState state);
    TESCameraState* Function8fc8a0();

    float Function8f8c70() const;
    void Function8f8e30(Actor* actor);
    bool Function8f8ff0() const;
    void Function8f9030(Point3& result, bool configured);
    void Function8f90e0();
    Point2* Function8f9100();
    void Function8f9140(bool allow);
    void Function8f9250();
    void Function8f92f0(const Point3& position);
    void Function8f9310(float x, float y, float z);
    void Function8f98f0(bool enabled);
    void Function8f99c0(std::uint32_t mode);
    void Function8f99e0();
    void Function8fb210();
    bool Function8fb240(ActorPointer& target) const;
    bool Function8fb2a0() const;
    void Function8fb680(bool enabled);
    void Function8fb6a0(bool enabled);
    void Function8fc100(std::uint32_t value);
    void Function8fc170();
    void Function8fc1c0();
};
static_assert(offsetof(PlayerCamera, cameraTarget) == 0x3c, "camera target offset");
static_assert(offsetof(PlayerCamera, cameraStates) == 0xb8, "camera states offset");
static_assert(offsetof(PlayerCamera, worldFOV) == 0x13C, "world FOV offset");
static_assert(offsetof(PlayerCamera, idleTimer) == 0x150, "idle timer offset");
static_assert(offsetof(FirstPersonState, overrideFlags) == 0x84, "first-person state field offset");
static_assert(offsetof(ThirdPersonState, toggleAnimCam) == 0xE0, "third-person state field offset");
