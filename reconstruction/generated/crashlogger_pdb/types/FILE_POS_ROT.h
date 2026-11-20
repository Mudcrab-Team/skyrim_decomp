// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FILE_POS_ROT; size 0x18
#pragma once

#include "NiPoint3.h"
struct FILE_POS_ROT {
    NiPoint3 pos;
    NiPoint3 rot;
};
static_assert(sizeof(FILE_POS_ROT) == 24, "FILE_POS_ROT layout differs from the PDB");
