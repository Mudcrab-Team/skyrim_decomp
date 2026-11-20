// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESWaitStartEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESWaitStartEvent_b881c4b3.h"
struct BSTEventSource_RE__TESWaitStartEvent_2c7b40b7 {
    BSTArray_RE__BSTEventSink_RE__TESWaitStartEvent_b881c4b3 sinks;
    BSTArray_RE__BSTEventSink_RE__TESWaitStartEvent_b881c4b3 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESWaitStartEvent_b881c4b3 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESWaitStartEvent_2c7b40b7) == 88, "BSTEventSource_RE__TESWaitStartEvent_2c7b40b7 layout differs from the PDB");
