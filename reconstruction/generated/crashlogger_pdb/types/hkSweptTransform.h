// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSweptTransform; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkQuaternion_eff9c81f.h"
#include "hkVector4.h"
struct hkSweptTransform {
    hkVector4 centerOfMass0;
    hkVector4 centerOfMass1;
    hkQuaternion_eff9c81f rotation0;
    hkQuaternion_eff9c81f rotation1;
    hkVector4 centerOfMassLocal;
};
static_assert(sizeof(hkSweptTransform) == 80, "hkSweptTransform layout differs from the PDB");
