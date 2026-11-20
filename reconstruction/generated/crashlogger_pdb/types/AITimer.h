// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AITimer; size 0x8
#pragma once
struct AITimer {
    float aiTimer;
    float timer;
};
static_assert(sizeof(AITimer) == 8, "AITimer layout differs from the PDB");
