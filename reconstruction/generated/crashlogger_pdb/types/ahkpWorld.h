// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ahkpWorld; size 0x440
#pragma once

#include "hkpWorld_938ebb10.h"
struct bhkWorld;
struct ahkpWorld {
    hkpWorld_938ebb10 _base;
    bhkWorld* userData;
    unsigned long long unk438;
};
static_assert(sizeof(ahkpWorld) == 1088, "ahkpWorld layout differs from the PDB");
