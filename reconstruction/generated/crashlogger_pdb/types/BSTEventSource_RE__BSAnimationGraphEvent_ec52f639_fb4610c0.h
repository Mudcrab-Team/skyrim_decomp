// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSAnimationGraphEvent>; size 0x58
// one of 2 different PDB types sharing this name
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSAnimationGraphEvent_a76cc557_b188c084.h"
struct BSTEventSource_RE__BSAnimationGraphEvent_ec52f639_fb4610c0 {
    BSTArray_RE__BSTEventSink_RE__BSAnimationGraphEvent_a76cc557_b188c084 sinks;
    BSTArray_RE__BSTEventSink_RE__BSAnimationGraphEvent_a76cc557_b188c084 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSAnimationGraphEvent_a76cc557_b188c084 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSAnimationGraphEvent_ec52f639_fb4610c0) == 88, "BSTEventSource_RE__BSAnimationGraphEvent_ec52f639_fb4610c0 layout differs from the PDB");
