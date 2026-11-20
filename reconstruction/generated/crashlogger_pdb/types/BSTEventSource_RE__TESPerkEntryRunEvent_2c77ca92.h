// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESPerkEntryRunEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESPerkEntryRunEvent_045f3e15.h"
struct BSTEventSource_RE__TESPerkEntryRunEvent_2c77ca92 {
    BSTArray_RE__BSTEventSink_RE__TESPerkEntryRunEvent_045f3e15 sinks;
    BSTArray_RE__BSTEventSink_RE__TESPerkEntryRunEvent_045f3e15 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESPerkEntryRunEvent_045f3e15 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESPerkEntryRunEvent_2c77ca92) == 88, "BSTEventSource_RE__TESPerkEntryRunEvent_2c77ca92 layout differs from the PDB");
