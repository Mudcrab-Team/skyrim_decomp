// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiRefObject; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

struct NiRefObject_vtbl;
struct NiRefObject_f24a9221 {
    NiRefObject_vtbl* __vftable;
    unsigned int _refCount;
    unsigned int _pad0C;
};
static_assert(sizeof(NiRefObject_f24a9221) == 16, "NiRefObject_f24a9221 layout differs from the PDB");
