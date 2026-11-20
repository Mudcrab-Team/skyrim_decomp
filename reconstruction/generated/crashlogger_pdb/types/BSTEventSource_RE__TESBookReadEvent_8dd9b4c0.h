// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESBookReadEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESBookReadEvent_9cbc5003.h"
struct BSTEventSource_RE__TESBookReadEvent_8dd9b4c0 {
    BSTArray_RE__BSTEventSink_RE__TESBookReadEvent_9cbc5003 sinks;
    BSTArray_RE__BSTEventSink_RE__TESBookReadEvent_9cbc5003 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESBookReadEvent_9cbc5003 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESBookReadEvent_8dd9b4c0) == 88, "BSTEventSource_RE__TESBookReadEvent_8dd9b4c0 layout differs from the PDB");
