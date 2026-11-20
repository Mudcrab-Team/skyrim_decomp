// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkMemorySystem; size 0x8
#pragma once

struct hkMemorySystem_vtbl;
struct hkMemorySystem {
    hkMemorySystem_vtbl* __vftable;
};
static_assert(sizeof(hkMemorySystem) == 8, "hkMemorySystem layout differs from the PDB");
