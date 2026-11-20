// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BSGamepadEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BSGamepadEvent_19eeacb5.h"
struct BSTEventSource_RE__BSGamepadEvent_9cb27daf {
    BSTArray_RE__BSTEventSink_RE__BSGamepadEvent_19eeacb5 sinks;
    BSTArray_RE__BSTEventSink_RE__BSGamepadEvent_19eeacb5 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BSGamepadEvent_19eeacb5 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BSGamepadEvent_9cb27daf) == 88, "BSTEventSource_RE__BSGamepadEvent_9cb27daf layout differs from the PDB");
