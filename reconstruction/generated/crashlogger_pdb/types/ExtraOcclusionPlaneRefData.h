// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraOcclusionPlaneRefData; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct OcclusionPlaneLinkedRefData;
struct ExtraOcclusionPlaneRefData {
    BSExtraData_4ca6af76 _base;
    OcclusionPlaneLinkedRefData* data;
};
static_assert(sizeof(ExtraOcclusionPlaneRefData) == 24, "ExtraOcclusionPlaneRefData layout differs from the PDB");
