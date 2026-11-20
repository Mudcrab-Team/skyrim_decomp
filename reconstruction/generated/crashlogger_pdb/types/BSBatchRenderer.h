// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSBatchRenderer; size 0x108
#pragma once

#include "BSSimpleList_unsigned_int_e1497462.h"
#include "BSTArray_RE__BSBatchRenderer__PassGroup_42bd416c.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_73c5f09d.h"
struct BSBatchRenderer_vtbl;
struct GeometryGroup;
struct BSBatchRenderer {
    BSBatchRenderer_vtbl* __vftable;
    BSTArray_RE__BSBatchRenderer__PassGroup_42bd416c renderPass;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_73c5f09d renderPassMap;
    unsigned long long unk48;
    unsigned int currentFirstPass;
    unsigned int currentLastPass;
    BSSimpleList_unsigned_int_e1497462 activePassIndexList;
    unsigned int groupingAlphasCount;
    bool autoClearPasses;
    unsigned char pad06D;
    unsigned short pad06E;
    GeometryGroup* geometryGroups[16];
    GeometryGroup* alphaGroup;
    void* unk0F8;
    void* unk100;
};
static_assert(sizeof(BSBatchRenderer) == 264, "BSBatchRenderer layout differs from the PDB");
