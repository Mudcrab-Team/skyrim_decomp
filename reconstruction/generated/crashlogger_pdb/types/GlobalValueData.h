// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GlobalValueData; size 0x10
#pragma once

struct TESGlobal;
struct GlobalValueData {
    TESGlobal* global;
    float value;
    unsigned int pad0C;
};
static_assert(sizeof(GlobalValueData) == 16, "GlobalValueData layout differs from the PDB");
