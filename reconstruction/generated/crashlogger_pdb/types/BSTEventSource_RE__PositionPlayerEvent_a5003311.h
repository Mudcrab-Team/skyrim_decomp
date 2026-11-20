// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::PositionPlayerEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__PositionPlayerEvent_b4c862e5.h"
struct BSTEventSource_RE__PositionPlayerEvent_a5003311 {
    BSTArray_RE__BSTEventSink_RE__PositionPlayerEvent_b4c862e5 sinks;
    BSTArray_RE__BSTEventSink_RE__PositionPlayerEvent_b4c862e5 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__PositionPlayerEvent_b4c862e5 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__PositionPlayerEvent_a5003311) == 88, "BSTEventSource_RE__PositionPlayerEvent_a5003311 layout differs from the PDB");
