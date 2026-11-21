// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpEntity; size 0x2d0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "SpuCollisionCallback_79fc8e6e.h"
#include "hkArray_RE__hkpConstraintInstance_8fa29619.h"
#include "hkArray_unsigned_char_c72971e9.h"
#include "hkRefPtr_RE__hkLocalFrame_5999ec6f.h"
#include "hkSmallArray_RE__hkConstraintInternal_3bd94aaa.h"
#include "hkSmallArray_RE__hkpAction_83636b31_e48d6c12.h"
#include "hkSmallArray_RE__hkpContactListener_70bf55a3_3949cf0c.h"
#include "hkpMaterial.h"
#include "hkpMaxSizeMotion.h"
#include "hkpWorldObject_690af56a.h"
struct ExtendedListeners_9c17781f;
struct hkpBreakableBody_eba245b6;
struct hkpSimulationIsland;
struct hkpEntity {
    hkpWorldObject_690af56a _base;
    hkpMaterial material;
    unsigned int pad00C;
    void* limitContactImpulseUtilAndFlag;
    float damageMultiplier;
    unsigned int pad01C;
    hkpBreakableBody_eba245b6* breakableBody;
    unsigned int solverData;
    unsigned short storageIndex;
    unsigned short contactPointCallbackDelay;
    hkSmallArray_RE__hkConstraintInternal_3bd94aaa constraintsMaster;
    hkArray_RE__hkpConstraintInstance_8fa29619 constraintsSlave;
    hkArray_unsigned_char_c72971e9 constraintRuntime;
    hkpSimulationIsland* simulationIsland;
    unsigned char autoRemoveLevel;
    unsigned char numShapeKeysInContactPointProperties;
    unsigned char responseModifierFlags;
    unsigned char pad13B;
    unsigned int uid;
    SpuCollisionCallback_79fc8e6e spuCollisionCallback;
    hkpMaxSizeMotion motion;
    hkSmallArray_RE__hkpContactListener_70bf55a3_3949cf0c contactListeners;
    hkSmallArray_RE__hkpAction_83636b31_e48d6c12 actions;
    hkRefPtr_RE__hkLocalFrame_5999ec6f localFrame;
    ExtendedListeners_9c17781f* extendedListeners;
    unsigned int npData;
    unsigned int pad2C4;
    unsigned long long pad2C8;
};
static_assert(sizeof(hkpEntity) == 720, "hkpEntity layout differs from the PDB");
