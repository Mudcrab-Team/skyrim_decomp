// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshClosedDoorInfo; size 0x10
#pragma once

#include "BSTSmartPointer_RE__BSPathingDoor_281903e3.h"
struct BSNavmeshClosedDoorInfo {
    BSTSmartPointer_RE__BSPathingDoor_281903e3 door;
    unsigned short triangleIndex;
    unsigned short pad0A;
    unsigned int pad0C;
};
static_assert(sizeof(BSNavmeshClosedDoorInfo) == 16, "BSNavmeshClosedDoorInfo layout differs from the PDB");
