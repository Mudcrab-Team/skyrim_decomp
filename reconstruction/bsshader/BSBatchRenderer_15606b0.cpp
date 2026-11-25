// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, InitSDM: CRASHLOGGER_PDB(59818@2026.10.24)
// groupState, groupIndex, nextGroupState: GUESS(low)
// 0x15606b0 BSBatchRenderer::InitSDM
#include "BSBatchRenderer_15606b0.h"

// Reset the shared state used by the batch renderer.
void BSBatchRenderer::InitSDM()
{
    groupState = nullptr;
    groupIndex = 0;
    nextGroupState = nullptr;
}
