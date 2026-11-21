// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BGSFootstepEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BGSFootstepEvent_ad14343c.h"
struct BSTEventSource_RE__BGSFootstepEvent_11dcce9c {
    BSTArray_RE__BSTEventSink_RE__BGSFootstepEvent_ad14343c sinks;
    BSTArray_RE__BSTEventSink_RE__BGSFootstepEvent_ad14343c pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BGSFootstepEvent_ad14343c pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BGSFootstepEvent_11dcce9c) == 88, "BSTEventSource_RE__BGSFootstepEvent_11dcce9c layout differs from the PDB");
