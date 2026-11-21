// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESCellReadyToApplyDecalsEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESCellReadyToApplyDecalsEvent_440c5cd0.h"
struct BSTEventSource_RE__TESCellReadyToApplyDecalsEvent_8a313a60 {
    BSTArray_RE__BSTEventSink_RE__TESCellReadyToApplyDecalsEvent_440c5cd0 sinks;
    BSTArray_RE__BSTEventSink_RE__TESCellReadyToApplyDecalsEvent_440c5cd0 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESCellReadyToApplyDecalsEvent_440c5cd0 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESCellReadyToApplyDecalsEvent_8a313a60) == 88, "BSTEventSource_RE__TESCellReadyToApplyDecalsEvent_8a313a60 layout differs from the PDB");
