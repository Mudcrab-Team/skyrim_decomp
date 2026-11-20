// Source exposure: mixed (pinned image and the cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original camera forwarding and state access from the pinned image.
// 0x8f8c70 PlayerCamera::Function8f8c70
// 0x8f8e30 PlayerCamera::Function8f8e30
// 0x8f8ff0 PlayerCamera::Function8f8ff0
// 0x8f9030 PlayerCamera::Function8f9030
// 0x8f90e0 PlayerCamera::Function8f90e0
// 0x8f9100 PlayerCamera::Function8f9100
// 0x8f9140 PlayerCamera::Function8f9140
// 0x8f9250 PlayerCamera::Function8f9250
// 0x8f92f0 PlayerCamera::Function8f92f0
// 0x8f9310 PlayerCamera::Function8f9310
// 0x8f98f0 PlayerCamera::Function8f98f0
// 0x8f99c0 PlayerCamera::Function8f99c0
// 0x8f99e0 PlayerCamera::Function8f99e0
// 0x8fb210 PlayerCamera::Function8fb210
// 0x8fb240 PlayerCamera::Function8fb240
// 0x8fb2a0 PlayerCamera::Function8fb2a0
// 0x8fb680 PlayerCamera::Function8fb680
// 0x8fb6a0 PlayerCamera::Function8fb6a0
// 0x8fc100 PlayerCamera::Function8fc100
// 0x8fc170 PlayerCamera::Function8fc170
// 0x8fc1c0 PlayerCamera::Function8fc1c0
#include "PlayerCamera_8f8c70.h"

// defaultFirstPersonFOV, defaultWorldFOV, playerHandle: GUESS(low)
extern float defaultFirstPersonFOV;
extern float defaultWorldFOV;
extern unsigned playerHandle;

// IsThirdPersonOrLater: GUESS(low)
static bool IsThirdPersonOrLater(const TESCameraState* a_state)
{
    return a_state ? a_state->id >= CameraStates::kThirdPerson : false;
}

// cameraOriginX, cameraOriginY, cameraOriginZ, vanityModeRestricted, cameraInput, cameraActor: GUESS(low)
extern float cameraOriginX;
extern float cameraOriginY;
extern float cameraOriginZ;
extern bool vanityModeRestricted;
extern PlayerCameraInput* cameraInput;
extern Actor* cameraActor;

float PlayerCamera::Function8f8c70() const
{
    const auto* thirdPerson = static_cast<const ThirdPersonState*>(cameraStates[CameraStates::kThirdPerson]);
    if (thirdPerson && thirdPerson->thirdPersonCameraObj) {
        return thirdPerson->thirdPersonCameraObj->localTranslateZ;
    }
    return 0.0f;
}

void PlayerCamera::Function8f8e30(Actor* actor)
{
    auto* firstPerson = static_cast<FirstPersonState*>(cameraStates[CameraStates::kFirstPerson]);
    firstPerson->Function8f5370(actor);
    static_cast<IronSightsState*>(cameraStates[CameraStates::kIronSights])->cameraObject = firstPerson->firstPersonCameraObj;
}

bool PlayerCamera::Function8f8ff0() const
{
    if (IsThirdPersonOrLater(currentState)) {
        if (static_cast<const ThirdPersonState*>(currentState)->GetFreeRotationMode()) {
            return true;
        }
    }
    return false;
}

void PlayerCamera::Function8f9030(Point3& result, bool configured)
{
    if (auto* thirdPerson = static_cast<ThirdPersonState*>(cameraStates[CameraStates::kThirdPerson])) {
        return thirdPerson->Function8fda40(result, configured);
    }
    result.x = cameraOriginX;
    result.y = cameraOriginY;
    result.z = cameraOriginZ;
}

void PlayerCamera::Function8f90e0()
{
    auto* thirdPerson = static_cast<ThirdPersonState*>(cameraStates[CameraStates::kThirdPerson]);
    thirdPerson->toggleAnimCam = !thirdPerson->toggleAnimCam;
}

Point2* PlayerCamera::Function8f9100()
{
    auto state = cameraActor->Function6abb10() ? CameraStates::kDragon : CameraStates::kMount;
    return &static_cast<ThirdPersonState*>(cameraStates[state])->freeRotation;
}

void PlayerCamera::Function8f9140(bool allow)
{
    if (allow && !vanityModeRestricted) {
        allowAutoVanityMode = true;
    } else {
        allowAutoVanityMode = false;
    }
}

void PlayerCamera::Function8f9250()
{
    if (cameraTarget.value == playerHandle && !Function8fc810()) {
        return SetState(cameraStates[CameraStates::kVATS]);
    }
}

void PlayerCamera::Function8f92f0(const Point3& position)
{
    return static_cast<VATSCameraState*>(cameraStates[CameraStates::kVATS])->Function9002a0(position);
}

void PlayerCamera::Function8f9310(float x, float y, float z)
{
    return static_cast<VATSCameraState*>(cameraStates[CameraStates::kVATS])->Function900280(x, y, z);
}

void PlayerCamera::Function8f98f0(bool enabled)
{
    static_cast<FirstPersonState*>(cameraStates[CameraStates::kFirstPerson])->flag8B = enabled;
}

void PlayerCamera::Function8f99c0(std::uint32_t mode)
{
    return static_cast<TweenCameraState*>(cameraStates[CameraStates::kTween])->Function8ff750(mode);
}

void PlayerCamera::Function8f99e0()
{
    return static_cast<TweenCameraState*>(cameraStates[CameraStates::kTween])->Function8ff880();
}

void PlayerCamera::Function8fb210()
{
    firstPersonFOV = defaultFirstPersonFOV;
    worldFOV = defaultWorldFOV;
}

bool PlayerCamera::Function8fb240(ActorPointer& target) const
{
    return cameraTarget.GetTarget(target);
}

bool PlayerCamera::Function8fb2a0() const
{
    return cameraStates[CameraStates::kFirstPerson] || cameraStates[CameraStates::kThirdPerson] ||
           cameraStates[CameraStates::kMount] || cameraStates[CameraStates::kDragon];
}

void PlayerCamera::Function8fb680(bool enabled)
{
    if (auto* firstPerson = static_cast<FirstPersonState*>(cameraStates[CameraStates::kFirstPerson])) {
        firstPerson->flag88 = enabled;
    }
}

void PlayerCamera::Function8fb6a0(bool enabled)
{
    if (auto* firstPerson = static_cast<FirstPersonState*>(cameraStates[CameraStates::kFirstPerson])) {
        firstPerson->flag89 = enabled;
    }
}

void PlayerCamera::Function8fc100(std::uint32_t value)
{
    if (auto* firstPerson = static_cast<FirstPersonState*>(cameraStates[CameraStates::kFirstPerson])) {
        firstPerson->overrideFlags = value;
    }
}

void PlayerCamera::Function8fc170()
{
    if (currentState != cameraStates[CameraStates::kAutoVanity] && cameraInput->Function7ae030()) {
        return Function8fc920(CameraStates::kAutoVanity);
    }
}

void PlayerCamera::Function8fc1c0()
{
    if (currentState == cameraStates[CameraStates::kAutoVanity]) {
        SetState(Function8fc8a0());
        idleTimer = 0.0f;
    }
}
