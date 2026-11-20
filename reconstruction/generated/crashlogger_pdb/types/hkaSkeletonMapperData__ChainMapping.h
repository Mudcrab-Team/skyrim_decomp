// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaSkeletonMapperData__ChainMapping; size 0x70
#pragma once

#include "hkQsTransform_f8a86d4b.h"
struct hkaSkeletonMapperData__ChainMapping {
    short m_startBoneA_0;
    short m_endBoneA_2;
    short m_startBoneB_4;
    short m_endBoneB_6;
    char _pad_8[8];
    hkQsTransform_f8a86d4b m_startAFromBTransform_10;
    hkQsTransform_f8a86d4b m_endAFromBTransform_40;
};
static_assert(sizeof(hkaSkeletonMapperData__ChainMapping) == 112, "hkaSkeletonMapperData__ChainMapping layout differs from the PDB");
