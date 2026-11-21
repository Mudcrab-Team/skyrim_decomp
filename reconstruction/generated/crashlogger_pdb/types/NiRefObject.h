// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiRefObject; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct NiRefObject__VFTable;
struct NiRefObject {
    NiRefObject__VFTable* _vtable;
    unsigned int _refCount;
    unsigned int _pad0C;
};
static_assert(sizeof(NiRefObject) == 16, "NiRefObject layout differs from the PDB");
