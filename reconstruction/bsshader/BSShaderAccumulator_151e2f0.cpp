// BSDismemberSkinInstance, unk98, BSShaderProperty, lightData, BSShaderPropertyLightData, activeLightMask: CRASHLOGGER_PDB(59818@2026.10.24)
// skinInstance, rendererData, particleShaderDynamicTriShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// BSShaderAccumulator, AccumulateObject, BSGeometry, renderMode, flagOverrideMode, flagOverrideMask: CRASHLOGGER_PDB(59818@2026.10.24)
// dismemberType, dispatchTable: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// 0x151e2f0 BSShaderAccumulator::AccumulateObject
// CI hash: 0x151e2f0 ?AccumulateObject@BSShaderAccumulator@@QEAA_NPEAVBSGeometry@@_K@Z
#include "BSShaderAccumulator_151e2f0.h"

bool BSShaderAccumulator::AccumulateObject(BSGeometry* geometry, unsigned long long argument)
{
    NiObject* skin = geometry->skinInstance;
    if (skin && &dismemberType == skin->GetRTTI() && !static_cast<BSDismemberSkinInstance*>(skin)->unk98) {
        return true;
    }
    BSShaderProperty* property = geometry->property;
    const unsigned char particleShaderDynamicTriShape = 11;
    if (!property || (!geometry->rendererData && !geometry->skinInstance &&
        !geometry->AsParticlesGeom() && geometry->type != particleShaderDynamicTriShape)) {
        return true;
    }
    bool result = dispatchTable[renderMode](this, geometry, property, argument);
    const unsigned mode = flagOverrideMode;
    const unsigned mask = flagOverrideMask;
    if (mode) {
        if (auto* lightData = geometry->property->lightData) {
            if (mode == 0xffff) {
                lightData->activeLightMask = 0;
            } else {
                lightData->activeLightMask |= mask;
            }
        }
    }
    return result;
}
