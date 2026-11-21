// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PlayerCamera; size 0x188
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSSpinLock.h"
#include "BSTArray_RE__TESCameraState_RE__BSTSmallArrayHeapAllocator_112_a1e6fad3.h"
#include "BSTSingletonSDM_RE__PlayerCamera_e31379cc.h"
#include "NiPoint3_a7124070.h"
#include "NiPointer_RE__bhkRigidBody_db9ab486.h"
#include "TESCamera_ba12c162.h"
struct Unk120_6d4e3af9;
struct PlayerCamera {
    TESCamera_ba12c162 _base;
    BSTSingletonSDM_RE__PlayerCamera_e31379cc _base_BSTSingletonSDM_RE_PlayerCamera_;
    unsigned char pad039;
    unsigned short pad03A;
    BSPointerHandle_RE__Actor_1a35f4b9 cameraTarget;
    BSTArray_RE__TESCameraState_RE__BSTSmallArrayHeapAllocator_112_a1e6fad3 tempReturnStates;
    unsigned char cameraStates_raw[112];
    Unk120_6d4e3af9* unk120;
    NiPointer_RE__bhkRigidBody_db9ab486 rigidBody;
    unsigned int objectFadeHandle;
    unsigned int unk144;
    bool unk148;
    unsigned char pad149[3];
    BSSpinLock lock;
    unsigned int unk154;
    float worldFOV;
    float firstPersonFOV;
    NiPoint3_a7124070 pos;
    float idleTimer;
    float yaw;
    unsigned int unk158;
    unsigned int unk15C;
    bool allowAutoVanityMode;
    bool bowZoomedIn;
    bool isWeapSheathed;
    bool isProcessed;
    unsigned char unk164;
    unsigned char unk165;
    unsigned short pad166;
    unsigned char undefined_184[4];
};
static_assert(sizeof(PlayerCamera) == 392, "PlayerCamera layout differs from the PDB");
