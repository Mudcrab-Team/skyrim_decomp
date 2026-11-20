// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCharacterController; size 0x330
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSBound.h"
#include "BSTEventSource_RE__bhkCharacterMoveFinishEvent_19e249fa.h"
#include "EnumSet_RE__CHARACTER_FLAGS_unsigned_int_78ed6acb.h"
#include "MATERIAL_ID.h"
#include "NiRefObject.h"
#include "hkRefPtr_RE__hkpRigidBody_1c3aded2.h"
#include "hkStepInfo_751f46fd.h"
#include "hkVector4_f554a678.h"
#include "hkpCharacterContext.h"
#include "hkpCharacterStateType_dce6b736.h"
#include "hkpSurfaceInfo.h"
struct bhkICharOrientationController;
struct bhkWorldObject;
struct bhkCharacterController {
    NiRefObject _base;
    BSTEventSource_RE__bhkCharacterMoveFinishEvent_19e249fa _base_BSTEventSource_RE_bhkCharacterMoveFinishEvent_;
    unsigned char undefined_68[8];
    hkVector4_f554a678 forwardVec;
    hkStepInfo_751f46fd stepInfo;
    hkVector4_f554a678 outVelocity;
    hkVector4_f554a678 initialVelocity;
    hkVector4_f554a678 velocityMod;
    hkVector4_f554a678 direction;
    hkVector4_f554a678 rotCenter;
    hkVector4_f554a678 pushDelta;
    hkVector4_f554a678 fakeSupportStart;
    hkVector4_f554a678 up;
    hkVector4_f554a678 supportNorm;
    BSBound collisionBound;
    BSBound bumperCollisionBound;
    hkVector4_f554a678 deltaPos;
    bhkICharOrientationController* orientationCtrl;
    unsigned long long pad198;
    hkpSurfaceInfo surfaceInfo;
    hkpCharacterContext context;
    EnumSet_RE__CHARACTER_FLAGS_unsigned_int_78ed6acb flags;
    hkpCharacterStateType_dce6b736 wantState;
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
    bhkWorldObject* fld270;
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
    unsigned char undefined_2d0[8];
    unsigned int field74_0x2d8;
    unsigned int field75_0x2dc;
    unsigned int field76_0x2e0;
    unsigned int field77_0x2e4;
    unsigned char* field78_0x2e8;
    unsigned char undefined_2f0[8];
    unsigned char* field87_0x2f8;
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
static_assert(sizeof(bhkCharacterController) == 816, "bhkCharacterController layout differs from the PDB");
