// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: ThirdPersonState::GetRotation and ::GetTranslation were adapted from the anonymous fo4-private sibling as labelled (author permission); ThirdPersonState::GetFreeRotationMode was written from the pinned image listing by Taylor Turner with Claude Sonnet 5.5 (first drafts by DeepSeek V4.1 Flash) with no adapted body; declarations from the pinned community headers.
// GetRotation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:106
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:112
// ThirdPersonState, ThirdPersonState::GetRotation, ThirdPersonState::GetTranslation: SIBLING(fo4-private@1b765c70, author-permission)
// ThirdPersonState, TESCameraState, PlayerInputHandler, PlayerControls, PlayerControlsData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// thirdPersonCameraObj, thirdPersonFOVControl, translation, rotation, posOffsetExpected, posOffsetActual, targetZoomOffset, currentZoomOffset, targetYaw, currentYaw, savedZoomOffset, pitchZoomOffset, unk8C, collisionPos, collisionPosValid, unkA0, animatedBoneName, animationRotation, unkC0, unkC8, unkD0, freeRotation, freeRotationEnabled, stateNotActive, toggleAnimCam, applyOffsets, unkE2, unkE4: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// moveInputVec, lookInputVec, prevMoveVec, prevLookVec, unk20, autoMove, running, unk26, fovSlideMode, povScriptMode, povBeastMode, unk2A, unk2B, remapMode, unk2D, unk2E: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// camera, id, inputEventHandlingEnabled, data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// playerControls: GUESS(low); the singleton accessor is not declared in the pinned checkout.
// unkDE: GUESS(low); the pinned checkout spells this 0xDE halfword unkDC, so this unit uses its own unknown name.
// GetFreeRotationMode readers toggleAnimCam, freeRotationEnabled and the singleton fovSlideMode from the pinned image listing.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
struct NiPoint2 { float x, y; };
struct NiPoint3 { float x, y, z; };
struct NiQuaternion { float w, x, y, z; };
class NiAVObject;
class NiNode;
class TESCamera;
class BSIntrusiveRefCounted { public: virtual ~BSIntrusiveRefCounted(); unsigned refCount; };
class TESCameraState : public BSIntrusiveRefCounted { public: TESCamera* camera; unsigned id; };
class PlayerInputHandler { public: virtual ~PlayerInputHandler(); bool inputEventHandlingEnabled; };
class ThirdPersonState : public TESCameraState, public PlayerInputHandler
{
public:
    void GetRotation(NiQuaternion& value) const;
    void GetTranslation(NiPoint3& value) const;
    bool GetFreeRotationMode() const;
    NiAVObject* thirdPersonCameraObj;
    NiNode* thirdPersonFOVControl;
    NiPoint3 translation;
    NiQuaternion rotation;
    NiPoint3 posOffsetExpected;
    NiPoint3 posOffsetActual;
    float targetZoomOffset, currentZoomOffset, targetYaw, currentYaw, savedZoomOffset, pitchZoomOffset, unk8C;
    NiPoint3 collisionPos;
    float collisionPosValid;
    std::uint64_t unkA0;
    const char* animatedBoneName;
    NiQuaternion animationRotation;
    std::uint64_t unkC0, unkC8;
    std::uint32_t unkD0;
    NiPoint2 freeRotation;
    bool freeRotationEnabled, stateNotActive;
    std::uint16_t unkDE;
    bool toggleAnimCam, applyOffsets;
    std::uint16_t unkE2;
    std::uint32_t unkE4;
};
static_assert(offsetof(ThirdPersonState, freeRotationEnabled) == 0xDC, "free rotation flag offset");
static_assert(offsetof(ThirdPersonState, toggleAnimCam) == 0xE0, "animation camera flag offset");
static_assert(sizeof(ThirdPersonState) == 0xE8, "ThirdPersonState size");
struct PlayerControlsData
{
    NiPoint2 moveInputVec, lookInputVec, prevMoveVec, prevLookVec;
    std::uint32_t unk20;
    bool autoMove, running;
    std::uint8_t unk26;
    bool fovSlideMode;
    bool povScriptMode, povBeastMode;
    std::uint8_t unk2A, unk2B;
    bool remapMode;
    std::uint8_t unk2D;
    std::uint16_t unk2E;
};
static_assert(offsetof(PlayerControlsData, fovSlideMode) == 0x27, "field of view slide flag offset");
static_assert(sizeof(PlayerControlsData) == 0x30, "PlayerControlsData size");
template <class T> class BSTEventSink { public: virtual ~BSTEventSink(); };
class InputEvent;
class MenuOpenCloseEvent;
class MenuModeChangeEvent;
class TESFurnitureEvent;
class PlayerControls :
    public BSTEventSink<InputEvent*>,
    public BSTEventSink<MenuOpenCloseEvent>,
    public BSTEventSink<MenuModeChangeEvent>,
    public BSTEventSink<TESFurnitureEvent>
{
public:
    std::uint8_t unknown20;
    PlayerControlsData data;
};
static_assert(offsetof(PlayerControls, data) == 0x24, "controls data offset");
extern PlayerControls* playerControls;
