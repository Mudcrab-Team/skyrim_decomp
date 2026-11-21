// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CachedValues; size 0x60
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_CachedValueData_BSTArrayHeapAllocator.h"
#include "CachedValues__BooleanValue.h"
#include "CachedValues__Flags.h"
struct CachedValues_ebedb0c3 {
    float CachedRadius_0;
    float CachedWidth_4;
    float CachedLength_8;
    float CachedForwardLength_C;
    float CachedDPS_10;
    float CachedEyeLevel_14;
    float CachedWalkSpeed_18;
    float CachedRunSpeed_1C;
    float CachedJogSpeed_20;
    float CachedFastWalkSpeed_24;
    CachedValues__BooleanValue booleanValues;
    CachedValues__Flags flags;
    BSTArray_CachedValueData_BSTArrayHeapAllocator ActorValueCache_30;
    BSTArray_CachedValueData_BSTArrayHeapAllocator PermanentActorValueCache_48;
};
static_assert(sizeof(CachedValues_ebedb0c3) == 96, "CachedValues_ebedb0c3 layout differs from the PDB");
