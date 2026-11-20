// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DestructibleObjectData; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiPointer_RE__QueuedFile_61648701.h"
struct DestructibleObjectStage;
struct DestructibleObjectData {
    unsigned int health;
    unsigned char numStages;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned short pad06;
    DestructibleObjectStage** stages;
    int replacementModelRefCount;
    unsigned int pad14;
    NiPointer_RE__QueuedFile_61648701 preloadedReplacementModels;
};
static_assert(sizeof(DestructibleObjectData) == 32, "DestructibleObjectData layout differs from the PDB");
