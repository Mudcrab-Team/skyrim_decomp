// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESTopicInfoEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESTopicInfoEvent_820536c2.h"
struct BSTEventSource_RE__TESTopicInfoEvent_ee85b8c2 {
    BSTArray_RE__BSTEventSink_RE__TESTopicInfoEvent_820536c2 sinks;
    BSTArray_RE__BSTEventSink_RE__TESTopicInfoEvent_820536c2 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESTopicInfoEvent_820536c2 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESTopicInfoEvent_ee85b8c2) == 88, "BSTEventSource_RE__TESTopicInfoEvent_ee85b8c2 layout differs from the PDB");
