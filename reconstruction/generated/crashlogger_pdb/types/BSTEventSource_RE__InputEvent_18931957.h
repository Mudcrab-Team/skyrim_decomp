// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::InputEvent *>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__InputEvent_dc0f1a39.h"
struct BSTEventSource_RE__InputEvent_18931957 {
    BSTArray_RE__BSTEventSink_RE__InputEvent_dc0f1a39 sinks;
    BSTArray_RE__BSTEventSink_RE__InputEvent_dc0f1a39 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__InputEvent_dc0f1a39 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__InputEvent_18931957) == 88, "BSTEventSource_RE__InputEvent_18931957 layout differs from the PDB");
