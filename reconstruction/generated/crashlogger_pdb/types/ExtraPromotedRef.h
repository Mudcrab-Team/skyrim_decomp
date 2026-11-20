// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraPromotedRef; size 0x28
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSTArray_RE__TESForm_7f041170.h"
struct ExtraPromotedRef {
    BSExtraData_4ca6af76 _base;
    BSTArray_RE__TESForm_7f041170 promotedRefOwners;
};
static_assert(sizeof(ExtraPromotedRef) == 40, "ExtraPromotedRef layout differs from the PDB");
