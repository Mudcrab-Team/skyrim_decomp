// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatBehaviorController; size 0x74
// one of 2 different PDB types sharing this name
#pragma once
#pragma pack(push, 4)
struct CombatBehaviorController_e9533d18 {
    void* defaultThread;
    void* activeThreads;
    void* activeThreads_end;
    void* activeThreads_cap;
    int combatController;
    unsigned char undefined_24[4];
    void* resources;
    unsigned char undefined_30[40];
    void* queued;
    unsigned char undefined_60[16];
    int nextThreadID;
};
#pragma pack(pop)
static_assert(sizeof(CombatBehaviorController_e9533d18) == 116, "CombatBehaviorController_e9533d18 layout differs from the PDB");
