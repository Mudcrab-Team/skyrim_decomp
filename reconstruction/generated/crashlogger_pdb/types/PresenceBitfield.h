// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PresenceBitfield; size 0x18
#pragma once
struct PresenceBitfield {
    unsigned char bits[24];
};
static_assert(sizeof(PresenceBitfield) == 24, "PresenceBitfield layout differs from the PDB");
