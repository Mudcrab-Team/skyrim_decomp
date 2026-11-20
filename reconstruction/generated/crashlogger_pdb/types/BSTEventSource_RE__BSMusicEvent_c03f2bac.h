// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSMusicEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSMusicEvent_0a00be92.h"
struct BSTEventSource_RE__BSMusicEvent_c03f2bac {
    BSTArray_RE__BSTEventSink_RE__BSMusicEvent_0a00be92 sinks;
    BSTArray_RE__BSTEventSink_RE__BSMusicEvent_0a00be92 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSMusicEvent_0a00be92 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSMusicEvent_c03f2bac) == 88, "BSTEventSource_RE__BSMusicEvent_c03f2bac layout differs from the PDB");
