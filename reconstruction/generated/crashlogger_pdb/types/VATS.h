// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: VATS; size 0xc0
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTSmartPointer_RE__VATSCommand_4309a674.h"
#include "BSTSingletonSDM_RE__VATS_a542426a.h"
#include "NiPointer_RE__Actor_71eb6ba3.h"
#include "NiPointer_RE__BSLight_c51dfae1.h"
#include "VATS_MODE.h"
struct BGSCameraShot;
struct ExtraDataList;
struct ImageSpaceModifierInstanceRB;
struct Projectile;
struct TESBoundObject_fc790793;
struct VATSCameraShotQueueNode;
struct VATS {
    BSTSingletonSDM_RE__VATS_a542426a _base;
    unsigned char undefined_1[3];
    unsigned int pad00;
    BSTArray_RE__BSTSmartPointer_RE__VATSCommand_4309a674 commandList;
    VATS_MODE mode;
    unsigned int pad24;
    VATSCameraShotQueueNode* cameraShotQueue;
    BGSCameraShot* cameraShot;
    float safetyTime;
    float cameraTime;
    float castingAfterKillDelay;
    unsigned int pad44;
    Projectile* killProjectile;
    Projectile* killProjectile2;
    unsigned long long unk58;
    ImageSpaceModifierInstanceRB* unk60;
    ImageSpaceModifierInstanceRB* unk68;
    NiPointer_RE__BSLight_c51dfae1 VATSLight;
    bool killCamActive;
    bool killCamInitialized;
    unsigned short pad7A;
    int pendingCameraTransition;
    float magicTimeSlowdown;
    float playerMagicTimeSlowdown;
    TESBoundObject_fc790793* item;
    ExtraDataList* extraList;
    NiPointer_RE__Actor_71eb6ba3 target;
    int unkA0;
    unsigned int padA4;
    NiPointer_RE__Actor_71eb6ba3 attacker;
    NiPointer_RE__Actor_71eb6ba3 stranger;
    BSSpinLock lock;
};
static_assert(sizeof(VATS) == 192, "VATS layout differs from the PDB");
