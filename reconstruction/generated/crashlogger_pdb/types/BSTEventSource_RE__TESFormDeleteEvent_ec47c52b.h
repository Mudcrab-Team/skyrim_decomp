// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESFormDeleteEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESFormDeleteEvent_c8d9cee6.h"
struct BSTEventSource_RE__TESFormDeleteEvent_ec47c52b {
    BSTArray_RE__BSTEventSink_RE__TESFormDeleteEvent_c8d9cee6 sinks;
    BSTArray_RE__BSTEventSink_RE__TESFormDeleteEvent_c8d9cee6 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESFormDeleteEvent_c8d9cee6 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESFormDeleteEvent_ec47c52b) == 88, "BSTEventSource_RE__TESFormDeleteEvent_ec47c52b layout differs from the PDB");
