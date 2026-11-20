// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESResetEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESResetEvent_0a5fc097.h"
struct BSTEventSource_RE__TESResetEvent_98d58de3 {
    BSTArray_RE__BSTEventSink_RE__TESResetEvent_0a5fc097 sinks;
    BSTArray_RE__BSTEventSink_RE__TESResetEvent_0a5fc097 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESResetEvent_0a5fc097 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESResetEvent_98d58de3) == 88, "BSTEventSource_RE__TESResetEvent_98d58de3 layout differs from the PDB");
