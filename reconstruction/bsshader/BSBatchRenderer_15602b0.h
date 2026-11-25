// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, GetRenderPassIndex, PassGroup, BSRenderPass, passes, validPassBits, renderPass, autoClearPasses: CRASHLOGGER_PDB(59818@2026.10.24)
// PassIndexNode, AdvancePass, Entry, entries, sentinel, capacity, key, index: GUESS(low)
#pragma once

struct BSRenderPass;
class BSBatchRenderer
{
public:
    struct PassGroup
    {
        BSRenderPass* passes[5];
        unsigned int validPassBits;
    };
    struct Entry
    {
        unsigned int key;
        unsigned int index;
        Entry* next;
    };

    struct PassIndexNode;
    bool GetRenderPassIndex(unsigned int& key, int& slot, PassIndexNode*& position);
    bool AdvancePass(unsigned int& key, int& slot, PassIndexNode*& position);

    unsigned char unrecovered000[8];
    PassGroup* renderPass;
    unsigned char unrecovered010[0x1C];
    unsigned int capacity;
    unsigned char unrecovered030[8];
    Entry* sentinel;
    unsigned char unrecovered040[8];
    Entry* entries;
    unsigned char unrecovered050[0x1C];
    bool autoClearPasses;
};
