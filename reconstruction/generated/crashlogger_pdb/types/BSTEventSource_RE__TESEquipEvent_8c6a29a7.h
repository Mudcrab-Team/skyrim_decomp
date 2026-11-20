// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESEquipEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESEquipEvent_5b0d5416.h"
struct BSTEventSource_RE__TESEquipEvent_8c6a29a7 {
    BSTArray_RE__BSTEventSink_RE__TESEquipEvent_5b0d5416 sinks;
    BSTArray_RE__BSTEventSink_RE__TESEquipEvent_5b0d5416 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESEquipEvent_5b0d5416 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESEquipEvent_8c6a29a7) == 88, "BSTEventSource_RE__TESEquipEvent_8c6a29a7 layout differs from the PDB");
