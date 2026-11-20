// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESLoadGameEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESLoadGameEvent_c3102210.h"
struct BSTEventSource_RE__TESLoadGameEvent_6ff91d1b {
    BSTArray_RE__BSTEventSink_RE__TESLoadGameEvent_c3102210 sinks;
    BSTArray_RE__BSTEventSink_RE__TESLoadGameEvent_c3102210 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESLoadGameEvent_c3102210 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESLoadGameEvent_6ff91d1b) == 88, "BSTEventSource_RE__TESLoadGameEvent_6ff91d1b layout differs from the PDB");
