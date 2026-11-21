// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BGSEventProcessedEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BGSEventProcessedEvent_01081c7b.h"
struct BSTEventSource_RE__BGSEventProcessedEvent_3d9964de {
    BSTArray_RE__BSTEventSink_RE__BGSEventProcessedEvent_01081c7b sinks;
    BSTArray_RE__BSTEventSink_RE__BGSEventProcessedEvent_01081c7b pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BGSEventProcessedEvent_01081c7b pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BGSEventProcessedEvent_3d9964de) == 88, "BSTEventSource_RE__BGSEventProcessedEvent_3d9964de layout differs from the PDB");
