// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSCullingProcess, TestBaseVisibility2, BSOcclusionPlane, NiCullingProcess and NiCamera layouts: CRASHLOGGER_PDB(59818@2026.10.24)
// TestPlanes and its signature: GUESS(low) STANDIN
#pragma once

#include "generated/crashlogger_pdb/types/NiCullingProcess.h"
#include "generated/crashlogger_pdb/types/NiPoint3.h"

struct NiCamera {
    unsigned char unknown00[0xA0];
    NiPoint3 worldPosition;
};



struct BSOcclusionPlane {
    bool TestPlanes(NiFrustumPlanes& planes, const NiPoint3& eye);
};

struct BSCullingProcess : NiCullingProcess {
    bool TestBaseVisibility2(BSOcclusionPlane& plane);
};
