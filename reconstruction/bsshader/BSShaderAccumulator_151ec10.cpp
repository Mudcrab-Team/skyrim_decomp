// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShaderAccumulator, BSGeometry, BSShaderProperty, BSRenderPass, RenderPassArray, NiAlphaProperty, FinishAccumulatingAppendPasses, AppendPassToGeometryGroup, flags, drawDecals, isShadowMapAccumulator, alphaProperty, renderMode, lastAccumulatedFrameCount, accumulationHint, batchRenderer, passEnum, next: CRASHLOGGER_PDB(59818@2026.10.24)
// head, alphaFlags, GetRenderPasses: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_frameCount, RegisterPassGeometryGroup: GUESS(low)
// 0x151ec10 BSShaderAccumulator::FinishAccumulatingAppendPasses
#include "BSShaderAccumulator_151ec10.h"

bool BSShaderAccumulator::FinishAccumulatingAppendPasses(BSGeometry* geometry, BSShaderProperty* shaderProperty)
{
    std::uint64_t shaderFlags = shaderProperty->flags;
    if (((shaderFlags & 0x4000000ULL) > 0ULL || (shaderFlags & 0x8000000ULL) > 0ULL) && !drawDecals) {
        if (!isShadowMapAccumulator) {
            return true;
        }
        if ((shaderFlags & 0x100000000ULL) <= 0ULL || (shaderFlags & 0x40000ULL) <= 0ULL) {
            return true;
        }
        NiAlphaProperty* alphaProp = geometry->alphaProperty;
        if (!alphaProp || (alphaProp->alphaFlags & 1u) == 0u) {
            return true;
        }
    }

    RenderPassArray* list = shaderProperty->GetRenderPasses(geometry, renderMode, this);
    shaderProperty->lastAccumulatedFrameCount = g_frameCount;
    if (list) {
        for (BSRenderPass* pass = list->head; pass != nullptr; pass = pass->next) {
            unsigned char hint = pass->accumulationHint;
            if (hint == 11) {
                batchRenderer->AppendPassToGeometryGroup(pass, 9, false);
            } else if (hint == 7) {
                batchRenderer->AppendPassToGeometryGroup(pass, 1, false);
            } else if (hint == 3) {
                batchRenderer->AppendPassToGeometryGroup(pass, 4, false);
            } else if (hint == 8) {
                batchRenderer->AppendPassToGeometryGroup(pass, 15, false);
            } else {
                batchRenderer->RegisterPassGeometryGroup(pass, pass->passEnum);
            }
        }
    }
    return true;
}
