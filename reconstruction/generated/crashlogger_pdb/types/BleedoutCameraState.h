// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BleedoutCameraState; size 0x138
#pragma once

#include "BSSoundHandle.h"
#include "NiMatrix3.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "ThirdPersonState.h"
struct BleedoutCameraState {
    ThirdPersonState _base;
    NiMatrix3 rotationMtx;
    float zoom;
    float pitch;
    float yaw;
    float randHeading;
    unsigned int pad11C;
    NiPointer_RE__NiAVObject_9e3aa701 animatedBone;
    BSSoundHandle activeSound;
    bool useCurrentHeading;
    unsigned char pad135;
    unsigned short pad136;
};
static_assert(sizeof(BleedoutCameraState) == 312, "BleedoutCameraState layout differs from the PDB");
