// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESWaitStopEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESWaitStopEvent_3d215604.h"
struct BSTEventSource_RE__TESWaitStopEvent_77e61a8a {
    BSTArray_RE__BSTEventSink_RE__TESWaitStopEvent_3d215604 sinks;
    BSTArray_RE__BSTEventSink_RE__TESWaitStopEvent_3d215604 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESWaitStopEvent_3d215604 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESWaitStopEvent_77e61a8a) == 88, "BSTEventSource_RE__TESWaitStopEvent_77e61a8a layout differs from the PDB");
