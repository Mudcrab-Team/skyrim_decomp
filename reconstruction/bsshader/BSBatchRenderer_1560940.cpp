// Code origin: original reconstruction; no external implementation body was used.
// Source exposure: binary-analysis and community-generated name/layout evidence.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, BSBatchRenderer::HasActivePassIndexInRange, activePassIndexList: CRASHLOGGER_PDB(59818@2026.10.24)
// Adapted bodies: none.
// 0x1560940 BSBatchRenderer::HasActivePassIndexInRange
#include "BSBatchRenderer_1560940.h"

bool BSBatchRenderer::HasActivePassIndexInRange(std::uint32_t firstPass, std::uint32_t lastPass) const
{
    const ActivePassNode* node = &activePassIndexList;
    if (!node->next && !node->passIndex) {
        return false;
    }
    for (; node; node = node->next) {
        if (node->passIndex > lastPass) {
            return false;
        }
        if (node->passIndex >= firstPass) {
            return true;
        }
    }
    return false;
}
