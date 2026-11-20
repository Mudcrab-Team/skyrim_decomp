// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbProjectData; size 0x30
#pragma once

#include "hkRefPtr_RE__hkbProjectStringData_4aa987b1.h"
#include "hkReferencedObject.h"
#include "hkVector4.h"
struct hkbProjectData {
    hkReferencedObject _base;
    hkVector4 worldUpWS;
    hkRefPtr_RE__hkbProjectStringData_4aa987b1 stringData;
    unsigned char defaultEventNode;
    unsigned char undefined_29[7];
};
static_assert(sizeof(hkbProjectData) == 48, "hkbProjectData layout differs from the PDB");
