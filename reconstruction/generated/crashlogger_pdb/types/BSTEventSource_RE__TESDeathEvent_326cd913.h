// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESDeathEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESDeathEvent_4420ff89.h"
struct BSTEventSource_RE__TESDeathEvent_326cd913 {
    BSTArray_RE__BSTEventSink_RE__TESDeathEvent_4420ff89 sinks;
    BSTArray_RE__BSTEventSink_RE__TESDeathEvent_4420ff89 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESDeathEvent_4420ff89 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESDeathEvent_326cd913) == 88, "BSTEventSource_RE__TESDeathEvent_326cd913 layout differs from the PDB");
