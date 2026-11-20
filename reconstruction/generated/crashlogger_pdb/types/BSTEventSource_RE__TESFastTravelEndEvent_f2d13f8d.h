// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESFastTravelEndEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESFastTravelEndEvent_70d34f0e.h"
struct BSTEventSource_RE__TESFastTravelEndEvent_f2d13f8d {
    BSTArray_RE__BSTEventSink_RE__TESFastTravelEndEvent_70d34f0e sinks;
    BSTArray_RE__BSTEventSink_RE__TESFastTravelEndEvent_70d34f0e pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESFastTravelEndEvent_70d34f0e pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESFastTravelEndEvent_f2d13f8d) == 88, "BSTEventSource_RE__TESFastTravelEndEvent_f2d13f8d layout differs from the PDB");
