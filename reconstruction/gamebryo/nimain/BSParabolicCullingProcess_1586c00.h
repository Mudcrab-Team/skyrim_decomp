// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSParabolicCullingProcess, Process2, NiCamera::viewFrustum, NiCullingProcess layout, NiCullingProcess::SetFrustum and NiAVObject::Cull: CRASHLOGGER_PDB(59818@2026.10.24)
// SetFrustum and Cull signatures: GUESS(low) STANDIN
#pragma once

#include "generated/crashlogger_pdb/types/NiCullingProcess.h"


struct NiCamera {
    unsigned char unknown00[0x150];
    NiFrustum viewFrustum;
};
struct BSParabolicCullingProcess;
struct NiAVObject {
    void Cull(BSParabolicCullingProcess* process, unsigned int argument);
};
struct BSParabolicCullingProcess : NiCullingProcess {
    void SetFrustum(const NiFrustum& frustum);
    void Process2(NiCamera* camera, NiAVObject* scene, NiVisibleArray* visible);
};
