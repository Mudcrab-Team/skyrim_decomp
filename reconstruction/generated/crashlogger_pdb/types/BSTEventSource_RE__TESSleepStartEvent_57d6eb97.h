// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESSleepStartEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESSleepStartEvent_838e400e.h"
struct BSTEventSource_RE__TESSleepStartEvent_57d6eb97 {
    BSTArray_RE__BSTEventSink_RE__TESSleepStartEvent_838e400e sinks;
    BSTArray_RE__BSTEventSink_RE__TESSleepStartEvent_838e400e pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESSleepStartEvent_838e400e pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESSleepStartEvent_57d6eb97) == 88, "BSTEventSource_RE__TESSleepStartEvent_57d6eb97 layout differs from the PDB");
