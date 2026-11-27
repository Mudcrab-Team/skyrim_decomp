// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// BSCullingProcess, TestBaseVisibility3, planes, activePlanes, updateAccumulateFlag, enablePlaneOptimization, NiPlane, NiBound, NiPoint3: CRASHLOGGER_PDB(59818@2026.10.24)
// distance, side: GUESS(low) STANDIN
#pragma once

struct NiPoint3 { float x, y, z; };
struct NiPlane { NiPoint3 normal; float constant; };
struct NiBound { NiPoint3 center; float radius; };

struct BSCullingProcess {
    unsigned char unrecovered00[0x3c];
    NiPlane planes[6];
    unsigned int activePlanes;
    unsigned char unrecoveredA0[0x7D];
    bool updateAccumulateFlag;
    unsigned char unrecovered11E[2];
    bool enablePlaneOptimization;
    bool TestBaseVisibility3(const NiBound& bound);
};
