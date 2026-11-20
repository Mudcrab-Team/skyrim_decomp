// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESSceneActionEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESSceneActionEvent_9b235cf9.h"
struct BSTEventSource_RE__TESSceneActionEvent_4742f39e {
    BSTArray_RE__BSTEventSink_RE__TESSceneActionEvent_9b235cf9 sinks;
    BSTArray_RE__BSTEventSink_RE__TESSceneActionEvent_9b235cf9 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESSceneActionEvent_9b235cf9 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESSceneActionEvent_4742f39e) == 88, "BSTEventSource_RE__TESSceneActionEvent_4742f39e layout differs from the PDB");
