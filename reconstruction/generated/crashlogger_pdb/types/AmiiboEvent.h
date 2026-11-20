// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AmiiboEvent; size 0x40
#pragma once

#include "IDEvent.h"
#pragma pack(push, 4)
struct AmiiboEvent {
    IDEvent _base;
    unsigned int unk28;
    unsigned long long unk2C;
    unsigned short unk34;
    unsigned short unk36;
    unsigned int unk38;
    unsigned int unk3C;
};
#pragma pack(pop)
static_assert(sizeof(AmiiboEvent) == 64, "AmiiboEvent layout differs from the PDB");
