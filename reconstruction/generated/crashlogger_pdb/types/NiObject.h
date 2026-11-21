// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiObject; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct NiObject__VFTable;
struct NiObject {
    NiObject__VFTable* vftable_NiObject_0;
    char _pad_8[8];
};
static_assert(sizeof(NiObject) == 16, "NiObject layout differs from the PDB");
