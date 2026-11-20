// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FORM; size 0x18
// one of 2 different PDB types sharing this name
#pragma once
struct FORM_bc455ae9 {
    unsigned int form_00;
    unsigned int length_04;
    unsigned int flags_08;
    unsigned int formID_0c;
    unsigned int versionControl_10;
    unsigned short formVersion_14;
    unsigned short vcVersion_16;
};
static_assert(sizeof(FORM_bc455ae9) == 24, "FORM_bc455ae9 layout differs from the PDB");
