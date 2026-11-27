// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiObject, NiAccumulator, NiBackToFrontAccumulator, NiAlphaAccumulator, BSShaderAccumulator, RenderDecalPassesAlt, RenderBatches, BSBatchRenderer, GeometryGroup, RendererShadowState, drawDecals, isShadowMapAccumulator, batchRenderer, geometryGroups, flags: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderSettings, GetRenderSettings, shadowState, RenderGroup, RenderGeometryGroup, SetDepthMode, SetFillMode, SetDepthBiasMode, SetAlphaBlendMode, SetAlphaBlendWriteMode, updateFlags, depthMode, depthModePrevious, fillMode, depthBiasMode, blendMode, blendWriteMode, useAltDepthBias: GUESS(low)
// 0x151ff00 BSShaderAccumulator::RenderDecalPassesAlt
#include "BSShaderAccumulator_151ff00.h"

inline void BSShaderAccumulator::RenderGeometryGroup(int index, unsigned int renderFlags)
{
    constexpr unsigned int lastPass = 0x5C006074;
    GeometryGroup* group = batchRenderer->geometryGroups[index];
    if (group) {
        if ((group->flags & 1u) > 0u) {
            group->RenderGroup(renderFlags);
        } else {
            RenderBatches(1, lastPass, renderFlags, index);
        }
    }
}

// Configure depth and bias states, draw the decal geometry group, and reset shadow render states.
void BSShaderAccumulator::RenderDecalPassesAlt(unsigned int renderFlags)
{
    constexpr unsigned int depthPrepassFlag = 0x20;
    constexpr unsigned int applyAlphaPropertyFlag = 0x4;

    if (!drawDecals && !isShadowMapAccumulator) {
        return;
    }

    if ((renderFlags & depthPrepassFlag) == 0) {
        shadowState.SetDepthMode(1);
        RenderSettings* settings = GetRenderSettings();
        shadowState.SetDepthBiasMode(settings->useAltDepthBias ? 11u : 10u);
    } else {
        shadowState.SetDepthMode(3);
    }

    unsigned int groupFlags = renderFlags | (static_cast<unsigned int>((renderFlags & depthPrepassFlag) == 0) << 2);
    RenderGeometryGroup(4, groupFlags);

    shadowState.SetFillMode(0);
    shadowState.SetAlphaBlendMode(0);
    shadowState.SetAlphaBlendWriteMode(0);
    shadowState.SetDepthMode(3);
    shadowState.SetDepthBiasMode(0);
}
