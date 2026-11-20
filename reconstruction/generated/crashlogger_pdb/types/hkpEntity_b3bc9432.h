// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpEntity; size 0x2d0
// one of 2 different PDB types sharing this name
#pragma once

#include "SpuCollisionCallback.h"
#include "hkArray_RE__hkpConstraintInstance_8fa29619.h"
#include "hkArray_unsigned_char_c72971e9.h"
#include "hkRefPtr_RE__hkLocalFrame_5999ec6f.h"
#include "hkSmallArray_RE__hkConstraintInternal_3bd94aaa_5f69f5a3.h"
#include "hkSmallArray_RE__hkpAction_83636b31.h"
#include "hkSmallArray_RE__hkpContactListener_70bf55a3.h"
#include "hkpMaterial_f996c811.h"
#include "hkpMaxSizeMotion_6c02c998.h"
#include "hkpWorldObject.h"
struct ExtendedListeners;
struct hkpBreakableBody;
struct hkpSimulationIsland_f82b975f;
struct hkpEntity_b3bc9432 {
    hkpWorldObject _base;
    hkpMaterial_f996c811 material;
    unsigned int pad00C;
    void* limitContactImpulseUtilAndFlag;
    float damageMultiplier;
    unsigned int pad01C;
    hkpBreakableBody* breakableBody;
    unsigned int solverData;
    unsigned short storageIndex;
    unsigned short contactPointCallbackDelay;
    hkSmallArray_RE__hkConstraintInternal_3bd94aaa_5f69f5a3 constraintsMaster;
    hkArray_RE__hkpConstraintInstance_8fa29619 constraintsSlave;
    hkArray_unsigned_char_c72971e9 constraintRuntime;
    hkpSimulationIsland_f82b975f* simulationIsland;
    unsigned char autoRemoveLevel;
    unsigned char numShapeKeysInContactPointProperties;
    unsigned char responseModifierFlags;
    unsigned char pad13B;
    unsigned int uid;
    SpuCollisionCallback spuCollisionCallback;
    hkpMaxSizeMotion_6c02c998 motion;
    hkSmallArray_RE__hkpContactListener_70bf55a3 contactListeners;
    hkSmallArray_RE__hkpAction_83636b31 actions;
    hkRefPtr_RE__hkLocalFrame_5999ec6f localFrame;
    ExtendedListeners* extendedListeners;
    unsigned int npData;
    unsigned int pad2C4;
    unsigned long long pad2C8;
};
static_assert(sizeof(hkpEntity_b3bc9432) == 720, "hkpEntity_b3bc9432 layout differs from the PDB");
