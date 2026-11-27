// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSShaderAccumulator, BSBatchRenderer, GeometryGroup, FinishAccumulatingSharedModes, RenderBatches, RenderDecalPassesAlt, UpdateWorldCameraProjection, camera, batchRenderer, geometryGroups, flags: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderGeometryGroup, RenderGroup, SaveWorldCameraProjection, TrySaveProjection, g_renderStateFlags, g_depthWriteMode: GUESS(low)
// 0x15206a0 BSShaderAccumulator::FinishAccumulatingSharedModes
#include "BSShaderAccumulator_15206a0.h"

inline bool TrySaveProjection(unsigned int renderFlags)
{
    if ((renderFlags & 0x20u) != 0u && (renderFlags & 0x2u) == 0u) {
        SaveWorldCameraProjection();
        return true;
    }
    return false;
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

void BSShaderAccumulator::FinishAccumulatingSharedModes(unsigned int renderFlags)
{
    if (!camera) {
        return;
    }

    bool savedProjection = ((renderFlags & 0x20u) != 0u && (renderFlags & 0x2u) == 0u);
    if (savedProjection) {
        SaveWorldCameraProjection();
    }

    if ((renderFlags & 0x100u) == 0u) {
        RenderBatches(0x2Bu, 0x4000002Bu, renderFlags, -1);
        RenderBatches(0x5C000030u, 0x5C00005Cu, renderFlags, -1);
        RenderGeometryGroup(1, renderFlags);
        RenderGeometryGroup(9, renderFlags);
        RenderDecalPassesAlt(renderFlags);
    } else {
        if (g_depthWriteMode != 0u) {
            g_renderStateFlags |= 0x20u;
            g_depthWriteMode = 0u;
        }
        RenderGeometryGroup(15, renderFlags);
    }

    if (savedProjection) {
        UpdateWorldCameraProjection();
    }
}
