// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESMagicEffectApplyEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESMagicEffectApplyEvent_e9a55e50.h"
struct BSTEventSource_RE__TESMagicEffectApplyEvent_ce7f0e15 {
    BSTArray_RE__BSTEventSink_RE__TESMagicEffectApplyEvent_e9a55e50 sinks;
    BSTArray_RE__BSTEventSink_RE__TESMagicEffectApplyEvent_e9a55e50 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESMagicEffectApplyEvent_e9a55e50 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESMagicEffectApplyEvent_ce7f0e15) == 88, "BSTEventSource_RE__TESMagicEffectApplyEvent_ce7f0e15 layout differs from the PDB");
