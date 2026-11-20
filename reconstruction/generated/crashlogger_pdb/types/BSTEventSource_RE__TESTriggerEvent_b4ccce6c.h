// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESTriggerEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESTriggerEvent_58b7b2e4.h"
struct BSTEventSource_RE__TESTriggerEvent_b4ccce6c {
    BSTArray_RE__BSTEventSink_RE__TESTriggerEvent_58b7b2e4 sinks;
    BSTArray_RE__BSTEventSink_RE__TESTriggerEvent_58b7b2e4 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESTriggerEvent_58b7b2e4 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESTriggerEvent_b4ccce6c) == 88, "BSTEventSource_RE__TESTriggerEvent_b4ccce6c layout differs from the PDB");
