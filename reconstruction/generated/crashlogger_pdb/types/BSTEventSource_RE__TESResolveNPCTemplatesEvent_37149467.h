// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESResolveNPCTemplatesEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESResolveNPCTemplatesEvent_ed892a86.h"
struct BSTEventSource_RE__TESResolveNPCTemplatesEvent_37149467 {
    BSTArray_RE__BSTEventSink_RE__TESResolveNPCTemplatesEvent_ed892a86 sinks;
    BSTArray_RE__BSTEventSink_RE__TESResolveNPCTemplatesEvent_ed892a86 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESResolveNPCTemplatesEvent_ed892a86 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESResolveNPCTemplatesEvent_37149467) == 88, "BSTEventSource_RE__TESResolveNPCTemplatesEvent_37149467 layout differs from the PDB");
