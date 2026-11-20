// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESGrabReleaseEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESGrabReleaseEvent_ffee45a1.h"
struct BSTEventSource_RE__TESGrabReleaseEvent_ee994fe3 {
    BSTArray_RE__BSTEventSink_RE__TESGrabReleaseEvent_ffee45a1 sinks;
    BSTArray_RE__BSTEventSink_RE__TESGrabReleaseEvent_ffee45a1 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESGrabReleaseEvent_ffee45a1 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESGrabReleaseEvent_ee994fe3) == 88, "BSTEventSource_RE__TESGrabReleaseEvent_ee994fe3 layout differs from the PDB");
