// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GASStringBuiltinManager; size 0x4f0
#pragma once

struct GASStringManager;
struct GASStringBuiltinManager {
    unsigned long long unk000[157];
    GASStringManager* stringManager;
};
static_assert(sizeof(GASStringBuiltinManager) == 1264, "GASStringBuiltinManager layout differs from the PDB");
