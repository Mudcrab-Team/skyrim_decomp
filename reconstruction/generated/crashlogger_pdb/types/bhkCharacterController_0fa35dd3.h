// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCharacterController; size 0x330
// one of 2 different PDB types sharing this name
#pragma once

#include "BSBound_d0847efa.h"
#include "BSTEventSource_RE__bhkCharacterMoveFinishEvent_19e249fa_b4d276f2.h"
#include "BSTScatterTable_RE__BSCRC32_RE__NiPointer_RE__bhkRigidBody_std__equal_to_RE__NiPointer_285f7b48.h"
#include "CHARACTER_FLAGS.h"
#include "MATERIAL_ID.h"
#include "NiRefObject_f24a9221.h"
#include "hkRefPtr_RE__hkpRigidBody_1c3aded2.h"
#include "hkStepInfo.h"
#include "hkVector4.h"
#include "hkpCharacterContext_47f0195b.h"
#include "hkpCharacterStateType.h"
#include "hkpSurfaceInfo_550ea3d7.h"
struct bhkICharOrientationController_3a768a8c;
struct bhkCharacterController_0fa35dd3 {
    NiRefObject_f24a9221 _base;
    BSTEventSource_RE__bhkCharacterMoveFinishEvent_19e249fa_b4d276f2 _base_BSTEventSource_RE_bhkCharacterMoveFinishEvent_;
    unsigned char undefined_68[8];
    hkVector4 forwardVec;
    hkStepInfo stepInfo;
    hkVector4 outVelocity;
    hkVector4 initialVelocity;
    hkVector4 velocityMod;
    hkVector4 direction;
    hkVector4 rotCenter;
    hkVector4 pushDelta;
    hkVector4 fakeSupportStart;
    hkVector4 up;
    hkVector4 supportNorm;
    BSBound_d0847efa collisionBound;
    BSBound_d0847efa bumperCollisionBound;
    hkVector4 deltaPos;
    bhkICharOrientationController_3a768a8c* orientationCtrl;
    unsigned long long pad198;
    hkpSurfaceInfo_550ea3d7 surfaceInfo;
    hkpCharacterContext_47f0195b context;
    CHARACTER_FLAGS flags;
    hkpCharacterStateType wantState;
    float velocityTime;
    float rotMod;
    float rotModTime;
    float calculatePitchTimer;
    float acrobatics;
    float center;
    float waterHeight;
    float jumpHeight;
    float fallStartHeight;
    float fallTime;
    float gravity;
    float pitchAngle;
    float rollAngle;
    float pitchMult;
    float scale;
    float swimFloatHeight;
    float actorHeight;
    float speedPct;
    unsigned int pushCount;
    unsigned int unk26C;
    unsigned long long unk270;
    unsigned long long unk278;
    unsigned char shapes_raw[16];
    float radius;
    float height;
    float destRadius;
    float lodDistance;
    unsigned int size;
    unsigned int priority;
    int supportCount;
    unsigned int pad2AC;
    hkRefPtr_RE__hkpRigidBody_1c3aded2 supportBody;
    float bumpedForce;
    unsigned int pad2BC;
    hkRefPtr_RE__hkpRigidBody_1c3aded2 bumpedBody;
    hkRefPtr_RE__hkpRigidBody_1c3aded2 bumpedCharCollisionObject;
    BSTScatterTable_RE__BSCRC32_RE__NiPointer_RE__bhkRigidBody_std__equal_to_RE__NiPointer_285f7b48 damageImpacts;
    float zNormal;
    MATERIAL_ID surfaceMaterial;
    unsigned int unk308;
    float unk30C;
    float unk310;
    unsigned int contactPointsCount;
    unsigned int collisionFilterGroup;
    bool unk31C;
    unsigned char unk31D;
    unsigned char unk31E;
    unsigned char unk31F;
    unsigned short unk320;
    unsigned short unk322;
    unsigned int unk324;
    unsigned long long unk328;
};
static_assert(sizeof(bhkCharacterController_0fa35dd3) == 816, "bhkCharacterController_0fa35dd3 layout differs from the PDB");
