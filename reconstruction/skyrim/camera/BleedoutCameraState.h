// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BleedoutCameraState, BleedoutCameraState::~BleedoutCameraState, BleedoutCameraState::Begin, BleedoutCameraState::End, BleedoutCameraState::Update, ThirdPersonState, ThirdPersonState::~ThirdPersonState, ThirdPersonState::Begin, ThirdPersonState::CanProcess, ThirdPersonState::End, ThirdPersonState::Update, ThirdPersonState::GetRotation, ThirdPersonState::ProcessButton, ThirdPersonState::GetTranslation, ThirdPersonState::SaveGame, ThirdPersonState::LoadGame, ThirdPersonState::Revert, ThirdPersonState::SetCameraHandle, ThirdPersonState::Unk_0A, ThirdPersonState::ProcessWeaponDrawnChange, ThirdPersonState::GetFreeRotationMode, ThirdPersonState::SetFreeRotationMode, ThirdPersonState::UpdateRotation, ThirdPersonState::HandleLookInput, PlayerInputHandler, PlayerInputHandler::~PlayerInputHandler, PlayerInputHandler::CanProcess, PlayerInputHandler::ProcessThumbstick, PlayerInputHandler::ProcessMouseMove, PlayerInputHandler::ProcessButton, NiRefObject, NiRefObject::~NiRefObject, NiRefObject::_refCount, NiRefObject::DeleteThis, NiAVObject, NiPointer, NiMatrix3, NiMatrix3::entry, BSSoundHandle, BSSoundHandle::soundID, BSSoundHandle::assumeSuccess, BSSoundHandle::state: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the same source names every ThirdPersonState and BleedoutCameraState member below
// NiPointer::pointer, NiPointer::~NiPointer: GUESS(low); the inline release is reconstructed from the compared image (one interlocked decrement, then a virtual DeleteThis at count zero)
// unknown05, unknown06, unknown09, unknown0A, unknown0C, unknown11C, unknown135, unknown136, unknown8C, unknownDE, unknownE2, unknownE4: GUESS(low); typed fields at their observed offsets whose meaning the pinned community headers do not name
#pragma once

#include <cstdint>
#include <intrin.h>
#include "skyrim/camera/TESCameraState.h"

class InputEvent;
class ButtonEvent;
class PlayerControlsData;
class ThumbstickEvent;
class MouseMoveEvent;
class RefHandle;
class NiPoint2;
class NiNode;
class BGSSaveFormBuffer;

template <class T>
class BSTSmartPointer;

// NiRefObject, NiRefObject::_refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT);
// the compared destructor reads the count at +0x8 through NiPointer's inline release.
class NiRefObject
{
public:
    virtual ~NiRefObject();     // 00
    virtual void DeleteThis();  // 08

    // _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared long because
    // the pinned intrinsic set supplies only the volatile long overload at this width.
    volatile long _refCount;  // 08
    std::uint32_t unknown0C;           // 0C
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject community size");

// NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the compared destructor
// calls its virtual slot 1 through NiRefObject, so no field is represented in this unit.
class NiAVObject : public NiRefObject
{
public:
};

// NiPointer::pointer: GUESS(low); the community type keeps the raw pointer as its only member.
// The destructor is the inlined release the compared image shows.
template <class T>
class NiPointer
{
public:
    ~NiPointer()
    {
        // The release keeps the loaded target in a register; the compared listing loads the
        // member once and calls slot 1 through that same value.
        T* const object = pointer;
        if (object) {
            if (_InterlockedExchangeAdd(&object->_refCount, -1) == 1) {  // 4-byte interlocked decrement
                object->DeleteThis();
            }
        }
    }

    T* pointer;  // 00
};
static_assert(sizeof(NiPointer<NiAVObject>) == 0x8, "NiPointer size");

class NiMatrix3
{
public:
    float entry[3][3];  // 00
};
static_assert(sizeof(NiMatrix3) == 0x24, "NiMatrix3 community size");

class BSSoundHandle
{
public:
    std::uint32_t soundID;        // 00
    bool assumeSuccess;           // 04
    std::uint8_t unknown05;       // 05
    std::uint16_t unknown06;      // 06
    std::uint32_t state;          // 08
};
static_assert(sizeof(BSSoundHandle) == 0xC, "BSSoundHandle community size");

// PlayerInputHandler is the second polymorphic base of ThirdPersonState at +0x20; its vftable
// pointer is the second store the compared destructor makes.
class PlayerInputHandler
{
public:
    virtual ~PlayerInputHandler();                                       // 00
    virtual bool CanProcess(InputEvent* a_event);                        // 08
    virtual void ProcessThumbstick(ThumbstickEvent* a_event, PlayerControlsData* a_data);  // 10
    virtual void ProcessMouseMove(MouseMoveEvent* a_event, PlayerControlsData* a_data);    // 18
    virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data);          // 20

