// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESPackage; size 0xe0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "PACKAGE_PROCEDURE_TYPE_ba5a54aa.h"
#include "TESCondition.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESPackage__Data.h"
#include "TESPackage__EventActionData.h"
#include "TESPackage__ScheduleData.h"
struct BGSIdleCollection;
struct PackageLocation_8e1e4e82;
struct TESCombatStyle;
struct TESPackageData;
struct TESPackage__TargetData;
struct TESPackage__VFTable;
struct TESQuest;
struct TESPackage {
    TESPackage__VFTable* vftable_TESPackage_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESPackage__Data BaseData_20;
    unsigned int pad2C;
    TESPackageData* PackageData_30;
    PackageLocation_8e1e4e82* PackageLocationData_38;
    TESPackage__TargetData* PackageTargetData_40;
    BGSIdleCollection* IdleCollection_48;
    TESPackage__ScheduleData PackageSchedule_50;
    unsigned int pad5C;
    TESCondition PackageConditions_60;
    TESCombatStyle* CombatStyle_68;
    TESQuest* OwnerQuest_70;
    TESPackage__EventActionData OnBegin_78;
    TESPackage__EventActionData OnEnd_98;
    TESPackage__EventActionData OnChange_B8;
    PACKAGE_PROCEDURE_TYPE_ba5a54aa procedureType;
    unsigned int refCount;
};
static_assert(sizeof(TESPackage) == 224, "TESPackage layout differs from the PDB");
