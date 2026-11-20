// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiObjectNET; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "NiObject_de5bc370.h"
#include "NiPointer_RE__NiTimeController_8219d923.h"
struct NiExtraData_b2385dce;
struct NiObjectNET {
    NiObject_de5bc370 _base;
    BSFixedString_char_83b572b4 name;
    NiPointer_RE__NiTimeController_8219d923 controllers;
    NiExtraData_b2385dce** extra;
    unsigned short extraDataSize;
    unsigned short maxSize;
    unsigned int pad2C;
};
static_assert(sizeof(NiObjectNET) == 48, "NiObjectNET layout differs from the PDB");
