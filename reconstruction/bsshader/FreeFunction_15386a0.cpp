// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// FirstListAccumulationJob, CullDescriptor, SubmitCullResultsJob, FlushAlphaGroupQueueJob, BSCullingProcess, InitCullDescriptor, DispatchCullAndAccumulate, NiRefObject, NiCamera, NiAVObject, BSCompoundFrustum, BSPortalGraphEntry, accumulator, unk08, camera, geometryListProcess, sceneRoot, lightData, renderTargetIndex, unk61, portalGraphEntry, compoundFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPointer, PortalGraphData, activeCullingProcess, defaultLightData, baseRenderTargetIndex, unk10, unk58, unk131: GUESS(low)
// 0x15386a0 FirstListAccumulationJob
#include "FreeFunction_15386a0.h"

// Submit the first cull list, flush alpha groups, and dispatch follow-up cull passes.
void FirstListAccumulationJob(CullDescriptor* descriptor)
{
    SubmitCullResultsJob(descriptor);
    FlushAlphaGroupQueueJob(descriptor);
    (*activeCullingProcess)->compoundFrustum = nullptr;

    CullDescriptor localDesc;
    localDesc.camera = descriptor->camera.ptr;
    localDesc.geometryListProcess = *activeCullingProcess;

    BSPortalGraphEntry* entry = (*activeCullingProcess)->portalGraphEntry;
    if (entry->unk131) {
        localDesc.unk61 = true;
        localDesc.lightData = &entry->unk10->unk58;
        localDesc.renderTargetIndex = baseRenderTargetIndex;
        DispatchCullAndAccumulate(&localDesc, 1, 1);
    }

    localDesc.lightData = &defaultLightData;
    localDesc.unk61 = false;
    localDesc.renderTargetIndex = baseRenderTargetIndex + 1;
    DispatchCullAndAccumulate(&localDesc, 1, 1);
}
