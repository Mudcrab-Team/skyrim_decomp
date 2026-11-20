// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkWorld; size 0xc600
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct bhkWorld__VFTable;
struct hkBaseObject_67f706b6;
struct bhkWorld {
    bhkWorld__VFTable* vftable_bhkWorld_0;
    char _pad_8[8];
    hkBaseObject_67f706b6* HavokObject_10;
    unsigned char unk0020[800];
    unsigned char undefined_338[49864];
};
static_assert(sizeof(bhkWorld) == 50688, "bhkWorld layout differs from the PDB");
