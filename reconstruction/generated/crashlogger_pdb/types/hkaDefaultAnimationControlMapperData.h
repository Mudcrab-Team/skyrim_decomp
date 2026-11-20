// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaDefaultAnimationControlMapperData; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_int16_hkContainerHeapAllocator.h"
struct hkaDefaultAnimationControlMapperData__VFTable;
struct hkaSkeletonMapper;
struct hkaDefaultAnimationControlMapperData {
    hkaDefaultAnimationControlMapperData__VFTable* vftable_hkaDefaultAnimationControlMapperData_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkaSkeletonMapper* m_mapper_10;
    hkArray_int16_hkContainerHeapAllocator m_srcBoneToTrackIndices_18;
    hkArray_int16_hkContainerHeapAllocator m_dstBoneToTrackIndices_28;
    hkArray_int16_hkContainerHeapAllocator m_dstTrackToBoneIndices_38;
};
static_assert(sizeof(hkaDefaultAnimationControlMapperData) == 72, "hkaDefaultAnimationControlMapperData layout differs from the PDB");
