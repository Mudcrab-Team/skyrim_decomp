// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraActivateRefChildren; size 0x28
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSSimpleList_RE__REF_ACTIVATE_DATA_4f47bb4e.h"
struct ExtraActivateRefChildren {
    BSExtraData_4ca6af76 _base;
    BSSimpleList_RE__REF_ACTIVATE_DATA_4f47bb4e children;
    float activateChildrenTimer;
    unsigned int pad24;
};
static_assert(sizeof(ExtraActivateRefChildren) == 40, "ExtraActivateRefChildren layout differs from the PDB");
