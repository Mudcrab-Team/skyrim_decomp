// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CrosshairPickData; size 0x38
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "NiPoint3.h"
#include "NiPointer_RE__bhkSimpleShapePhantom_351f27c5.h"
struct bhkRigidBody;
struct CrosshairPickData {
    unsigned int pad00;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 target;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 targetActor;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 grabPickRef;
    NiPoint3 collisionPoint;
    unsigned int pad1C;
    bhkRigidBody* targetCollider;
    NiPointer_RE__bhkSimpleShapePhantom_351f27c5 pickCollider;
    unsigned int collisionInfo;
    unsigned char unk34;
    unsigned char unk35;
    unsigned short unk36;
};
static_assert(sizeof(CrosshairPickData) == 56, "CrosshairPickData layout differs from the PDB");
