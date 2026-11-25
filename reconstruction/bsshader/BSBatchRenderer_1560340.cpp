// Source exposure: mixed (pinned-image listing and community declarations).
// Code origin: original reconstruction from the local listing.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSBatchRenderer, SetupAndDrawPass, AutoMemContext, BSRenderPass, BSShaderProperty, material: CRASHLOGGER_PDB(59818@2026.10.24)
// SetupPassTechnique, currentShader, currentTechnique, currentMaterial, requestedTechnique, forceSkinning, RenderSkinned, g_memoryContext_tls_0x768, forceSetupTechnique, customDrawFlag, renderMemoryContext: GUESS(low)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// 0x1560340 BSBatchRenderer::SetupAndDrawPass
// CI hash: 0x1560340 ?SetupAndDrawPass@BSBatchRenderer@@SAXPEAUBSRenderPass@@I_NI@Z
#include "BSBatchRenderer_1560340.h"

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

static void RenderSkinned(BSRenderPass* pass, bool alpha, unsigned int flags)
{
    constexpr unsigned int renderMemoryContext = 26;
    AutoMemContext context(renderMemoryContext);
    BSShader* shader = pass->shader;
    PrepareGeometry(pass, shader, alpha || forceSkinning, flags);
    pass->DrawPass();
    shader->RestoreGeometry(pass, flags);
}

static bool SetupPassTechnique(BSShader* shader, unsigned int technique)
{
    constexpr unsigned int forceSetupTechnique = 0x5C006076;
    if (currentTechnique != technique || technique == forceSetupTechnique || shader != currentShader) {
        requestedTechnique = technique;
        if (currentShader) {
            currentShader->RestoreTechnique(currentTechnique);
        }
        currentShader = nullptr;
        currentTechnique = 0;
        currentMaterial = nullptr;
        if (shader->SetupTechnique(technique)) {
            currentShader = shader;
            currentTechnique = technique;
        } else {
            return false;
        }
    }
    return true;
}

void BSBatchRenderer::SetupAndDrawPass(BSRenderPass* pass, unsigned int technique, bool alpha, unsigned int flags)
{
    constexpr unsigned char customDrawFlag = 8;
    BSShader* shader = pass->shader;
    BSGeometry* geometry = pass->geometry;
    if (SetupPassTechnique(shader, technique)) {
        auto* material = pass->shaderProperty ? pass->shaderProperty->material : nullptr;
        if (material != currentMaterial) {
            if (material) {
                shader->SetupMaterial(material);
            }
            currentMaterial = material;
        }
        // The geometry keeps its LOD mode and custom-draw flag in adjacent bytes.
        geometry->unk108 = pass->lodMode;
        if (geometry->skinInstance) {
            pass->DrawStandardGeometry(alpha, flags);
        } else if (geometry->unk109[0] & customDrawFlag) {
            pass->DrawCustomGeometry(flags);
        } else {
            RenderSkinned(pass, alpha, flags);
        }
    } else {
        currentShader = nullptr;
        currentTechnique = 0;
    }
}