    bool inputEventHandlingEnabled;  // 08
    std::uint8_t unknown09;          // 09
    std::uint16_t unknown0A;         // 0A
    std::uint32_t unknown0C;         // 0C
};
static_assert(sizeof(PlayerInputHandler) == 0x10, "PlayerInputHandler community size");

class ThirdPersonState :
    public TESCameraState,      // 00
    public PlayerInputHandler   // 20
{
public:
    virtual ~ThirdPersonState();  // 00
    void Begin() override;                                          // 01
    bool CanProcess(InputEvent* a_event) override;                  // 01
    void End() override;                                            // 02
    virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState);  // 03
    void GetRotation(NiQuaternion& a_rotation) override;            // 04
    void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_movementData) override;  // 04
    void GetTranslation(NiPoint3& a_translation) override;          // 05
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);                 // 06
    void LoadGame(BGSLoadFormBuffer* a_buf) override;                // 07
    virtual void Revert(BGSLoadFormBuffer* a_buf);                   // 08
    virtual void SetCameraHandle(RefHandle& a_handle);               // 09
    virtual void Unk_0A(void);                                       // 0A
    virtual void ProcessWeaponDrawnChange(bool a_drawn);             // 0B
    virtual bool GetFreeRotationMode() const;                        // 0C
    virtual void SetFreeRotationMode(bool a_weaponSheathed);         // 0D
    virtual void UpdateRotation();                                   // 0E
    virtual void HandleLookInput(const NiPoint2& a_input);           // 0F

    NiAVObject* thirdPersonCameraObj;    // 30
    NiNode* thirdPersonFOVControl;       // 38
    NiPoint3 translation;                // 40
    NiQuaternion rotation;               // 4C
    NiPoint3 posOffsetExpected;          // 5C
    NiPoint3 posOffsetActual;            // 68
    float targetZoomOffset;              // 74
    float currentZoomOffset;             // 78
    float targetYaw;                     // 7C
    float currentYaw;                    // 80
    float savedZoomOffset;               // 84
    float pitchZoomOffset;               // 88
    float unknown8C;                     // 8C
    NiPoint3 collisionPos;               // 90
    float collisionPosValid;             // 9C
    std::uint64_t unknownA0;             // A0
    void* animatedBoneName;              // A8
    NiQuaternion animationRotation;      // B0
    std::uint64_t unknownC0;             // C0
    std::uint64_t unknownC8;             // C8
    std::uint32_t unknownD0;             // D0
    float freeRotation[2];               // D4
    bool freeRotationEnabled;            // DC
    bool stateNotActive;                 // DD
    std::uint16_t unknownDE;             // DE
    bool toggleAnimCam;                  // E0
    bool applyOffsets;                   // E1
    std::uint16_t unknownE2;             // E2
    std::uint32_t unknownE4;             // E4
};
static_assert(sizeof(ThirdPersonState) == 0xE8, "ThirdPersonState size");

class BleedoutCameraState : public ThirdPersonState
{
public:
    BleedoutCameraState();
    virtual ~BleedoutCameraState();  // compared: 0x8fc4f0

    void Begin() override;                                           // 01
    void End() override;                                             // 02
    virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState);  // 03

    NiMatrix3 rotationMtx;                // 0E8
    float zoom;                           // 10C
    float pitch;                          // 110
    float yaw;                            // 114
    float randHeading;                    // 118
    std::uint32_t unknown11C;             // 11C
    NiPointer<NiAVObject> animatedBone;   // 120
    BSSoundHandle activeSound;            // 128
    bool useCurrentHeading;               // 134
    std::uint8_t unknown135;              // 135
    std::uint16_t unknown136;             // 136
};
static_assert(sizeof(BleedoutCameraState) == 0x138, "BleedoutCameraState size");
