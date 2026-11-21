// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BGSActorCellEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BGSActorCellEvent_63a69b59.h"
struct BSTEventSource_RE__BGSActorCellEvent_266e4475 {
    BSTArray_RE__BSTEventSink_RE__BGSActorCellEvent_63a69b59 sinks;
    BSTArray_RE__BSTEventSink_RE__BGSActorCellEvent_63a69b59 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BGSActorCellEvent_63a69b59 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BGSActorCellEvent_266e4475) == 88, "BSTEventSource_RE__BGSActorCellEvent_266e4475 layout differs from the PDB");
