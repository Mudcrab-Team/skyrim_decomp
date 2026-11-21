// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSWaterCollisionManager::BGSWaterUpdateI; size 0x48
#pragma once

#include "BGSWaterCollisionManager__BGSWaterUpdateI__Flag.h"
struct BGSWaterCollisionManager__BGSWaterUpdateI__VFTable;
struct TESWaterForm;
struct bhkRigidBody_b921d773;
struct BGSWaterCollisionManager__BGSWaterUpdateI {
    BGSWaterCollisionManager__BGSWaterUpdateI__VFTable* vftable;
    BGSWaterCollisionManager__BGSWaterUpdateI__Flag flags;
    unsigned int pad0C;
    char32_t* trackedBodies_data;
    unsigned int trackedBodies_capacity;
    unsigned int trackedBodies_pad14;
    unsigned int trackedBodies_size;
    unsigned int trackedBodies_pad1C;
    char32_t* next;
    TESWaterForm* waterType;
    char32_t* context;
    bhkRigidBody_b921d773* body;
};
static_assert(sizeof(BGSWaterCollisionManager__BGSWaterUpdateI) == 72, "BGSWaterCollisionManager__BGSWaterUpdateI layout differs from the PDB");
