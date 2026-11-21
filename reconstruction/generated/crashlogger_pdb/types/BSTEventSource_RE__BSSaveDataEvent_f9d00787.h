// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSSaveDataEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSSaveDataEvent_2e05fe2d.h"
struct BSTEventSource_RE__BSSaveDataEvent_f9d00787 {
    BSTArray_RE__BSTEventSink_RE__BSSaveDataEvent_2e05fe2d sinks;
    BSTArray_RE__BSTEventSink_RE__BSSaveDataEvent_2e05fe2d pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSSaveDataEvent_2e05fe2d pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSSaveDataEvent_f9d00787) == 88, "BSTEventSource_RE__BSSaveDataEvent_f9d00787 layout differs from the PDB");
