// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FORM_ENUM_STRING; size 0x18
#pragma once
struct FORM_ENUM_STRING {
    unsigned char formType_raw[8];
    unsigned char* formString;
    unsigned int formCode;
    unsigned char undefined_14[4];
};
static_assert(sizeof(FORM_ENUM_STRING) == 24, "FORM_ENUM_STRING layout differs from the PDB");
