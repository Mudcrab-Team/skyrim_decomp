// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESTrackedStatsEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESTrackedStatsEvent_bd53b9a9.h"
struct BSTEventSource_RE__TESTrackedStatsEvent_e997ca2a {
    BSTArray_RE__BSTEventSink_RE__TESTrackedStatsEvent_bd53b9a9 sinks;
    BSTArray_RE__BSTEventSink_RE__TESTrackedStatsEvent_bd53b9a9 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESTrackedStatsEvent_bd53b9a9 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESTrackedStatsEvent_e997ca2a) == 88, "BSTEventSource_RE__TESTrackedStatsEvent_e997ca2a layout differs from the PDB");
