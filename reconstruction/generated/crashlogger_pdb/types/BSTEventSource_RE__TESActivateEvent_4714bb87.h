// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESActivateEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESActivateEvent_5a356145.h"
struct BSTEventSource_RE__TESActivateEvent_4714bb87 {
    BSTArray_RE__BSTEventSink_RE__TESActivateEvent_5a356145 sinks;
    BSTArray_RE__BSTEventSink_RE__TESActivateEvent_5a356145 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESActivateEvent_5a356145 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESActivateEvent_4714bb87) == 88, "BSTEventSource_RE__TESActivateEvent_4714bb87 layout differs from the PDB");
