// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<void *>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_void_6fd5c633.h"
struct BSTEventSource_void_5fe0fef5 {
    BSTArray_RE__BSTEventSink_void_6fd5c633 sinks;
    BSTArray_RE__BSTEventSink_void_6fd5c633 pendingRegisters;
    BSTArray_RE__BSTEventSink_void_6fd5c633 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_void_5fe0fef5) == 88, "BSTEventSource_void_5fe0fef5 layout differs from the PDB");
