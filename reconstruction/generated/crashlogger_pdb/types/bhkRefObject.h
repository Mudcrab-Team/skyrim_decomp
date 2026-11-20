// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkRefObject; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct bhkRefObject__VFTable;
struct hkBaseObject_67f706b6;
struct bhkRefObject {
    bhkRefObject__VFTable* vftable_bhkRefObject_0;
    char _pad_8[8];
    hkBaseObject_67f706b6* HavokObject_10;
};
static_assert(sizeof(bhkRefObject) == 24, "bhkRefObject layout differs from the PDB");
