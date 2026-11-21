// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkRefObject; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "NiObject_de5bc370.h"
#include "hkRefPtr_RE__hkReferencedObject_80d781c0.h"
struct bhkRefObject_7e62c3f6 {
    NiObject_de5bc370 _base;
    hkRefPtr_RE__hkReferencedObject_80d781c0 referencedObject;
};
static_assert(sizeof(bhkRefObject_7e62c3f6) == 24, "bhkRefObject_7e62c3f6 layout differs from the PDB");
