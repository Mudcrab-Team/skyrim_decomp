// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDecalGroup; size 0x38
#pragma once

#include "BSTArray_RE__DECAL_CREATION_DATA_4c7e0b6d.h"
#include "BSTArray_unsigned_int_4b643186.h"
struct BGSDecalGroup {
    bool permanentGroup;
    bool manualSaveLoad;
    unsigned short pad02;
    unsigned int pad04;
    BSTArray_unsigned_int_4b643186 decalGroups;
    BSTArray_RE__DECAL_CREATION_DATA_4c7e0b6d pendingDecals;
};
static_assert(sizeof(BGSDecalGroup) == 56, "BGSDecalGroup layout differs from the PDB");
