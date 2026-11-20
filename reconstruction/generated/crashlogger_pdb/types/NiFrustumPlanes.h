// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiFrustumPlanes; size 0x70
#pragma once

#include "ActivePlane.h"
struct NiFrustumPlanes {
    unsigned char cullingPlanes_raw[96];
    ActivePlane activePlanes;
    unsigned int basePlaneStates;
    unsigned int unk68;
    unsigned int unk6C;
};
static_assert(sizeof(NiFrustumPlanes) == 112, "NiFrustumPlanes layout differs from the PDB");
