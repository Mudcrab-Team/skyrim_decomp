// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ACTOR_LIFE_STATE
#pragma once
enum class ACTOR_LIFE_STATE : int {
    kAlive = 0,
    kDying = 1,
    kDead = 2,
    kUnconcious = 3,
    kReanimate = 4,
    kRecycle = 5,
    kRestrained = 6,
    kEssentialDown = 7,
    kBleedout = 8,
};
