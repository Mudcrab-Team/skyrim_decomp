// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BGSActorDeathEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BGSActorDeathEvent_31439266.h"
struct BSTEventSource_RE__BGSActorDeathEvent_6cdc140d {
    BSTArray_RE__BSTEventSink_RE__BGSActorDeathEvent_31439266 sinks;
    BSTArray_RE__BSTEventSink_RE__BGSActorDeathEvent_31439266 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BGSActorDeathEvent_31439266 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BGSActorDeathEvent_6cdc140d) == 88, "BSTEventSource_RE__BGSActorDeathEvent_6cdc140d layout differs from the PDB");
