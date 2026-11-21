// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESQuestStageItemDoneEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESQuestStageItemDoneEvent_0bf82346.h"
struct BSTEventSource_RE__TESQuestStageItemDoneEvent_43ab6bf4 {
    BSTArray_RE__BSTEventSink_RE__TESQuestStageItemDoneEvent_0bf82346 sinks;
    BSTArray_RE__BSTEventSink_RE__TESQuestStageItemDoneEvent_0bf82346 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESQuestStageItemDoneEvent_0bf82346 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESQuestStageItemDoneEvent_43ab6bf4) == 88, "BSTEventSource_RE__TESQuestStageItemDoneEvent_43ab6bf4 layout differs from the PDB");
