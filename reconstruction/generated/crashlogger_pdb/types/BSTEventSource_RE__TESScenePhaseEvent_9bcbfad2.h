// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESScenePhaseEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESScenePhaseEvent_4e27abc0.h"
struct BSTEventSource_RE__TESScenePhaseEvent_9bcbfad2 {
    BSTArray_RE__BSTEventSink_RE__TESScenePhaseEvent_4e27abc0 sinks;
    BSTArray_RE__BSTEventSink_RE__TESScenePhaseEvent_4e27abc0 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESScenePhaseEvent_4e27abc0 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESScenePhaseEvent_9bcbfad2) == 88, "BSTEventSource_RE__TESScenePhaseEvent_9bcbfad2 layout differs from the PDB");
