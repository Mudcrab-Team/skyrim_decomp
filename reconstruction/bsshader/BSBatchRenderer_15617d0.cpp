// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, AppendPassToAlphaGroupSorted, GeometryGroup, batchRenderer, head, tail, alphaGroup, passList, BSRenderPass, PersistentPassList: CRASHLOGGER_PDB(59818@2026.10.24)
// AppendSorted, sortMode: GUESS(low)
// 0x15617d0 BSBatchRenderer::AppendPassToAlphaGroupSorted
#include "BSBatchRenderer_15617d0.h"

// Insert a pass into the persistent list of the current alpha group.
void BSBatchRenderer::AppendPassToAlphaGroupSorted(BSRenderPass* pass, unsigned char sortMode)
{
    alphaGroup->passList.AppendSorted(pass, sortMode, false);
}
