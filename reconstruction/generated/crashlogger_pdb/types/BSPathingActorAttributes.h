// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingActorAttributes; size 0x18
#pragma once

#include "BSTSmartPointer_RE__BSPathingLockData_83dec521.h"
struct BSPathingActorAttributes {
    float radius;
    float height;
    BSTSmartPointer_RE__BSPathingLockData_83dec521 lockData;
    unsigned int data;
    unsigned char undefined_14[4];
};
static_assert(sizeof(BSPathingActorAttributes) == 24, "BSPathingActorAttributes layout differs from the PDB");
