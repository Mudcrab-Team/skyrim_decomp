// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UnreachableLocation; size 0x20
#pragma once

#include "AITimeStamp.h"
#include "BGSWorldLocation.h"
struct UnreachableLocation {
    BGSWorldLocation loc;
    AITimeStamp timestamp;
    unsigned int pad1C;
};
static_assert(sizeof(UnreachableLocation) == 32, "UnreachableLocation layout differs from the PDB");
