// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESPackage; size 0xe0
// one of 2 different PDB types sharing this name
#pragma once

#include "PACKAGE_DATA.h"
#include "PACKAGE_PROCEDURE_TYPE.h"
#include "PackageEventAction.h"
#include "PackageSchedule.h"
#include "TESCondition_4d3cdc88.h"
#include "TESForm.h"
struct BGSIdleCollection_ffcdd2aa;
struct PackageLocation;
struct PackageTarget;
struct TESCombatStyle_cff5b770;
struct TESPackageData_d74d6d41;
struct TESQuest_fe66f8e1;
struct TESPackage_986d2eaa {
    TESForm _base;
    PACKAGE_DATA packData;
    unsigned int pad2C;
    TESPackageData_d74d6d41* data;
    PackageLocation* packLoc;
    PackageTarget* packTarg;
    BGSIdleCollection_ffcdd2aa* idleCollection;
    PackageSchedule packSched;
    unsigned int pad5C;
    TESCondition_4d3cdc88 packConditions;
    TESCombatStyle_cff5b770* combatStyle;
    TESQuest_fe66f8e1* ownerQuest;
    PackageEventAction onBegin;
    PackageEventAction onEnd;
    PackageEventAction onChange;
    PACKAGE_PROCEDURE_TYPE procedureType;
    unsigned int refCount;
};
static_assert(sizeof(TESPackage_986d2eaa) == 224, "TESPackage_986d2eaa layout differs from the PDB");
