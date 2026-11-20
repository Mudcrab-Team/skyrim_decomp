// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FORM; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct FORM {
    unsigned int form;
    unsigned int length;
    unsigned int flags;
    unsigned int formID;
    unsigned int versionControl;
    unsigned short formVersion;
    unsigned short vcVersion;
};
static_assert(sizeof(FORM) == 24, "FORM layout differs from the PDB");
