// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DestructibleObjectData; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "EnumSet_RE__DestructibleObjectData__Flag_unsigned_char_b949229b.h"
#include "NiPointer_RE__QueuedFile_61648701.h"
struct DestructibleObjectStage_9d2a5ba1;
struct DestructibleObjectData_6bff2c12 {
    unsigned int health;
    unsigned char numStages;
    EnumSet_RE__DestructibleObjectData__Flag_unsigned_char_b949229b flags;
    unsigned short pad06;
    DestructibleObjectStage_9d2a5ba1** stages;
    int replacementModelRefCount;
    unsigned int pad14;
    NiPointer_RE__QueuedFile_61648701 preloadedReplacementModels;
};
static_assert(sizeof(DestructibleObjectData_6bff2c12) == 32, "DestructibleObjectData_6bff2c12 layout differs from the PDB");
