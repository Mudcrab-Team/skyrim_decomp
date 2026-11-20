// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshTriangleDoorPortal; size 0x10
#pragma once

#include "BSTSmartPointer_RE__BSPathingDoor_281903e3.h"
struct BSNavmeshTriangleDoorPortal {
    BSTSmartPointer_RE__BSPathingDoor_281903e3 door;
    unsigned short owningTriangleIndex;
    unsigned short pad0A;
    unsigned int pad0C;
};
static_assert(sizeof(BSNavmeshTriangleDoorPortal) == 16, "BSNavmeshTriangleDoorPortal layout differs from the PDB");
