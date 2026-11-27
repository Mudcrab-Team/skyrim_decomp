// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GetRTTI, AsMultiIndexTriShape, GetRenderPasses, head, alphaFlags, unk20: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject, NiObject, NiObjectNET, NiProperty, NiShadeProperty, NiAVObject, NiAccumulator, NiBackToFrontAccumulator, NiAlphaAccumulator, BSShaderAccumulator, FinishAccumulatingAppendLocalMapPasses, BSGeometry, BSMultiIndexTriShape, BSShaderProperty, BSShaderPropertyLightData, BSRenderPass, RenderPassArray, BSBatchRenderer, NiAlphaProperty, NiBound, NiRTTI, modelBound, alphaProperty, flags, lightData, lastAccumulatedFrameCount, firstPerson, drawDecals, isShadowMapAccumulator, batchRenderer, renderMode, passEnum, accumulationHint, next, AppendPassToGeometryGroup: CRASHLOGGER_PDB(59818@2026.10.24)
// RegisterPassGeometryGroup, excludedPropertyRTTI, currentFrameCount, secondaryProperty: GUESS(low)
// 0x151e9c0 BSShaderAccumulator::FinishAccumulatingAppendLocalMapPasses
#include "BSShaderAccumulator_151e9c0.h"

// Filter eligible geometry and append primary and secondary local-map render passes.
bool BSShaderAccumulator::FinishAccumulatingAppendLocalMapPasses(BSGeometry* geometry, BSShaderProperty* property)
{
    constexpr float minLocalMapRadius = 50.0f;
    if (geometry->modelBound.radius < minLocalMapRadius) {
        return true;
    }

    std::uint64_t shaderFlags = property->flags;
    if ((shaderFlags & 0x4000000000000ULL) > 0ULL) {
        return true;
    }
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
    if (firstPerson && property->GetRTTI() == &excludedPropertyRTTI) {
        return true;
    }

    unsigned char savedLightFlag = 0;
    BSMultiIndexTriShape* multiIndex = geometry->AsMultiIndexTriShape();
    if (multiIndex && property->lightData) {
        savedLightFlag = property->lightData->unk20;
    }

    RenderPassArray* list = property->GetRenderPasses(geometry, renderMode, this);
    property->lastAccumulatedFrameCount = currentFrameCount;
    if (list && list->head) {
        for (BSRenderPass* pass = list->head; pass; pass = pass->next) {
            batchRenderer->RegisterPassGeometryGroup(pass, pass->passEnum);
        }
        if (multiIndex && multiIndex->secondaryProperty) {
            BSShaderProperty* secondary = multiIndex->secondaryProperty;
            secondary->lightData->unk20 = savedLightFlag;
            RenderPassArray* secondaryList = secondary->GetRenderPasses(geometry, renderMode, this);
            if (secondaryList) {
                for (BSRenderPass* pass = secondaryList->head; pass; pass = pass->next) {
                    pass->accumulationHint = 12;
                    batchRenderer->AppendPassToGeometryGroup(pass, 2, true);
                }
            }
        }
    }
    return true;
}
