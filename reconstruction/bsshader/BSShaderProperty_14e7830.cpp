// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSShaderProperty, RenderPassArray, TrimAfter, BSRenderPass, next, head, SetNext, ClearRenderPass: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x14e7830 BSShaderProperty::RenderPassArray::TrimAfter
#include "BSShaderProperty_14e7830.h"

// Release the passes after the retained pass, or the entire list when it is null.
void BSShaderProperty::RenderPassArray::TrimAfter(BSRenderPass* last)
{
    if (last) {
        BSRenderPass* pass = last->next;
        last->SetNext(nullptr);
        while (pass) {
            BSRenderPass* next = pass->next;
            BSRenderPass::ClearRenderPass(pass);
            pass = next;
        }
    } else {
        BSRenderPass* pass = head;
        while (pass) {
            BSRenderPass* next = pass->next;
            BSRenderPass::ClearRenderPass(pass);
            pass = next;
        }
        head = nullptr;
    }
}
