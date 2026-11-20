// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkListShape; size 0x30
#pragma once

#include "bhkShapeCollection.h"
struct bhkListShape {
    bhkShapeCollection _base;
    unsigned long long unk28;
};
static_assert(sizeof(bhkListShape) == 48, "bhkListShape layout differs from the PDB");
