// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PackageTarget; size 0x18
#pragma once

#include "Target.h"
struct PackageTarget {
    unsigned char targType;
    unsigned char pad01;
    unsigned short pad02;
    unsigned char undefined_4[4];
    Target target;
    int value;
    unsigned int pad14;
};
static_assert(sizeof(PackageTarget) == 24, "PackageTarget layout differs from the PDB");
