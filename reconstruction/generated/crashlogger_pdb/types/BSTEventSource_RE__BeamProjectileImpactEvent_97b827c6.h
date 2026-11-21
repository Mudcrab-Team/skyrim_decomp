// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::BeamProjectileImpactEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__BeamProjectileImpactEvent_db54360d.h"
struct BSTEventSource_RE__BeamProjectileImpactEvent_97b827c6 {
    BSTArray_RE__BSTEventSink_RE__BeamProjectileImpactEvent_db54360d sinks;
    BSTArray_RE__BSTEventSink_RE__BeamProjectileImpactEvent_db54360d pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__BeamProjectileImpactEvent_db54360d pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__BeamProjectileImpactEvent_97b827c6) == 88, "BSTEventSource_RE__BeamProjectileImpactEvent_97b827c6 layout differs from the PDB");
