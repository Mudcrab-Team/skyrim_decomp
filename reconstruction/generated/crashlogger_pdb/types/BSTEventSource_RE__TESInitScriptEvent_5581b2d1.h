// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESInitScriptEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESInitScriptEvent_45195091.h"
struct BSTEventSource_RE__TESInitScriptEvent_5581b2d1 {
    BSTArray_RE__BSTEventSink_RE__TESInitScriptEvent_45195091 sinks;
    BSTArray_RE__BSTEventSink_RE__TESInitScriptEvent_45195091 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESInitScriptEvent_45195091 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESInitScriptEvent_5581b2d1) == 88, "BSTEventSource_RE__TESInitScriptEvent_5581b2d1 layout differs from the PDB");
