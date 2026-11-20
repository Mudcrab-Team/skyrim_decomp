// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BooleanValue
#pragma once
enum class BooleanValue : int {
    kNone = 0,
    kConditionPreventsRun = 1,
    kOwnerIsNPC = 2,
    kOwnerIsUndead = 4,
    kOwnerIsInCombatantFaction = 8,
};
