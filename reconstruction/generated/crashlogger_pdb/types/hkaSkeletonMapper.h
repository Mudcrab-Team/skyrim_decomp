// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaSkeletonMapper; size 0x90
#pragma once

#include "hkaSkeletonMapperData.h"
struct hkaSkeletonMapper__VFTable;
struct hkaSkeletonMapper {
    hkaSkeletonMapper__VFTable* vftable_hkaSkeletonMapper_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkaSkeletonMapperData m_mapping_10;
};
static_assert(sizeof(hkaSkeletonMapper) == 144, "hkaSkeletonMapper layout differs from the PDB");
