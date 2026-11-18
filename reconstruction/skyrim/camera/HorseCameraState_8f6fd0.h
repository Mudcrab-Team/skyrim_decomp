// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/H/HorseCameraState.h, include/RE/T/ThirdPersonState.h, include/RE/T/TESCameraState.h, include/RE/P/PlayerInputHandler.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); target callees and signatures are inferred independently from the target call sequence.
#pragma once
struct NiPoint3 { float x,y,z; }; struct NiPoint2 { float x,y; }; struct NiQuaternion { float w,x,y,z; }; class TESCamera; class NiAVObject; class NiNode; class BGSLoadFormBuffer;
class BSIntrusiveRefCounted { public: virtual ~BSIntrusiveRefCounted(); unsigned refCount; }; class TESCameraState : public BSIntrusiveRefCounted { public: TESCamera* camera; unsigned id; }; class PlayerInputHandler { public: virtual ~PlayerInputHandler(); bool inputEventHandlingEnabled; };
class ThirdPersonState : public TESCameraState, public PlayerInputHandler { public:
 void End(); void Revert(BGSLoadFormBuffer*);
 NiAVObject* thirdPersonCameraObj; NiNode* thirdPersonFOVControl; NiPoint3 translation; NiQuaternion rotation; NiPoint3 posOffsetExpected, posOffsetActual; float targetZoomOffset,currentZoomOffset,targetYaw,currentYaw,savedZoomOffset,pitchZoomOffset,unk8C; NiPoint3 collisionPos; float collisionPosValid; unsigned long long unkA0; const char* animatedBoneName; NiQuaternion animationRotation; unsigned long long unkC0,unkC8; unsigned unkD0; NiPoint2 freeRotation; bool freeRotationEnabled,stateNotActive; unsigned short unkDE; bool toggleAnimCam,applyOffsets; unsigned short unkE2; unsigned unkE4;
};
extern unsigned nullHandle;
class HorseCameraState : public ThirdPersonState { public: unsigned horseRefHandle; float horseCurrentDirection; bool atMaxHorseAngle; void End(); void Revert(BGSLoadFormBuffer*); };
