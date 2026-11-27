// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0x152be10 BSCullingProcess::SetupCullingProcess
#include "BSCullingProcess_152be10.h"

BSCullingProcess* BSCullingProcess::SetupCullingProcess(
    int passType, CullDescriptor* descriptor, BSCullingProcess* process)
{
    BSCullingProcess* result = process;
    if (passType == 0) {
        if (descriptor->ringSelect) {
            auto* parabolic = static_cast<BSParabolicCullingProcess*>(process);
            parabolic->UpdateLightPlanes(descriptor->camera, descriptor->lightRadius, false);
            parabolic->SetBackHemisphereAccumulator(descriptor->unk08);
        } else {
            process->camera = descriptor->camera;
        }

        descriptor->accumulator->camera = descriptor->camera;
        process->ignorePreprocess = descriptor->unk5E;
        process->cullMode = static_cast<BSCPCullingType>(descriptor->cullMode);
        process->compoundFrustum = descriptor->compoundFrustum;
        process->cameraRelatedUpdates = descriptor->unk60;
        process->portalGraphEntry = descriptor->portalGraphEntry;
        process->doCustomCullPlanes = descriptor->unk5F;
        process->updateAccumulateFlag = descriptor->unk62;

        if (descriptor->unk5F) {
            process->customCullPlanes = *descriptor->unk38;
        }

        if (descriptor->unk20) {
            process->SetFrustum(*descriptor->unk20);
        }

        process->unk121 = descriptor->unk5D;
    } else if (passType == 1) {
        result = descriptor->geometryListProcess;
    }

    return result;
}
