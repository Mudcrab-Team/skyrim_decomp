// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ConeProjectile; size 0x220
#pragma once

#include "BSTArray_void_9eb8914c.h"
#include "NiPoint3.h"
#include "Projectile.h"
#include "hkRefPtr_RE__hkpSphereShape_675b9ed3.h"
struct ConeProjectile {
    Projectile _base;
    unsigned int impactResult;
    float environmentTimer;
    float coneAngleTangent;
    float initialCollisionSphereRadius;
    NiPoint3 origin;
    unsigned int pad1F4;
    hkRefPtr_RE__hkpSphereShape_675b9ed3 collisionShape;
    BSTArray_void_9eb8914c collisions;
};
static_assert(sizeof(ConeProjectile) == 544, "ConeProjectile layout differs from the PDB");
