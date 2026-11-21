// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiBinaryExtraData; size 0x28
#pragma once

#include "BSFixedString_char_83b572b4.h"
struct NiBinaryExtraData {
    char32_t* vftable_NiBinaryExtraData_0;
    unsigned char _pad_8;
    unsigned char undefined_9[7];
    BSFixedString_char_83b572b4 Name_10;
    unsigned char* data;
    unsigned int size;
    unsigned char undefined_24[4];
};
static_assert(sizeof(NiBinaryExtraData) == 40, "NiBinaryExtraData layout differs from the PDB");
