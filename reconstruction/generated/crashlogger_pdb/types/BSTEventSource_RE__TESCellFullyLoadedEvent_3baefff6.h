// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESCellFullyLoadedEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESCellFullyLoadedEvent_b1b80798.h"
struct BSTEventSource_RE__TESCellFullyLoadedEvent_3baefff6 {
    BSTArray_RE__BSTEventSink_RE__TESCellFullyLoadedEvent_b1b80798 sinks;
    BSTArray_RE__BSTEventSink_RE__TESCellFullyLoadedEvent_b1b80798 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESCellFullyLoadedEvent_b1b80798 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESCellFullyLoadedEvent_3baefff6) == 88, "BSTEventSource_RE__TESCellFullyLoadedEvent_3baefff6 layout differs from the PDB");
