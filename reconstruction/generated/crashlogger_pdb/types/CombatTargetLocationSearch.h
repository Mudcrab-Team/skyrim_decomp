// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatTargetLocationSearch; size 0x78
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSTArray_unsigned_int_4b643186.h"
#include "BSTArray_void_9eb8914c.h"
#include "CombatObject_2faf992b.h"
#include "NiPoint3.h"
struct CombatTargetLocationSearchResult;
struct CombatTargetLocationSearch {
    CombatObject_2faf992b _base;
    CombatTargetLocationSearchResult* result;
    BSTArray_unsigned_int_4b643186 array1;
    BSTArray_void_9eb8914c array2;
    BSPointerHandle_RE__Actor_1a35f4b9 actor;
    BSPointerHandle_RE__Actor_1a35f4b9 target;
    unsigned int target_formid;
    NiPoint3 P;
    float r;
    float me_r;
    unsigned int field_68;
    unsigned int field_6C;
    void* lock;
};
static_assert(sizeof(CombatTargetLocationSearch) == 120, "CombatTargetLocationSearch layout differs from the PDB");
