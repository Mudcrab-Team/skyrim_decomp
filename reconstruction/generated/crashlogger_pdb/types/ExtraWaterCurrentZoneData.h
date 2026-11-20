// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraWaterCurrentZoneData; size 0x68
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSTScatterTable_RE__BSCRC32_RE__BSPointerHandle_RE__TESObjectREFR_std__equal_to_RE__BSP_f6ee4970.h"
#include "NiPoint3.h"
struct Action;
struct TESObjectCELL_f81013b3;
struct ExtraWaterCurrentZoneData {
    BSExtraData_4ca6af76 _base;
    BSTScatterTable_RE__BSCRC32_RE__BSPointerHandle_RE__TESObjectREFR_std__equal_to_RE__BSP_f6ee4970 referenceToActionMap;
    Action* cellAction;
    TESObjectCELL_f81013b3* affectedCell;
    NiPoint3 angularVelocity;
    NiPoint3 linearVelocity;
};
static_assert(sizeof(ExtraWaterCurrentZoneData) == 104, "ExtraWaterCurrentZoneData layout differs from the PDB");
