// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IOManager; size 0x128
#pragma once

#include "BSTEventSource_RE__BSTaskManagerWaitAction_d92a463e.h"
struct IOManager_vtbl;
struct IOManager {
    IOManager_vtbl* __vftable;
    void* nodePool;
    unsigned int bucketCount;
    unsigned int unk14;
    void* bucketHeads;
    unsigned int unk20;
    unsigned int pad24;
    unsigned char threadCache[24];
    BSTEventSource_RE__BSTaskManagerWaitAction_d92a463e events;
    unsigned char unk98[144];
};
static_assert(sizeof(IOManager) == 296, "IOManager layout differs from the PDB");
