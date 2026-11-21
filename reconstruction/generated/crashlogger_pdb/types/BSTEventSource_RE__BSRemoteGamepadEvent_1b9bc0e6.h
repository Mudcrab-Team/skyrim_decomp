// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSRemoteGamepadEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSRemoteGamepadEvent_afd8725b.h"
struct BSTEventSource_RE__BSRemoteGamepadEvent_1b9bc0e6 {
    BSTArray_RE__BSTEventSink_RE__BSRemoteGamepadEvent_afd8725b sinks;
    BSTArray_RE__BSTEventSink_RE__BSRemoteGamepadEvent_afd8725b pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSRemoteGamepadEvent_afd8725b pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSRemoteGamepadEvent_1b9bc0e6) == 88, "BSTEventSource_RE__BSRemoteGamepadEvent_1b9bc0e6 layout differs from the PDB");
