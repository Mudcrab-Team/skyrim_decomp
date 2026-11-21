// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraSoul; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct ExtraSoul {
    BSExtraData_4ca6af76 _base;
    unsigned char soul;  // SOUL_LEVEL in the PDB is wider than this slot
    unsigned char pad11;
    unsigned short pad12;
    unsigned int pad14;
};
static_assert(sizeof(ExtraSoul) == 24, "ExtraSoul layout differs from the PDB");
