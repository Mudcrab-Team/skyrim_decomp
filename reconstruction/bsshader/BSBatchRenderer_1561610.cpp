// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, AppendPassToGeometryGroup, geometryGroups, GeometryGroup, BSRenderPass: CRASHLOGGER_PDB(59818@2026.10.24)
// AppendPass, flags: GUESS(low)
// 0x1561610 BSBatchRenderer::AppendPassToGeometryGroup
#include "BSBatchRenderer_1561610.h"

// Forward the pass and its flags to the selected geometry group.
void BSBatchRenderer::AppendPassToGeometryGroup(BSRenderPass* pass, int group, unsigned char flags)
{
    geometryGroups[group]->AppendPass(pass, flags);
}
