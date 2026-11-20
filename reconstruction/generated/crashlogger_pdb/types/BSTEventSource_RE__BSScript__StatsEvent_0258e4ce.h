// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSScript::StatsEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSScript__StatsEvent_85ecbd6c.h"
struct BSTEventSource_RE__BSScript__StatsEvent_0258e4ce {
    BSTArray_RE__BSTEventSink_RE__BSScript__StatsEvent_85ecbd6c sinks;
    BSTArray_RE__BSTEventSink_RE__BSScript__StatsEvent_85ecbd6c pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSScript__StatsEvent_85ecbd6c pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSScript__StatsEvent_0258e4ce) == 88, "BSTEventSource_RE__BSScript__StatsEvent_0258e4ce layout differs from the PDB");
