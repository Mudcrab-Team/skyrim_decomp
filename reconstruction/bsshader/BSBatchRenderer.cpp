// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, GeometryGroup, geometryGroups, alphaGroup, batchRenderer, BSRenderPass, NiCamera: CRASHLOGGER_PDB(59818@2026.10.24)
// SortGroupPasses, SortPasses, currentRendererGroup, AppendPassToAlphaGroup, AppendPass, ClearRecycledPassNodes: GUESS(low)
// PassIndexNode, PassNodePool, passNodePool, Clear, Recycle: GUESS(low)
// 0x1560820 BSBatchRenderer::SortGroupPasses
// 0x1561200 BSBatchRenderer::ClearRecycledPassNodes
// 0x1561630 BSBatchRenderer::AppendPassToAlphaGroup
// CI hash: 0x1560820 ?SortGroupPasses@BSBatchRenderer@@QEAAXPEAVNiCamera@@I@Z
// CI hash: 0x1561200 ?ClearRecycledPassNodes@BSBatchRenderer@@SAXXZ
// CI hash: 0x1561630 ?AppendPassToAlphaGroup@BSBatchRenderer@@QEAAXPEAUBSRenderPass@@PEAUGeometryGroup@1@@Z
#include "BSBatchRenderer.h"

// The current renderer and each populated geometry group have their own passes.
void BSBatchRenderer::SortGroupPasses(NiCamera* camera, unsigned int group)
{
    if (group == currentRendererGroup) {
        SortPasses(camera);
    } else if (GeometryGroup* selected = geometryGroups[group]) {
        selected->batchRenderer->SortPasses(camera);
    }
}

// Release the recycled nodes after the pool head and reset its stored pass index.
void BSBatchRenderer::ClearRecycledPassNodes()
{
    PassIndexNode* head = passNodePool.head;
    if (head) {
        PassIndexNode* node = head->next;
        while (node) {
            PassIndexNode* following = node->next;
            node->next = nullptr;
            delete head->next;
            head->next = following;
            node = following;
        }
        head->pass = 0;
    }
}

// Use the active alpha group when the caller supplies no group.
void BSBatchRenderer::AppendPassToAlphaGroup(BSRenderPass* pass, GeometryGroup* group)
{
    if (!group) {
        group = alphaGroup;
    }
    group->AppendPass(pass, 0);
}
