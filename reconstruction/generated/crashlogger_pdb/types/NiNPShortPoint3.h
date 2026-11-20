// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiNPShortPoint3; size 0x6
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct NiNPShortPoint3 {
    short x;
    short y;
    short z;
};
static_assert(sizeof(NiNPShortPoint3) == 6, "NiNPShortPoint3 layout differs from the PDB");
