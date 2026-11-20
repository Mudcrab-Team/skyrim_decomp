// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BGSSaveLoadManagerEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BGSSaveLoadManagerEvent_acd9e0bf.h"
struct BSTEventSource_RE__BGSSaveLoadManagerEvent_d762136b {
    BSTArray_RE__BSTEventSink_RE__BGSSaveLoadManagerEvent_acd9e0bf sinks;
    BSTArray_RE__BSTEventSink_RE__BGSSaveLoadManagerEvent_acd9e0bf pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BGSSaveLoadManagerEvent_acd9e0bf pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BGSSaveLoadManagerEvent_d762136b) == 88, "BSTEventSource_RE__BGSSaveLoadManagerEvent_d762136b layout differs from the PDB");
