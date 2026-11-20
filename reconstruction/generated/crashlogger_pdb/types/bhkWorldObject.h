// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkWorldObject; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct bhkWorldObject__VFTable;
struct hkBaseObject_67f706b6;
struct bhkWorldObject {
    bhkWorldObject__VFTable* vftable_bhkWorldObject_0;
    char _pad_8[8];
    hkBaseObject_67f706b6* HavokObject_10;
    char _pad_18[16];
};
static_assert(sizeof(bhkWorldObject) == 40, "bhkWorldObject layout differs from the PDB");
