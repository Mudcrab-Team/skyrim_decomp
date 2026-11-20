// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESContainerChangedEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESContainerChangedEvent_09e4a42a.h"
struct BSTEventSource_RE__TESContainerChangedEvent_3fa830cd {
    BSTArray_RE__BSTEventSink_RE__TESContainerChangedEvent_09e4a42a sinks;
    BSTArray_RE__BSTEventSink_RE__TESContainerChangedEvent_09e4a42a pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESContainerChangedEvent_09e4a42a pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESContainerChangedEvent_3fa830cd) == 88, "BSTEventSource_RE__TESContainerChangedEvent_3fa830cd layout differs from the PDB");
