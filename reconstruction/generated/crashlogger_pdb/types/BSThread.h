// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSThread; size 0x50
#pragma once

#include "CRITICAL_SECTION_9c93bfc5.h"
struct BSThread_vtbl;
struct BSThread {
    BSThread_vtbl* __vftable;
    CRITICAL_SECTION_9c93bfc5 lock;
    void* thread;
    void* ownerThread;
    unsigned int threadID;
    unsigned int ownerThreadID;
    bool initialized;
    unsigned char pad49;
    unsigned short pad4A;
    unsigned int pad4C;
};
static_assert(sizeof(BSThread) == 80, "BSThread layout differs from the PDB");
