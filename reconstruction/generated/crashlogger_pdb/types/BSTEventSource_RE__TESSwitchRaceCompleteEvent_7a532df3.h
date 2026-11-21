// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESSwitchRaceCompleteEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESSwitchRaceCompleteEvent_abc53b69.h"
struct BSTEventSource_RE__TESSwitchRaceCompleteEvent_7a532df3 {
    BSTArray_RE__BSTEventSink_RE__TESSwitchRaceCompleteEvent_abc53b69 sinks;
    BSTArray_RE__BSTEventSink_RE__TESSwitchRaceCompleteEvent_abc53b69 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESSwitchRaceCompleteEvent_abc53b69 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESSwitchRaceCompleteEvent_7a532df3) == 88, "BSTEventSource_RE__TESSwitchRaceCompleteEvent_7a532df3 layout differs from the PDB");
