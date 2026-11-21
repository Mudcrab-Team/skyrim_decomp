// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Data; size 0x100
// one of 13 different PDB types sharing this name; the fullest
#pragma once
struct Data {
    unsigned char local[256];
};
static_assert(sizeof(Data) == 256, "Data layout differs from the PDB");
