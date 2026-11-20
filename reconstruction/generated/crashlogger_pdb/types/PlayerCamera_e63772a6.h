// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PlayerCamera; size 0x168
// one of 2 different PDB types sharing this name
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSSpinLock.h"
#include "BSTArray_RE__TESCameraState_RE__BSTSmallArrayHeapAllocator_104_e7d2513b.h"
#include "BSTSingletonSDM_RE__PlayerCamera_e31379cc.h"
#include "NiPoint3.h"
#include "NiPointer_RE__bhkRigidBody_db9ab486.h"
#include "TESCamera.h"
struct Unk120;
struct PlayerCamera_e63772a6 {
    TESCamera _base;
    BSTSingletonSDM_RE__PlayerCamera_e31379cc _base_BSTSingletonSDM_RE_PlayerCamera_;
    unsigned char pad039;
    unsigned short pad03A;
    BSPointerHandle_RE__Actor_1a35f4b9 cameraTarget;
    BSTArray_RE__TESCameraState_RE__BSTSmallArrayHeapAllocator_104_e7d2513b tempReturnStates;
    unsigned char cameraStates_raw[104];
    Unk120* unk120;
    NiPointer_RE__bhkRigidBody_db9ab486 rigidBody;
    unsigned int objectFadeHandle;
    BSSpinLock lock;
    float worldFOV;
    float firstPersonFOV;
    NiPoint3 pos;
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
};
static_assert(sizeof(PlayerCamera_e63772a6) == 360, "PlayerCamera_e63772a6 layout differs from the PDB");
