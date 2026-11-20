// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BeamProjectile; size 0x248
#pragma once

#include "BSTEventSink_RE__BSProceduralGeomEvent_6806a196.h"
#include "BSTEventSource_RE__BeamProjectileImpactEvent_97b827c6.h"
#include "Projectile.h"
struct BeamProjectile {
    Projectile _base;
    BSTEventSink_RE__BSProceduralGeomEvent_6806a196 eventSink;
    BSTEventSource_RE__BeamProjectileImpactEvent_97b827c6 eventSource;
    unsigned long long unk238;
};
static_assert(sizeof(BeamProjectile) == 584, "BeamProjectile layout differs from the PDB");
