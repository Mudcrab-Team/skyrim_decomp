// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatBehaviorStack; size 0x10
#pragma once
struct CombatBehaviorStack {
    unsigned char* buffer;
    unsigned int bufferSize;
    unsigned int size;
};
static_assert(sizeof(CombatBehaviorStack) == 16, "CombatBehaviorStack layout differs from the PDB");
