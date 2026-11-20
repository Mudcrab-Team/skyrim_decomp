// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESUniqueIDChangeEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESUniqueIDChangeEvent_35c05e30.h"
struct BSTEventSource_RE__TESUniqueIDChangeEvent_033445db {
    BSTArray_RE__BSTEventSink_RE__TESUniqueIDChangeEvent_35c05e30 sinks;
    BSTArray_RE__BSTEventSink_RE__TESUniqueIDChangeEvent_35c05e30 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESUniqueIDChangeEvent_35c05e30 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESUniqueIDChangeEvent_033445db) == 88, "BSTEventSource_RE__TESUniqueIDChangeEvent_033445db layout differs from the PDB");
