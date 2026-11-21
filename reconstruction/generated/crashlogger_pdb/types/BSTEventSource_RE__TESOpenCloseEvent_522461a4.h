// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESOpenCloseEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESOpenCloseEvent_29cc6658.h"
struct BSTEventSource_RE__TESOpenCloseEvent_522461a4 {
    BSTArray_RE__BSTEventSink_RE__TESOpenCloseEvent_29cc6658 sinks;
    BSTArray_RE__BSTEventSink_RE__TESOpenCloseEvent_29cc6658 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESOpenCloseEvent_29cc6658 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESOpenCloseEvent_522461a4) == 88, "BSTEventSource_RE__TESOpenCloseEvent_522461a4 layout differs from the PDB");
