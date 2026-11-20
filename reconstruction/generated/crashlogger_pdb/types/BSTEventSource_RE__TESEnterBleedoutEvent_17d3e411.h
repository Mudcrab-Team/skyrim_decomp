// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESEnterBleedoutEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESEnterBleedoutEvent_0abde228.h"
struct BSTEventSource_RE__TESEnterBleedoutEvent_17d3e411 {
    BSTArray_RE__BSTEventSink_RE__TESEnterBleedoutEvent_0abde228 sinks;
    BSTArray_RE__BSTEventSink_RE__TESEnterBleedoutEvent_0abde228 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESEnterBleedoutEvent_0abde228 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESEnterBleedoutEvent_17d3e411) == 88, "BSTEventSource_RE__TESEnterBleedoutEvent_17d3e411 layout differs from the PDB");
