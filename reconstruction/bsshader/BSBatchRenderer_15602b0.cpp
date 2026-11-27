// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, GetRenderPassIndex, PassGroup, BSRenderPass, passes, validPassBits, renderPass, autoClearPasses: CRASHLOGGER_PDB(59818@2026.10.24)
// AdvancePass, Entry, entries, sentinel, capacity, key, index: GUESS(low)
// 0x15602b0 BSBatchRenderer::GetRenderPassIndex
#include "BSBatchRenderer_15602b0.h"

// Clear the current pass group when requested and advance the traversal.
bool BSBatchRenderer::GetRenderPassIndex(unsigned int& key, int& slot, PassIndexNode*& position)
{
    unsigned int index = 0;
    if (entries) {
        Entry* entry = &entries[key & (capacity - 1)];
        if (entry->next) {
            do {
                if (entry->key == key) {
                    index = entry->index;
                    break;
                }
                entry = entry->next;
            } while (entry != sentinel);
        }
    }
    if (autoClearPasses) {
        PassGroup& group = renderPass[index];
        for (unsigned int i = 0; i < 5; ++i) {
            group.passes[i] = nullptr;
        }
        group.validPassBits = 0;
    }
    return AdvancePass(key, slot, position);
}
