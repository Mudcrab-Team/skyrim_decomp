// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: AutoMemContext::AutoMemContext (sibling similarity noted below).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (allocation-context save and install).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShader::RestoreGeometry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSRenderPass, RenderPassImmediately_Skinned, BSShader, shader, AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24)
// PrepareGeometrySkinned, DrawPass, forceSkinning, g_memoryContext_tls_0x768, renderMemoryContext: GUESS(low)
// 0x1560a30 BSRenderPass::RenderPassImmediately_Skinned
#include "BSRenderPass_1560a30.h"

class AutoMemContext
{
public:
    explicit AutoMemContext(unsigned int context) : previous(g_memoryContext_tls_0x768)
    {
        g_memoryContext_tls_0x768 = context;
    }

    ~AutoMemContext()
    {
        g_memoryContext_tls_0x768 = previous;
    }

private:
    unsigned int previous;
};

// Prepare skinned geometry state, draw the pass, and restore shader state under the render memory context.
void BSRenderPass::RenderPassImmediately_Skinned(bool alpha, unsigned int flags)
{
    constexpr unsigned int renderMemoryContext = 26;
    AutoMemContext context(renderMemoryContext);
    BSShader* passShader = shader;
    PrepareGeometrySkinned(this, passShader, alpha || forceSkinning, flags);
    DrawPass();
    passShader->RestoreGeometry(this, flags);
}
