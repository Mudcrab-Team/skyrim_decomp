// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GarbageCollector; size 0x18
#pragma once

#include "BSTEventSink_RE__PositionPlayerEvent_141ac998.h"
#include "BSTSingletonSDM_RE__GarbageCollector_9c05cdb6.h"
struct GarbageCollection;
struct GarbageCollector {
    BSTEventSink_RE__PositionPlayerEvent_141ac998 _base;
    BSTSingletonSDM_RE__GarbageCollector_9c05cdb6 _base_BSTSingletonSDM_RE_GarbageCollector_;
    unsigned char undefined_9[7];
    GarbageCollection* garbageCollection;
};
static_assert(sizeof(GarbageCollector) == 24, "GarbageCollector layout differs from the PDB");
