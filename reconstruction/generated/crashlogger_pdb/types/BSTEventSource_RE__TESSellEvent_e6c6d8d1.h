// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESSellEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESSellEvent_a8acc7f6.h"
struct BSTEventSource_RE__TESSellEvent_e6c6d8d1 {
    BSTArray_RE__BSTEventSink_RE__TESSellEvent_a8acc7f6 sinks;
    BSTArray_RE__BSTEventSink_RE__TESSellEvent_a8acc7f6 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESSellEvent_a8acc7f6 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESSellEvent_e6c6d8d1) == 88, "BSTEventSource_RE__TESSellEvent_e6c6d8d1 layout differs from the PDB");
