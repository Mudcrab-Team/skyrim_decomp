// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpProcessCollisionInput; size 0xa0
// one of 2 different PDB types sharing this name
#pragma once

#include "hkStepInfo.h"
#include "hkpCollisionInput_5c03ac90.h"
struct hkpAgent1nSector;
struct hkpCollisionQualityInfo;
struct hkpProcessCollisionInput_c2f94de3 {
    hkpCollisionInput_5c03ac90 _base;
    hkStepInfo stepInfo;
    hkpCollisionQualityInfo* collisionQualityInfo;
    hkpAgent1nSector* spareAgentSector;
    void* dynamicsInfo;
    bool enableDeprecatedWelding;
    bool allowToSkipConfirmedCallbacks;
    unsigned short pad8A;
    unsigned int pad8C;
    unsigned char config_raw[16];
};
static_assert(sizeof(hkpProcessCollisionInput_c2f94de3) == 160, "hkpProcessCollisionInput_c2f94de3 layout differs from the PDB");
