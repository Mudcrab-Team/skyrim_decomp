// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<void*>; size 0x58
#pragma once

#include "BSTArray_BSTEventSink_void.h"
#include "Mutex.h"
struct BSTEventSource_void_9d1a19e6 {
    BSTArray_BSTEventSink_void EventSinks_0;
    BSTArray_BSTEventSink_void PendingEventRegisters_18;
    BSTArray_BSTEventSink_void PendingEventUnregisters_30;
    Mutex EventSourceLock_48;
    bool EventSourceNotifying_50;
    char _pad_51[7];
};
static_assert(sizeof(BSTEventSource_void_9d1a19e6) == 88, "BSTEventSource_void_9d1a19e6 layout differs from the PDB");
