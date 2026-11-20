// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaSkeletonMapperData; size 0x80
#pragma once

#include "hkArray_hkaSkeletonMapperData__ChainMapping_hkContainerHeapAllocator.h"
#include "hkArray_hkaSkeletonMapperData__SimpleMapping_hkContainerHeapAllocator.h"
#include "hkArray_int16_hkContainerHeapAllocator.h"
#include "hkBool.h"
#include "hkEnum_hkaSkeletonMapperData__MappingType_int32.h"
#include "hkQsTransform_f8a86d4b.h"
#include "hkRefPtr_hkaSkeleton.h"
struct hkaSkeletonMapperData {
    hkRefPtr_hkaSkeleton m_skeletonA_0;
    hkRefPtr_hkaSkeleton m_skeletonB_8;
    hkArray_hkaSkeletonMapperData__ChainMapping_hkContainerHeapAllocator m_chainMappings_20;
    hkQsTransform_f8a86d4b m_extractedMotionMapping_40;
    hkBool m_keepUnmappedLocal_70;
    char _pad_71[3];
    char _pad_78[8];
    hkEnum_hkaSkeletonMapperData__MappingType_int32 m_mappingType_74;
    hkArray_int16_hkContainerHeapAllocator m_unmappedBones_30;
    hkArray_hkaSkeletonMapperData__SimpleMapping_hkContainerHeapAllocator m_simpleMappings_10;
};
static_assert(sizeof(hkaSkeletonMapperData) == 128, "hkaSkeletonMapperData layout differs from the PDB");
