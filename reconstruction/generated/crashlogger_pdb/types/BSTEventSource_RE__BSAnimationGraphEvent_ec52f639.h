// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSAnimationGraphEvent>; size 0x58
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSAnimationGraphEvent_a76cc557.h"
struct BSTEventSource_RE__BSAnimationGraphEvent_ec52f639 {
    BSTArray_RE__BSTEventSink_RE__BSAnimationGraphEvent_a76cc557 sinks;
    BSTArray_RE__BSTEventSink_RE__BSAnimationGraphEvent_a76cc557 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSAnimationGraphEvent_a76cc557 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSAnimationGraphEvent_ec52f639) == 88, "BSTEventSource_RE__BSAnimationGraphEvent_ec52f639 layout differs from the PDB");
