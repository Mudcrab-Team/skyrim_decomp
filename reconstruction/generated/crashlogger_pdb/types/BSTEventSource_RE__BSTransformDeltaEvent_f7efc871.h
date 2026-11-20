// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSTransformDeltaEvent>; size 0x58
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSTransformDeltaEvent_9232b2c4_e3552640.h"
struct BSTEventSource_RE__BSTransformDeltaEvent_f7efc871 {
    BSTArray_RE__BSTEventSink_RE__BSTransformDeltaEvent_9232b2c4_e3552640 sinks;
    BSTArray_RE__BSTEventSink_RE__BSTransformDeltaEvent_9232b2c4_e3552640 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSTransformDeltaEvent_9232b2c4_e3552640 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSTransformDeltaEvent_f7efc871) == 88, "BSTEventSource_RE__BSTransformDeltaEvent_f7efc871 layout differs from the PDB");
