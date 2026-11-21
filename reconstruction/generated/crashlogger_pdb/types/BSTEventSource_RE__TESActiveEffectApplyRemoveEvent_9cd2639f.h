// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESActiveEffectApplyRemoveEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESActiveEffectApplyRemoveEvent_cb371124.h"
struct BSTEventSource_RE__TESActiveEffectApplyRemoveEvent_9cd2639f {
    BSTArray_RE__BSTEventSink_RE__TESActiveEffectApplyRemoveEvent_cb371124 sinks;
    BSTArray_RE__BSTEventSink_RE__TESActiveEffectApplyRemoveEvent_cb371124 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESActiveEffectApplyRemoveEvent_cb371124 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESActiveEffectApplyRemoveEvent_9cd2639f) == 88, "BSTEventSource_RE__TESActiveEffectApplyRemoveEvent_9cd2639f layout differs from the PDB");
