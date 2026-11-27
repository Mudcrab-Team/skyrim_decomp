// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: BSShaderAccumulator::AccumulateObject follows the project unit BSShaderAccumulator_151e2f0.cpp.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GetRTTI, AsGeometry, AsParticlesGeom, skinInstance, rendererData, type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AccumulateNodeChildren, AccumulateSceneGraphContext, BSShaderAccumulator, AccumulateObject, NiRefObject, NiObject, NiObjectNET, NiAVObject, NiNode, BSGeometry, BSShaderProperty, BSShaderPropertyLightData, BSDismemberSkinInstance, NiRTTI, accumulator, filterByShaderProperty, children, flags, shaderProperty, lightData, activeLightMask, unk98, renderMode, flagOverrideMode, flagOverrideMask: CRASHLOGGER_PDB(59818@2026.10.24)
// NiChildArray, CanCastShadow, dismemberType, dispatchTable, data, capacity, freeSlot, size, growBy, particleShaderDynamicTriShape: GUESS(low)
// 0x1521ad0 AccumulateNodeChildren
#include "FreeFunction_1521ad0.h"

inline bool BSShaderAccumulator::AccumulateObject(BSGeometry* geometry, unsigned long long argument)
{
    NiObject* skin = geometry->skinInstance;
    if (skin && &dismemberType == skin->GetRTTI() && !static_cast<BSDismemberSkinInstance*>(skin)->unk98) {
        return true;
    }
    BSShaderProperty* property = geometry->shaderProperty;
    constexpr unsigned char particleShaderDynamicTriShape = 11;
    if (!property || (!geometry->rendererData && !geometry->skinInstance &&
        !geometry->AsParticlesGeom() && geometry->type != particleShaderDynamicTriShape)) {
        return true;
    }
    bool result = dispatchTable[renderMode](this, geometry, property, argument);
    const unsigned int mode = flagOverrideMode;
    const unsigned int mask = flagOverrideMask;
    if (mode) {
        if (BSShaderPropertyLightData* data = geometry->shaderProperty->lightData) {
            if (mode == 0xFFFF) {
                data->activeLightMask = 0;
            } else {
                data->activeLightMask |= mask;
            }
        }
    }
    return result;
}

// Accumulate visible geometry children of a scene-graph node into the shader accumulator.
unsigned int AccumulateNodeChildren(AccumulateSceneGraphContext* context, NiNode* node)
{
    if (!node || (node->flags & 1u) != 0) {
        return 2;
    }

    for (unsigned int i = 0; i < node->children.freeSlot; ++i) {
        NiAVObject* child = node->children.data[i];
        if (!child || !child->AsGeometry() || (child->flags & 1u) != 0) {
            continue;
        }

        bool matchesFilter =
            child->AsGeometry()->shaderProperty != nullptr &&
            child->AsGeometry()->shaderProperty->CanCastShadow() &&
            (child->AsGeometry()->shaderProperty->flags & 0x100000000ULL) <= 0ULL;

        if (!context->filterByShaderProperty || matchesFilter) {
            context->accumulator->AccumulateObject(child->AsGeometry(), 0);
        }
    }

    return 0;
}
