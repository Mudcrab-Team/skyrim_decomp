// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSSystemEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSSystemEvent_4f0ddb55.h"
struct BSTEventSource_RE__BSSystemEvent_5901f1da {
    BSTArray_RE__BSTEventSink_RE__BSSystemEvent_4f0ddb55 sinks;
    BSTArray_RE__BSTEventSink_RE__BSSystemEvent_4f0ddb55 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSSystemEvent_4f0ddb55 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSSystemEvent_5901f1da) == 88, "BSTEventSource_RE__BSSystemEvent_5901f1da layout differs from the PDB");
