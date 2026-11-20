// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESCustomPackageData; size 0x40
#pragma once

#include "BGSPackageDataList.h"
#include "BSTSmartPointer_RE__BGSPackageDataNameMap_b1c02b41.h"
#include "TESPackageData_d74d6d41.h"
struct IProcedureTreeItem;
struct TESPackage_986d2eaa;
struct TESCustomPackageData {
    TESPackageData_d74d6d41 _base;
    BGSPackageDataList data;
    IProcedureTreeItem* procedureTree;
    BSTSmartPointer_RE__BGSPackageDataNameMap_b1c02b41 nameMap;
    TESPackage_986d2eaa* templateParent;
    unsigned short version;
    bool alwaysRecheckConditions;
    unsigned char pad3B;
    unsigned int pad3C;
};
static_assert(sizeof(TESCustomPackageData) == 64, "TESCustomPackageData layout differs from the PDB");
