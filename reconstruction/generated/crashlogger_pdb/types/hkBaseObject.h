// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkBaseObject; size 0x8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkBaseObject_vtbl;
struct hkBaseObject {
    hkBaseObject_vtbl* __vftable;
};
static_assert(sizeof(hkBaseObject) == 8, "hkBaseObject layout differs from the PDB");
