// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESDestructionStageChangedEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESDestructionStageChangedEvent_ef7ccd44.h"
struct BSTEventSource_RE__TESDestructionStageChangedEvent_5983da61 {
    BSTArray_RE__BSTEventSink_RE__TESDestructionStageChangedEvent_ef7ccd44 sinks;
    BSTArray_RE__BSTEventSink_RE__TESDestructionStageChangedEvent_ef7ccd44 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESDestructionStageChangedEvent_ef7ccd44 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESDestructionStageChangedEvent_5983da61) == 88, "BSTEventSource_RE__TESDestructionStageChangedEvent_5983da61 layout differs from the PDB");
