// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESSpellCastEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESSpellCastEvent_53e3d3e8.h"
struct BSTEventSource_RE__TESSpellCastEvent_45b9ed17 {
    BSTArray_RE__BSTEventSink_RE__TESSpellCastEvent_53e3d3e8 sinks;
    BSTArray_RE__BSTEventSink_RE__TESSpellCastEvent_53e3d3e8 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESSpellCastEvent_53e3d3e8 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESSpellCastEvent_45b9ed17) == 88, "BSTEventSource_RE__TESSpellCastEvent_45b9ed17 layout differs from the PDB");
