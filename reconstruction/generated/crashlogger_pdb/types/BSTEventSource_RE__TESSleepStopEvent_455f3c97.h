// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESSleepStopEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESSleepStopEvent_47d0af12.h"
struct BSTEventSource_RE__TESSleepStopEvent_455f3c97 {
    BSTArray_RE__BSTEventSink_RE__TESSleepStopEvent_47d0af12 sinks;
    BSTArray_RE__BSTEventSink_RE__TESSleepStopEvent_47d0af12 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESSleepStopEvent_47d0af12 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESSleepStopEvent_455f3c97) == 88, "BSTEventSource_RE__TESSleepStopEvent_455f3c97 layout differs from the PDB");
