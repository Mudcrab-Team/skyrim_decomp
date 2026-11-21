// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESTriggerEnterEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESTriggerEnterEvent_3b17a510.h"
struct BSTEventSource_RE__TESTriggerEnterEvent_e5c52c65 {
    BSTArray_RE__BSTEventSink_RE__TESTriggerEnterEvent_3b17a510 sinks;
    BSTArray_RE__BSTEventSink_RE__TESTriggerEnterEvent_3b17a510 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESTriggerEnterEvent_3b17a510 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESTriggerEnterEvent_e5c52c65) == 88, "BSTEventSource_RE__TESTriggerEnterEvent_e5c52c65 layout differs from the PDB");
