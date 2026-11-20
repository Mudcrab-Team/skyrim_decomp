// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::UserEventEnabled>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__UserEventEnabled_4fa176e0.h"
struct BSTEventSource_RE__UserEventEnabled_9c655786 {
    BSTArray_RE__BSTEventSink_RE__UserEventEnabled_4fa176e0 sinks;
    BSTArray_RE__BSTEventSink_RE__UserEventEnabled_4fa176e0 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__UserEventEnabled_4fa176e0 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__UserEventEnabled_9c655786) == 88, "BSTEventSource_RE__UserEventEnabled_9c655786 layout differs from the PDB");
