// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShader virtual interface and NiRefObject base: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RenderPassImmediately_Custom, BSRenderPass, shader, shaderProperty, GetNiProperty: CRASHLOGGER_PDB(59818@2026.10.24)
// BSShader::SetAlphaTestRef, ApplyAlphaState, DrawPass, flags: GUESS(low)
// 0x1560c80 RenderPassImmediately_Custom
// CI hash: 0x1560c80 ?RenderPassImmediately_Custom@@YAXPEAUBSRenderPass@@_NI@Z
#include "BSRenderPass_1560c80.h"
#include "BSGeometry_1560ae0.h"

void RenderPassImmediately_Custom(BSRenderPass* pass, bool, unsigned int flags)
{
    pass->DrawCustomGeometry(flags);
}
