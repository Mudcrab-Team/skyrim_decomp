// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSTransformDeltaEvent>; size 0x58
// one of 2 different PDB types sharing this name
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSTransformDeltaEvent_9232b2c4.h"
struct BSTEventSource_RE__BSTransformDeltaEvent_f7efc871_fb0d4b41 {
    BSTArray_RE__BSTEventSink_RE__BSTransformDeltaEvent_9232b2c4 sinks;
    BSTArray_RE__BSTEventSink_RE__BSTransformDeltaEvent_9232b2c4 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSTransformDeltaEvent_9232b2c4 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSTransformDeltaEvent_f7efc871_fb0d4b41) == 88, "BSTEventSource_RE__BSTransformDeltaEvent_f7efc871_fb0d4b41 layout differs from the PDB");
