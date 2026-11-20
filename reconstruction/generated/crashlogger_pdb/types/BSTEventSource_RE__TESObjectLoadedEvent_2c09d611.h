// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESObjectLoadedEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESObjectLoadedEvent_5ac86f33.h"
struct BSTEventSource_RE__TESObjectLoadedEvent_2c09d611 {
    BSTArray_RE__BSTEventSink_RE__TESObjectLoadedEvent_5ac86f33 sinks;
    BSTArray_RE__BSTEventSink_RE__TESObjectLoadedEvent_5ac86f33 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESObjectLoadedEvent_5ac86f33 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESObjectLoadedEvent_2c09d611) == 88, "BSTEventSource_RE__TESObjectLoadedEvent_2c09d611 layout differs from the PDB");
