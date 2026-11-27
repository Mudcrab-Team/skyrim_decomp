// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: AutoMemContext::AutoMemContext (sibling similarity noted below).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (allocation-context save and install).
// SPDX-License-Identifier: CC0-1.0
// BSShaderProperty, RenderPassArray, AppendNew, BSRenderPass, BSShader, BSGeometry, BSLight, MakeRenderPass, SetNext, next, head, AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24)
// g_memoryContext_tls_0x768, renderPassMemoryContext: GUESS(low)
// 0x14e78e0 BSShaderProperty::RenderPassArray::AppendNew
#include "BSShaderProperty_14e78e0.h"

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

// Allocate a new render pass and append it to the tail of the intrusive pass list.
BSRenderPass* BSShaderProperty::RenderPassArray::AppendNew(
    BSShader* shader,
    BSShaderProperty* property,
    BSGeometry* geometry,
    unsigned int passEnum,
    unsigned char numLights,
    BSLight* light0,
    BSLight* light1,
    BSLight* light2,
    BSLight* light3)
{
    constexpr unsigned int renderPassMemoryContext = 30;
    AutoMemContext context(renderPassMemoryContext);
    BSLight* lights[4] = { light0, light1, light2, light3 };
    BSRenderPass* pass = shader->MakeRenderPass(property, geometry, passEnum, numLights, lights);
    BSRenderPass* tail = head;
    if (tail) {
        while (tail->next) {
            tail = tail->next;
        }
        tail->SetNext(pass);
    } else {
        head = pass;
    }
    return pass;
}
