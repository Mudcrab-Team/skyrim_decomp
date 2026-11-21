// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESActorLocationChangeEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESActorLocationChangeEvent_4a8e93d3.h"
struct BSTEventSource_RE__TESActorLocationChangeEvent_2f8b17a9 {
    BSTArray_RE__BSTEventSink_RE__TESActorLocationChangeEvent_4a8e93d3 sinks;
    BSTArray_RE__BSTEventSink_RE__TESActorLocationChangeEvent_4a8e93d3 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESActorLocationChangeEvent_4a8e93d3 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESActorLocationChangeEvent_2f8b17a9) == 88, "BSTEventSource_RE__TESActorLocationChangeEvent_2f8b17a9 layout differs from the PDB");
