// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, GetNextPassSlotInGroup, PassGroup, BSRenderPass, passes, renderPass: CRASHLOGGER_PDB(59818@2026.10.24)
// slotCount: GUESS(low)
// 0x155fed0 BSBatchRenderer::GetNextPassSlotInGroup
#include "BSBatchRenderer_155fed0.h"

// Find an occupied slot, resetting the cursor to zero when the group is exhausted.
bool BSBatchRenderer::GetNextPassSlotInGroup(unsigned int group, int& slot)
{
    if (slot < 0 || slot >= slotCount) {
        slot = 0;
    }
    int i;
    for (i = slot; i < slotCount; ++i) {
        if (renderPass[group].passes[i]) {
            slot = i;
            i = slotCount;
        }
    }
    if (i == slotCount) {
        slot = 0;
    }
    return i == slotCount + 1;
}
