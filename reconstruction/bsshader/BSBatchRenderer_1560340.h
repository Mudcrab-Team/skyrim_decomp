// Source exposure: mixed (pinned-image listing and community declarations).
// Code origin: original reconstruction from the local listing.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSBatchRenderer, SetupAndDrawPass, AutoMemContext, BSRenderPass, BSShaderProperty, material: CRASHLOGGER_PDB(59818@2026.10.24)
// SetupPassTechnique, currentShader, currentTechnique, currentMaterial, requestedTechnique, forceSkinning, RenderSkinned, g_memoryContext_tls_0x768, forceSetupTechnique, customDrawFlag, renderMemoryContext: GUESS(low)
#pragma once
#include "BSGeometry_1560ae0.h"

class BSBatchRenderer
{
public:
    static void SetupAndDrawPass(BSRenderPass* pass, unsigned int technique, bool alpha, unsigned int flags);
};
extern BSShader* currentShader;
extern unsigned int currentTechnique;
extern BSShaderMaterial* currentMaterial;
extern unsigned int requestedTechnique;
extern bool forceSkinning;
extern __declspec(thread) unsigned int g_memoryContext_tls_0x768;
