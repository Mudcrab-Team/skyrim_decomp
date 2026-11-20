// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESFurnitureEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESFurnitureEvent_1f0ba99c.h"
struct BSTEventSource_RE__TESFurnitureEvent_a4fc3800 {
    BSTArray_RE__BSTEventSink_RE__TESFurnitureEvent_1f0ba99c sinks;
    BSTArray_RE__BSTEventSink_RE__TESFurnitureEvent_1f0ba99c pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESFurnitureEvent_1f0ba99c pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESFurnitureEvent_a4fc3800) == 88, "BSTEventSource_RE__TESFurnitureEvent_a4fc3800 layout differs from the PDB");
