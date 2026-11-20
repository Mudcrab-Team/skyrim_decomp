// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESMoveAttachDetachEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESMoveAttachDetachEvent_1ad4c430.h"
struct BSTEventSource_RE__TESMoveAttachDetachEvent_6d8ef591 {
    BSTArray_RE__BSTEventSink_RE__TESMoveAttachDetachEvent_1ad4c430 sinks;
    BSTArray_RE__BSTEventSink_RE__TESMoveAttachDetachEvent_1ad4c430 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESMoveAttachDetachEvent_1ad4c430 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESMoveAttachDetachEvent_6d8ef591) == 88, "BSTEventSource_RE__TESMoveAttachDetachEvent_6d8ef591 layout differs from the PDB");
