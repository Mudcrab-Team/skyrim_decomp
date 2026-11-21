// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESCamera; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTPoint2_float_af46c5cb.h"
#include "BSTPoint3_float_ba0b407f.h"
#include "BSTSmartPointer_RE__TESCameraState_b4a49671.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
struct TESCamera_vtbl;
struct TESCamera {
    TESCamera_vtbl* __vftable;
    BSTPoint2_float_af46c5cb rotationInput;
    BSTPoint3_float_ba0b407f translationInput;
    float zoomInput;
    NiPointer_RE__NiNode_28171d5b cameraRoot;
    BSTSmartPointer_RE__TESCameraState_b4a49671 currentState;
    bool enabled;
    unsigned char pad31;
    unsigned short pad32;
    unsigned int pad34;
};
static_assert(sizeof(TESCamera) == 56, "TESCamera layout differs from the PDB");
