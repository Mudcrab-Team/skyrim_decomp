// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// BSShaderAccumulator, FinishAccumulatingMode25_VolumetricOrOcclusion, RenderBatches, BSBatchRenderer, batchRenderer, geometryGroups, GeometryGroup, flags, camera: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderGeometryGroup, RenderGroup, groupsEnabled: GUESS(low)
// 0x1520830 BSShaderAccumulator::FinishAccumulatingMode25_VolumetricOrOcclusion
// CI hash: 0x1520830 ?FinishAccumulatingMode25_VolumetricOrOcclusion@BSShaderAccumulator@@QEAAXI@Z
#include "BSShaderAccumulator_1520830.h"

inline void BSShaderAccumulator::RenderGeometryGroup(int index, unsigned renderFlags)
{
    const unsigned lastPass = 0x5c006074;
    GeometryGroup* group = batchRenderer->geometryGroups[index];
    if (group) {
        if ((group->flags & 1u) > 0u) {
            group->RenderGroup(renderFlags);
        } else {
            RenderBatches(1, lastPass, renderFlags, index);
        }
    }
}

// The provisional mode name comes from the name map. The body brackets two geometry groups.
void BSShaderAccumulator::FinishAccumulatingMode25_VolumetricOrOcclusion(unsigned renderFlags)
{
    if (camera) {
        groupsEnabled = false;
        RenderGeometryGroup(0, renderFlags);
        RenderGeometryGroup(1, renderFlags);
        groupsEnabled = true;
    }
}
