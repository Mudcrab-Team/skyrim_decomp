// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESQuestStageEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESQuestStageEvent_33b354fc.h"
struct BSTEventSource_RE__TESQuestStageEvent_0f7ffdc4 {
    BSTArray_RE__BSTEventSink_RE__TESQuestStageEvent_33b354fc sinks;
    BSTArray_RE__BSTEventSink_RE__TESQuestStageEvent_33b354fc pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESQuestStageEvent_33b354fc pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESQuestStageEvent_0f7ffdc4) == 88, "BSTEventSource_RE__TESQuestStageEvent_0f7ffdc4 layout differs from the PDB");
