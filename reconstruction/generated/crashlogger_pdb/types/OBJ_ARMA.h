// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: OBJ_ARMA; size 0xc
#pragma once
struct OBJ_ARMA {
    unsigned char priorities[2];
    unsigned char modelRange[2];
    unsigned char unused[2];
    unsigned char detectionSoundValue;
    unsigned char pad07;
    float weaponAdjust;
};
static_assert(sizeof(OBJ_ARMA) == 12, "OBJ_ARMA layout differs from the PDB");
