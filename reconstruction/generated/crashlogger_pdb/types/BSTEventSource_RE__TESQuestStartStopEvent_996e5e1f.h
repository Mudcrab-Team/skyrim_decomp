// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESQuestStartStopEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESQuestStartStopEvent_04460dd8.h"
struct BSTEventSource_RE__TESQuestStartStopEvent_996e5e1f {
    BSTArray_RE__BSTEventSink_RE__TESQuestStartStopEvent_04460dd8 sinks;
    BSTArray_RE__BSTEventSink_RE__TESQuestStartStopEvent_04460dd8 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESQuestStartStopEvent_04460dd8 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESQuestStartStopEvent_996e5e1f) == 88, "BSTEventSource_RE__TESQuestStartStopEvent_996e5e1f layout differs from the PDB");
