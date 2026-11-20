// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkEntity; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct bhkEntity__VFTable;
struct hkBaseObject_67f706b6;
struct bhkEntity {
    bhkEntity__VFTable* vftable_bhkEntity_0;
    char _pad_8[8];
    hkBaseObject_67f706b6* HavokObject_10;
    char _pad_18[16];
};
static_assert(sizeof(bhkEntity) == 40, "bhkEntity layout differs from the PDB");
