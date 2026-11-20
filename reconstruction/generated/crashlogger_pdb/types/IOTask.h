// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IOTask; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTSmartPointer_RE__QueuedFile_3db2ff8c.h"
#include "BSTask.h"
struct IOTask {
    BSTask _base;
    BSTSmartPointer_RE__QueuedFile_3db2ff8c dependency;
    void* children;
    int state;
    unsigned char undefined_34[4];
};
static_assert(sizeof(IOTask) == 56, "IOTask layout differs from the PDB");
