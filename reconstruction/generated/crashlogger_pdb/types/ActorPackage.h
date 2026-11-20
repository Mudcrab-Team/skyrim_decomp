// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorPackage; size 0x30
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSSpinLock.h"
struct ActorPackageData_d9b366d6;
struct TESPackage_986d2eaa;
struct ActorPackage {
    BSSpinLock packageLock;
    TESPackage_986d2eaa* package;
    ActorPackageData_d9b366d6* data;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 target;
    int currentProcedureIndex;
    float packageStartTime;
    unsigned int modifiedPackageFlag;
    unsigned short modifiedInterruptFlag;
    unsigned char actorPackageFlags;  // ACTOR_PACKAGE_FLAG in the PDB is wider than this slot
    unsigned char preferredSpeed;
    unsigned int pad2C;
};
static_assert(sizeof(ActorPackage) == 48, "ActorPackage layout differs from the PDB");
