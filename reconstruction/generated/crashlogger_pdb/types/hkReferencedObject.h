// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkReferencedObject; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkBaseObject.h"
struct hkReferencedObject {
    hkBaseObject _base;
    unsigned short memSizeAndFlags;
    short referenceCount;
    unsigned int pad0C;
};
static_assert(sizeof(hkReferencedObject) == 16, "hkReferencedObject layout differs from the PDB");
