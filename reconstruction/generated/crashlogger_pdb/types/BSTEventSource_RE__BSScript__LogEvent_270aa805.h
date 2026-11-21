// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSScript::LogEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSScript__LogEvent_a2aaef67.h"
struct BSTEventSource_RE__BSScript__LogEvent_270aa805 {
    BSTArray_RE__BSTEventSink_RE__BSScript__LogEvent_a2aaef67 sinks;
    BSTArray_RE__BSTEventSink_RE__BSScript__LogEvent_a2aaef67 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSScript__LogEvent_a2aaef67 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSScript__LogEvent_270aa805) == 88, "BSTEventSource_RE__BSScript__LogEvent_270aa805 layout differs from the PDB");
