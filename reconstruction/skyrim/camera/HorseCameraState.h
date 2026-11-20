// Source exposure: mixed
// Code origin: HorseCameraState::End was adapted from the anonymous fo4-private sibling as labelled (author permission); ~HorseCameraState and SetCameraHandle were written from the pinned image listing by Taylor Turner with Claude Sonnet 5.5 (first drafts by DeepSeek V4.1 Flash) with no adapted body; declarations from the pinned community headers.
// HorseCameraState, ThirdPersonState, TESCameraState, PlayerInputHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations adapted from include/RE/H/HorseCameraState.h, include/RE/T/ThirdPersonState.h, include/RE/T/TESCameraState.h, include/RE/P/PlayerInputHandler.h.
// HorseCameraState::~HorseCameraState, HorseCameraState::SetCameraHandle, ThirdPersonState::~ThirdPersonState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); target callees and signatures are inferred independently from the target call sequence.
#pragma once
struct NiPoint3 { float x,y,z; }; struct NiPoint2 { float x,y; }; struct NiQuaternion { float w,x,y,z; }; class TESCamera; class NiAVObject; class NiNode; class BGSLoadFormBuffer;
class BSIntrusiveRefCounted { public: virtual ~BSIntrusiveRefCounted(); unsigned refCount; }; class TESCameraState : public BSIntrusiveRefCounted { public: TESCamera* camera; unsigned id; }; class PlayerInputHandler { public: virtual ~PlayerInputHandler(); bool inputEventHandlingEnabled; };
class ThirdPersonState : public TESCameraState, public PlayerInputHandler { public:
 virtual ~ThirdPersonState();  // declared, not defined: the base teardown is an out-of-line call in the target
 void End(); void Revert(BGSLoadFormBuffer*);
 NiAVObject* thirdPersonCameraObj; NiNode* thirdPersonFOVControl; NiPoint3 translation; NiQuaternion rotation; NiPoint3 posOffsetExpected, posOffsetActual; float targetZoomOffset,currentZoomOffset,targetYaw,currentYaw,savedZoomOffset,pitchZoomOffset,unk8C; NiPoint3 collisionPos; float collisionPosValid; unsigned long long unkA0; const char* animatedBoneName; NiQuaternion animationRotation; unsigned long long unkC0,unkC8; unsigned unkD0; NiPoint2 freeRotation; bool freeRotationEnabled,stateNotActive; unsigned short unkDE; bool toggleAnimCam,applyOffsets; unsigned short unkE2; unsigned unkE4;
};
extern unsigned nullHandle;
class HorseCameraState : public ThirdPersonState { public: ~HorseCameraState(); unsigned horseRefHandle; float horseCurrentDirection; bool atMaxHorseAngle; void SetCameraHandle(unsigned& a_handle); void End(); void Revert(BGSLoadFormBuffer*); };
static_assert(sizeof(HorseCameraState) == 0xF8, "HorseCameraState size");
