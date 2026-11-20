// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCharacterProxy; size 0xf0
#pragma once

#include "hkArray_RE__hkpCharacterProxyListener_13296115.h"
#include "hkArray_RE__hkpPhantom_f69d7a63.h"
#include "hkArray_RE__hkpRigidBody_e7cd9bbe.h"
#include "hkArray_RE__hkpRootCdPoint_4305c8c8.h"
#include "hkArray_RE__hkpTriggerVolume_b73961f8.h"
#include "hkReferencedObject.h"
#include "hkVector4.h"
#include "hkpEntityListener.h"
#include "hkpPhantomListener_a28899aa.h"
struct hkpShapePhantom;
struct hkpCharacterProxy {
    hkReferencedObject _base;
    hkpEntityListener _base_hkpEntityListener;
    hkpPhantomListener_a28899aa _base_hkpPhantomListener;
    hkArray_RE__hkpRootCdPoint_4305c8c8 manifold;
    hkArray_RE__hkpRigidBody_e7cd9bbe bodies;
    hkArray_RE__hkpPhantom_f69d7a63 phantoms;
    hkArray_RE__hkpTriggerVolume_b73961f8 overlappingTriggerVolumes;
    hkVector4 velocity;
    hkVector4 oldDisplacement;
    hkpShapePhantom* shapePhantom;
    float dynamicFriction;
    float staticFriction;
    hkVector4 up;
    float extraUpStaticFriction;
    float extraDownStaticFriction;
    float keepDistance;
    float keepContactTolerance;
    float contactAngleSensitivity;
    int userPlanes;
    float maxCharacterSpeedForSolver;
    float characterStrength;
    float characterMass;
    unsigned int padC4;
    hkArray_RE__hkpCharacterProxyListener_13296115 listeners;
    float maxSlopeCosine;
    float penetrationRecoverySpeed;
    int maxCastIterations;
    bool refreshManifoldInCheckSupport;
    unsigned char undefined_e5[11];
};
static_assert(sizeof(hkpCharacterProxy) == 240, "hkpCharacterProxy layout differs from the PDB");
