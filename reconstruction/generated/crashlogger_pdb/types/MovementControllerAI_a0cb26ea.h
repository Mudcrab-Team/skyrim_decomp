// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MovementControllerAI; size 0x120
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__MovementControllerAI__ActiveSmartPtr_RE__MovementAgent_RE__BSTSmallArrayHe_f9afa75c.h"
#include "BSTArray_RE__MovementControllerAI__ActiveSmartPtr_RE__MovementArbiter_RE__BSTSmallArray_d5ae695b.h"
#include "IMovementControllerRegisterInterface_a55b6476.h"
struct MovementControllerAI_a0cb26ea {
    IMovementControllerRegisterInterface_a55b6476 _base;
    unsigned int _refCount;
    unsigned int pad00C;
    BSTArray_RE__MovementControllerAI__ActiveSmartPtr_RE__MovementArbiter_RE__BSTSmallArray_d5ae695b arbiters;
    BSTArray_RE__MovementControllerAI__ActiveSmartPtr_RE__MovementAgent_RE__BSTSmallArrayHe_f9afa75c agents;
    unsigned long long unk048;
    unsigned long long unk050;
    unsigned long long unk058;
    unsigned long long unk060;
    unsigned long long unk068;
    unsigned long long unk070;
    unsigned long long unk078;
    unsigned long long unk080;
    unsigned long long unk088;
    unsigned long long unk090;
    unsigned long long unk098;
    unsigned long long unk0A0;
    unsigned long long unk0A8;
    unsigned long long unk0B0;
    unsigned long long unk0B8;
    unsigned long long unk0C0;
    unsigned long long unk0C8;
    unsigned long long unk0D0;
    unsigned long long unk0D8;
    unsigned long long unk0E0;
    unsigned long long unk0E8;
    unsigned long long unk0F0;
    unsigned long long unk0F8;
    unsigned long long unk100;
    unsigned long long unk108;
    unsigned long long unk110;
    unsigned long long unk118;
};
static_assert(sizeof(MovementControllerAI_a0cb26ea) == 288, "MovementControllerAI_a0cb26ea layout differs from the PDB");
