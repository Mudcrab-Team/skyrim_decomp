// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, GetNextPassSlotInGroup, PassGroup, BSRenderPass, passes, renderPass: CRASHLOGGER_PDB(59818@2026.10.24)
// slotCount: GUESS(low)
#pragma once

struct BSRenderPass;
class BSBatchRenderer
{
public:
    enum { slotCount = 5 };
    struct PassGroup
    {
        BSRenderPass* passes[slotCount];
        unsigned int validPassBits;
    };

    bool GetNextPassSlotInGroup(unsigned int group, int& slot);
    unsigned char unrecovered000[8];
    PassGroup* renderPass;
};
