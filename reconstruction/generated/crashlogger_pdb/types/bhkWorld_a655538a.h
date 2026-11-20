// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkWorld; size 0xc600
// one of 2 different PDB types sharing this name
#pragma once

#include "BSReadWriteLock.h"
#include "BSTArray_void_9eb8914c.h"
#include "bhkSerializable_cf25f762.h"
#include "hkVector4.h"
struct BGSAcousticSpaceListener;
struct bhkConstraintProjector;
struct hkpSuspendInactiveAgentsUtil;
struct bhkWorld_a655538a {
    bhkSerializable_cf25f762 _base;
    unsigned char unk0020[800];
    unsigned char unk0340[25600];
    unsigned char unk6740[24000];
    BSTArray_void_9eb8914c unkC500;
    BSTArray_void_9eb8914c unkC518;
    BSTArray_void_9eb8914c unkC530;
    BSTArray_void_9eb8914c unkC548;
    unsigned long long unkC560;
    unsigned int unkC568;
    float unkC56C;
    bhkConstraintProjector* constraintProjector;
    unsigned long long unkC578;
    unsigned int unkC580;
    float unkC584;
    unsigned long long unkC588;
    unsigned long long unkC590;
    BSReadWriteLock worldLock;
    BSReadWriteLock unkC5A0;
    unsigned long long unkC5A8;
    hkVector4 unkC5B0;
    unsigned long long unkC5C0;
    BGSAcousticSpaceListener* acousticSpaceListener;
    hkpSuspendInactiveAgentsUtil* suspendInactiveAgentsUtil;
    unsigned int unkC5D8;
    unsigned int unkC5DC;
    unsigned int unkC5E0;
    unsigned int unkC5E4;
    unsigned int unkC5E8;
    unsigned int unkC5EC;
    float tau;
    float damping;
    unsigned char unkC5F8;
    bool toggleCollision;
    unsigned short unkC5FA;
    unsigned short unkC5FC;
    unsigned short unkC5FE;
};
static_assert(sizeof(bhkWorld_a655538a) == 50688, "bhkWorld_a655538a layout differs from the PDB");
