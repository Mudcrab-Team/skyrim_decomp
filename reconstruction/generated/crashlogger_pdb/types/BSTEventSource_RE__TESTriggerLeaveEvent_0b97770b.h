// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESTriggerLeaveEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESTriggerLeaveEvent_10249114.h"
struct BSTEventSource_RE__TESTriggerLeaveEvent_0b97770b {
    BSTArray_RE__BSTEventSink_RE__TESTriggerLeaveEvent_10249114 sinks;
    BSTArray_RE__BSTEventSink_RE__TESTriggerLeaveEvent_10249114 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESTriggerLeaveEvent_10249114 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESTriggerLeaveEvent_0b97770b) == 88, "BSTEventSource_RE__TESTriggerLeaveEvent_0b97770b layout differs from the PDB");
