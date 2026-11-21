// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFileContainer; size 0x8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct TESFileArray_72802340;
struct TESFileContainer {
    TESFileArray_72802340* array;
};
static_assert(sizeof(TESFileContainer) == 8, "TESFileContainer layout differs from the PDB");
