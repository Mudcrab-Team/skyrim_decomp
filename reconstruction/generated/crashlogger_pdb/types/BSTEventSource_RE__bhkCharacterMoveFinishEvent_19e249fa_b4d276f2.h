// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::bhkCharacterMoveFinishEvent>; size 0x58
// one of 2 different PDB types sharing this name
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__bhkCharacterMoveFinishEvent_1dbb9614.h"
struct BSTEventSource_RE__bhkCharacterMoveFinishEvent_19e249fa_b4d276f2 {
    BSTArray_RE__BSTEventSink_RE__bhkCharacterMoveFinishEvent_1dbb9614 sinks;
    BSTArray_RE__BSTEventSink_RE__bhkCharacterMoveFinishEvent_1dbb9614 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__bhkCharacterMoveFinishEvent_1dbb9614 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__bhkCharacterMoveFinishEvent_19e249fa_b4d276f2) == 88, "BSTEventSource_RE__bhkCharacterMoveFinishEvent_19e249fa_b4d276f2 layout differs from the PDB");
