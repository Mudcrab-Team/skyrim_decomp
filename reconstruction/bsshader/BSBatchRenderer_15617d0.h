// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, AppendPassToAlphaGroupSorted, GeometryGroup, batchRenderer, head, tail, alphaGroup, passList, BSRenderPass, PersistentPassList: CRASHLOGGER_PDB(59818@2026.10.24)
// AppendSorted, sortMode: GUESS(low)
#pragma once

struct BSRenderPass;
struct PersistentPassList
{
    void AppendSorted(BSRenderPass* pass, unsigned char sortMode, bool flag);

    BSRenderPass* head;
    BSRenderPass* tail;
};

class BSBatchRenderer
{
public:
    struct GeometryGroup
    {
        BSBatchRenderer* batchRenderer;
        PersistentPassList passList;
    };

    void AppendPassToAlphaGroupSorted(BSRenderPass* pass, unsigned char sortMode);

    unsigned char unrecovered000[0xF0];
    GeometryGroup* alphaGroup;
};
