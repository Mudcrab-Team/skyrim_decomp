// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollisionQualityInfo; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct hkpCollisionQualityInfo {
    float keepContact;
    float create4dContact;
    float createContact;
    float manifoldTimDistance;
    int useContinuousPhysics;
    bool useSimpleToiHandling;
    unsigned char pad15;
    unsigned short pad16;
    float minSeparation;
    float minExtraSeparation;
    float minSafeDeltaTime;
    float minAbsoluteSafeDeltaTime;
    float toiSeparation;
    float toiExtraSeparation;
    float toiAccuracy;
    float maxContraintViolation;
    float minToiDeltaTime;
    unsigned short constraintPriority;
    bool enableToiWeldRejection;
    unsigned char pad3F;
};
static_assert(sizeof(hkpCollisionQualityInfo) == 64, "hkpCollisionQualityInfo layout differs from the PDB");
