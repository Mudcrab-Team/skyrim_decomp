// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FirstPersonState; size 0x90
#pragma once

#include "NiPoint3.h"
#include "PlayerInputHandler.h"
#include "TESCameraState.h"
struct NiAVObject;
struct NiNode;
struct FirstPersonState {
    TESCameraState _base;
    PlayerInputHandler _base_PlayerInputHandler;
    NiPoint3 lastPosition;
    NiPoint3 lastFrameSpringVelocity;
    NiPoint3 dampeningOffset;
    unsigned int pad54;
    NiAVObject* firstPersonCameraObj;
    NiNode* firstPersonFOVControl;
    float sittingRotation;
    float unk6C;
    float unk70;
    float currentPitchOffset;
    float targetPitchOffset;
    float unk7C;
    unsigned int unk80;
    bool cameraOverride;
    bool cameraPitchOverride;
    unsigned short unk86;
    unsigned long long unk88;
};
static_assert(sizeof(FirstPersonState) == 144, "FirstPersonState layout differs from the PDB");
