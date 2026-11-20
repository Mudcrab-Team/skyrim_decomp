// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IDTag; size 0x28
#pragma once

#include "BSFixedString_char_83b572b4.h"
struct IDTag {
    BSFixedString_char_83b572b4 avObjectName;
    BSFixedString_char_83b572b4 propertyType;
    BSFixedString_char_83b572b4 ctlrType;
    BSFixedString_char_83b572b4 ctlrID;
    BSFixedString_char_83b572b4 interpolatorID;
};
static_assert(sizeof(IDTag) == 40, "IDTag layout differs from the PDB");
