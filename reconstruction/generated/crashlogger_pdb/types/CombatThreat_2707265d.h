// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatThreat; size 0x68
// one of 2 different PDB types sharing this name
#pragma once

#include "CombatObject_2faf992b.h"
#include "NiPoint3.h"
struct NiNode;
struct bhkRigidBody;
struct CombatThreat_2707265d {
    CombatObject_2faf992b _base;
    unsigned int formid;
    unsigned int handle;
    NiPoint3 pos;
    NiPoint3 angle;
    float rad;
    float damage;
    float range;
    float cone;
    float explosion_time;
    unsigned int shooter;
    NiNode* root;
    bhkRigidBody* body;
    NiPoint3 velocity;
    float cacheVelocity;
};
static_assert(sizeof(CombatThreat_2707265d) == 104, "CombatThreat_2707265d layout differs from the PDB");
