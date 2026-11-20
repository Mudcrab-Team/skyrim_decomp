// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSTaskManagerWaitAction>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSTaskManagerWaitAction_94859ba7.h"
struct BSTEventSource_RE__BSTaskManagerWaitAction_d92a463e {
    BSTArray_RE__BSTEventSink_RE__BSTaskManagerWaitAction_94859ba7 sinks;
    BSTArray_RE__BSTEventSink_RE__BSTaskManagerWaitAction_94859ba7 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSTaskManagerWaitAction_94859ba7 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSTaskManagerWaitAction_d92a463e) == 88, "BSTEventSource_RE__BSTaskManagerWaitAction_d92a463e layout differs from the PDB");
