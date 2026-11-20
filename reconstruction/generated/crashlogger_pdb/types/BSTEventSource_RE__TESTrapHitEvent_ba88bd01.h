// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESTrapHitEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESTrapHitEvent_2fdfbfc9.h"
struct BSTEventSource_RE__TESTrapHitEvent_ba88bd01 {
    BSTArray_RE__BSTEventSink_RE__TESTrapHitEvent_2fdfbfc9 sinks;
    BSTArray_RE__BSTEventSink_RE__TESTrapHitEvent_2fdfbfc9 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESTrapHitEvent_2fdfbfc9 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESTrapHitEvent_ba88bd01) == 88, "BSTEventSource_RE__TESTrapHitEvent_ba88bd01 layout differs from the PDB");
