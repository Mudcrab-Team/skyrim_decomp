// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkVector4; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct hkVector4 {
    unsigned char quad[16];
};
static_assert(sizeof(hkVector4) == 16, "hkVector4 layout differs from the PDB");
