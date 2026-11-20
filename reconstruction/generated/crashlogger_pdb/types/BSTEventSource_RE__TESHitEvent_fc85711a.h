// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESHitEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESHitEvent_db57349a.h"
struct BSTEventSource_RE__TESHitEvent_fc85711a {
    BSTArray_RE__BSTEventSink_RE__TESHitEvent_db57349a sinks;
    BSTArray_RE__BSTEventSink_RE__TESHitEvent_db57349a pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESHitEvent_db57349a pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESHitEvent_fc85711a) == 88, "BSTEventSource_RE__TESHitEvent_fc85711a layout differs from the PDB");
