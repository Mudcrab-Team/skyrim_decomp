// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCollisionFilter; size 0x7e0
#pragma once

#include "hkpCollisionFilter.h"
struct bhkCollisionFilter {
    hkpCollisionFilter _base;
    unsigned int unk48;
    unsigned int nextSystemGroup;
    unsigned int bipedBitfields[32];
    unsigned int layerCollisionGroups[64];
    unsigned long long layerBitfields[64];
    unsigned long long triggerField;
    unsigned long long sensorField;
    unsigned char collisionLayerNames_raw[512];
    unsigned char unk5E0[256];
    unsigned char collisionBoneNames_raw[256];
};
static_assert(sizeof(bhkCollisionFilter) == 2016, "bhkCollisionFilter layout differs from the PDB");
