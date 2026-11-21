// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintOwner; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "hkReferencedObject.h"
#include "hkpConstraintInfo.h"
struct hkpConstraintOwner_1e63eaed {
    hkReferencedObject _base;
    hkpConstraintInfo constraintInfo;
};
static_assert(sizeof(hkpConstraintOwner_1e63eaed) == 32, "hkpConstraintOwner_1e63eaed layout differs from the PDB");
