// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingRestrictions; size 0x18
#pragma once

#include "BSPathingSearchAreaRestrictions.h"
#include "NiPointer_RE__BSTArray_RE__BSPathingAvoidNode_7f35e883.h"
struct BSPathingRestrictions {
    NiPointer_RE__BSTArray_RE__BSPathingAvoidNode_7f35e883 avoidNodeArray;
    BSPathingSearchAreaRestrictions areaRestrictions;
};
static_assert(sizeof(BSPathingRestrictions) == 24, "BSPathingRestrictions layout differs from the PDB");
