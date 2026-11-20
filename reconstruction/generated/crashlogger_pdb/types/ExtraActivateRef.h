// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraActivateRef; size 0x28
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSSimpleList_RE__REF_ACTIVATE_DATA_4f47bb4e.h"
struct ExtraActivateRef {
    BSExtraData_4ca6af76 _base;
    BSSimpleList_RE__REF_ACTIVATE_DATA_4f47bb4e parents;
    unsigned char activateFlags;
    unsigned char pad21;
    unsigned short pad22;
    unsigned int pad24;
};
static_assert(sizeof(ExtraActivateRef) == 40, "ExtraActivateRef layout differs from the PDB");
