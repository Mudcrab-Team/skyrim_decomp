// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShapeRayCastInput; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "CFilter.h"
#include "hkVector4_f554a678.h"
struct hkpRayShapeCollectionFilter_9e3dc0d7;
struct hkpShapeRayCastInput_bdbc339d {
    hkVector4_f554a678 m_from_0;
    hkVector4_f554a678 m_to_10;
    CFilter collisionFilterInfo;
    unsigned char pad24[4];
    hkpRayShapeCollectionFilter_9e3dc0d7* m_rayShapeCollectionFilter_28;
};
static_assert(sizeof(hkpShapeRayCastInput_bdbc339d) == 48, "hkpShapeRayCastInput_bdbc339d layout differs from the PDB");
