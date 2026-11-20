// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSProceduralGeomEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSProceduralGeomEvent_0c8c689e.h"
struct BSTEventSource_RE__BSProceduralGeomEvent_281d9705 {
    BSTArray_RE__BSTEventSink_RE__BSProceduralGeomEvent_0c8c689e sinks;
    BSTArray_RE__BSTEventSink_RE__BSProceduralGeomEvent_0c8c689e pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSProceduralGeomEvent_0c8c689e pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSProceduralGeomEvent_281d9705) == 88, "BSTEventSource_RE__BSProceduralGeomEvent_281d9705 layout differs from the PDB");
