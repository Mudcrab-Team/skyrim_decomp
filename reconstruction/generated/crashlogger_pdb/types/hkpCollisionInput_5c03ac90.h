// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollisionInput; size 0x60
// one of 2 different PDB types sharing this name
#pragma once

#include "Aabb32Info.h"
struct hkpCollisionDispatcher_f542eee0;
struct hkpCollisionFilter;
struct hkpConvexListFilter_8ec0d7aa;
struct hkpCollisionInput_5c03ac90 {
    hkpCollisionDispatcher_f542eee0* dispatcher;
    int weldClosestPoints;
    int forceAcceptContactPoints;
    float tolerance;
    unsigned int pad14;
    hkpCollisionFilter* filter;
    hkpConvexListFilter_8ec0d7aa* convexListFilter;
    int createPredictiveAgents;
    unsigned int pad2C;
    Aabb32Info aabb32Info;
};
static_assert(sizeof(hkpCollisionInput_5c03ac90) == 96, "hkpCollisionInput_5c03ac90 layout differs from the PDB");
