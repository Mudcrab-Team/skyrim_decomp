// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiObjectNET; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString.h"
#include "BSFixedString_char_83b572b4.h"
#include "NiObject.h"
#include "NiPointer_NiTimeController_4d1e262c.h"
struct NiObjectNET_5d8e1bd4 {
    NiObject _base;
    BSFixedString_char_83b572b4 name;
    BSFixedString Name_10;
    NiPointer_NiTimeController_4d1e262c TimeControllers_18;
    unsigned short maxSize;
    unsigned char _pad_0[2];
    unsigned int pad2C;
};
static_assert(sizeof(NiObjectNET_5d8e1bd4) == 48, "NiObjectNET_5d8e1bd4 layout differs from the PDB");
