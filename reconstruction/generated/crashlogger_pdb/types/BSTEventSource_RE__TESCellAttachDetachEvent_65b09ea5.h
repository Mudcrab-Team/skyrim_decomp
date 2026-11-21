// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESCellAttachDetachEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESCellAttachDetachEvent_7eb0fd87.h"
struct BSTEventSource_RE__TESCellAttachDetachEvent_65b09ea5 {
    BSTArray_RE__BSTEventSink_RE__TESCellAttachDetachEvent_7eb0fd87 sinks;
    BSTArray_RE__BSTEventSink_RE__TESCellAttachDetachEvent_7eb0fd87 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESCellAttachDetachEvent_7eb0fd87 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESCellAttachDetachEvent_65b09ea5) == 88, "BSTEventSource_RE__TESCellAttachDetachEvent_65b09ea5 layout differs from the PDB");
