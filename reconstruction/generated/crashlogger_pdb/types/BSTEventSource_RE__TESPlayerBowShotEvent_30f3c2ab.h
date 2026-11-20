// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESPlayerBowShotEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESPlayerBowShotEvent_1910b82c.h"
struct BSTEventSource_RE__TESPlayerBowShotEvent_30f3c2ab {
    BSTArray_RE__BSTEventSink_RE__TESPlayerBowShotEvent_1910b82c sinks;
    BSTArray_RE__BSTEventSink_RE__TESPlayerBowShotEvent_1910b82c pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESPlayerBowShotEvent_1910b82c pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESPlayerBowShotEvent_30f3c2ab) == 88, "BSTEventSource_RE__TESPlayerBowShotEvent_30f3c2ab layout differs from the PDB");
