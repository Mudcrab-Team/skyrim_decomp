// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSoundHandle; size 0xc
#pragma once

#include "AssumedState.h"
struct BSSoundHandle {
    unsigned int soundID;
    bool assumeSuccess;
    unsigned char pad05;
    unsigned short pad06;
    AssumedState state;
};
static_assert(sizeof(BSSoundHandle) == 12, "BSSoundHandle layout differs from the PDB");
