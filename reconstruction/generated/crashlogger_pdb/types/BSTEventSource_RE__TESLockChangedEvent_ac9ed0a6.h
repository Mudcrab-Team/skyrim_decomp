// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESLockChangedEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESLockChangedEvent_21aa867f.h"
struct BSTEventSource_RE__TESLockChangedEvent_ac9ed0a6 {
    BSTArray_RE__BSTEventSink_RE__TESLockChangedEvent_21aa867f sinks;
    BSTArray_RE__BSTEventSink_RE__TESLockChangedEvent_21aa867f pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESLockChangedEvent_21aa867f pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESLockChangedEvent_ac9ed0a6) == 88, "BSTEventSource_RE__TESLockChangedEvent_ac9ed0a6 layout differs from the PDB");
