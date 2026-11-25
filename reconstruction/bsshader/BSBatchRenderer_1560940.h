// Code origin: original reconstruction; no external implementation body was used.
// Source exposure: binary-analysis and community-generated name/layout evidence.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, BSBatchRenderer::HasActivePassIndexInRange, activePassIndexList: CRASHLOGGER_PDB(59818@2026.10.24)
// ActivePassNode, passIndex, next, unrecovered000: GUESS(low); minimal observed list view.
#pragma once

#include <cstddef>
#include <cstdint>

class BSBatchRenderer
{
public:
    struct ActivePassNode
    {
        std::uint32_t passIndex;
        ActivePassNode* next;
    };

    // 0x1560940 BSBatchRenderer::HasActivePassIndexInRange
    bool HasActivePassIndexInRange(std::uint32_t firstPass, std::uint32_t lastPass) const;

    std::uint8_t unrecovered000[0x58];
    ActivePassNode activePassIndexList;
};
static_assert(offsetof(BSBatchRenderer, activePassIndexList) == 0x58, "active pass head offset");
static_assert(offsetof(BSBatchRenderer::ActivePassNode, next) == 8, "active pass link offset");
