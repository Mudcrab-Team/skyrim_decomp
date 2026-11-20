// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ThirdPersonState; size 0xe8
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "NiPoint2_6bdffc9f.h"
#include "NiPoint3.h"
#include "NiQuaternion.h"
#include "PlayerInputHandler.h"
#include "TESCameraState.h"
struct NiAVObject;
struct NiNode;
struct ThirdPersonState {
    TESCameraState _base;
    PlayerInputHandler _base_PlayerInputHandler;
    NiAVObject* thirdPersonCameraObj;
    NiNode* thirdPersonFOVControl;
    NiPoint3 translation;
    NiQuaternion rotation;
    NiPoint3 posOffsetExpected;
    NiPoint3 posOffsetActual;
    float targetZoomOffset;
    float currentZoomOffset;
    float targetYaw;
    float currentYaw;
    float savedZoomOffset;
    float pitchZoomOffset;
    float unk8C;
    NiPoint3 collisionPos;
    float collisionPosValid;
    unsigned long long unkA0;
    BSFixedString_char_83b572b4 animatedBoneName;
    NiQuaternion animationRotation;
    unsigned long long unkC0;
    unsigned long long unkC8;
    unsigned int unkD0;
    NiPoint2_6bdffc9f freeRotation;
    bool freeRotationEnabled;
    bool stateNotActive;
    unsigned short unkDC;
    bool toggleAnimCam;
    bool applyOffsets;
    unsigned short unkE2;
    unsigned int unkE4;
};
static_assert(sizeof(ThirdPersonState) == 232, "ThirdPersonState layout differs from the PDB");
