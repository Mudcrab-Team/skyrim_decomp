// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShape; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "hkReferencedObject.h"
#include "hkpShapeType.h"
struct bhkShape_a9c42bb4;
struct hkpShape_890c4847 {
    hkReferencedObject _base;
    bhkShape_a9c42bb4* userData;
    hkpShapeType type;
    unsigned int pad1C;
};
static_assert(sizeof(hkpShape_890c4847) == 32, "hkpShape_890c4847 layout differs from the PDB");
