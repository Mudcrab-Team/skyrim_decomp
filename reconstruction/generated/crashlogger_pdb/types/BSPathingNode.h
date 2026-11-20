// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingNode; size 0x48
#pragma once

#include "BSPathingLocation.h"
#include "BSTSmartPointer_RE__MovementMessage_5170657b.h"
struct BSPathingNode {
    BSPathingLocation location;
    BSTSmartPointer_RE__MovementMessage_5170657b actionAtNode;
    unsigned char tangent_raw[16];
};
static_assert(sizeof(BSPathingNode) == 72, "BSPathingNode layout differs from the PDB");
