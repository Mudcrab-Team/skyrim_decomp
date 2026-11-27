// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSShaderProperty, RenderPassArray, TrimAfter, BSRenderPass, next, head, SetNext, ClearRenderPass: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

struct BSRenderPass
{
    void SetNext(BSRenderPass* pass);
    static void ClearRenderPass(BSRenderPass* pass);
    unsigned char unrecovered000[0x28];
    BSRenderPass* next;
};

class BSShaderProperty
{
public:
    struct RenderPassArray
    {
        void TrimAfter(BSRenderPass* last);
        BSRenderPass* head;
    };
};
