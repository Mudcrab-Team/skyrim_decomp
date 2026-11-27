// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed (pinned-image listing and community declarations).
// Code origin: original reconstruction from the local listing.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSGeometry virtuals, BSShader virtuals, BSDynamicTriShape and dataSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RenderPassImmediately_Standard, BSRenderPass, BSShader, Partition, numBones, NiSkinPartition_DrawContext, SetBoneMatrices, BSGraphics::Renderer, MapDynamicBuffer, world, skinInstance: CRASHLOGGER_PDB(59818@2026.10.24)
// PrepareDraw, PrepareGeometry, LockGeometry, UnlockGeometry, CopyGeometryData, DrawPass, UnmapDynamicBuffer, Draw, flags, renderer: GUESS(low)
// 0x1560ae0 RenderPassImmediately_Standard
// CI hash: 0x1560ae0 ?RenderPassImmediately_Standard@@YAXPEAUBSRenderPass@@_NI@Z
#include "BSGeometry_1560ae0.h"

void RenderPassImmediately_Standard(BSRenderPass* pass, bool alpha, unsigned int flags)
{
    pass->DrawStandardGeometry(alpha, flags);
}
