// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESQuestInitEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESQuestInitEvent_451d94ec.h"
struct BSTEventSource_RE__TESQuestInitEvent_619e3e7d {
    BSTArray_RE__BSTEventSink_RE__TESQuestInitEvent_451d94ec sinks;
    BSTArray_RE__BSTEventSink_RE__TESQuestInitEvent_451d94ec pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESQuestInitEvent_451d94ec pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESQuestInitEvent_619e3e7d) == 88, "BSTEventSource_RE__TESQuestInitEvent_619e3e7d layout differs from the PDB");
