// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkSerializable; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct bhkSerializable__VFTable;
struct hkBaseObject_67f706b6;
struct bhkSerializable {
    bhkSerializable__VFTable* vftable_bhkSerializable_0;
    char _pad_8[8];
    hkBaseObject_67f706b6* HavokObject_10;
    char _pad_18[8];
};
static_assert(sizeof(bhkSerializable) == 32, "bhkSerializable layout differs from the PDB");
