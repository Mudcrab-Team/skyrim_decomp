// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSShaderAccumulator, BSBatchRenderer, GeometryGroup, RenderDecalPasses, RenderBatches, drawDecals, batchRenderer, geometryGroups, flags: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderGeometryGroup, RenderGroup, RenderStateView, useHighBias, GetRenderStateView, SetDepthMode, SetDepthBiasMode, g_depthBiasEnabled, g_stateDirtyFlags, g_depthMode, g_prevDepthMode, g_depthBiasMode: GUESS(low)
// 0x151fd60 BSShaderAccumulator::RenderDecalPasses
#include "BSShaderAccumulator_151fd60.h"

inline void SetDepthMode(unsigned int mode)
{
    if (g_depthMode != mode) {
        g_depthMode = mode;
        if (g_prevDepthMode != mode) {
            g_stateDirtyFlags |= 0x4u;
        } else {
            g_stateDirtyFlags &= ~0x4u;
        }
    }
}

inline void SetDepthBiasMode(unsigned int mode)
{
    unsigned int effective = g_depthBiasEnabled ? mode : 0u;
    if (g_depthBiasMode != effective) {
        g_stateDirtyFlags |= 0x40u;
        g_depthBiasMode = effective;
    }
}

inline void BSShaderAccumulator::RenderGeometryGroup(int index, unsigned int renderFlags)
{
    const unsigned int lastPass = 0x5C006074u;
    GeometryGroup* group = batchRenderer->geometryGroups[index];
    if (group) {
        if ((group->flags & 1u) > 0u) {
            group->RenderGroup(renderFlags);
        } else {
            RenderBatches(1, lastPass, renderFlags, index);
        }
    }
}

void BSShaderAccumulator::RenderDecalPasses(unsigned int renderFlags)
{
    if (!drawDecals) {
        return;
    }

    SetDepthMode(3u);

    SetDepthBiasMode(GetRenderStateView()->useHighBias ? 7u : 6u);
    RenderGeometryGroup(3, renderFlags);

    SetDepthBiasMode(GetRenderStateView()->useHighBias ? 9u : 8u);
    RenderGeometryGroup(2, renderFlags);

    SetDepthMode(3u);
    SetDepthBiasMode(0u);
}
