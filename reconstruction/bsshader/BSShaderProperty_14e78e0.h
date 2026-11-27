// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSShaderProperty, RenderPassArray, AppendNew, BSRenderPass, BSShader, BSGeometry, BSLight, MakeRenderPass, SetNext, next, head, AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24)
// g_memoryContext_tls_0x768, renderPassMemoryContext: GUESS(low)
#pragma once

class BSGeometry;
class BSLight;
class BSShaderProperty;

struct BSRenderPass
{
    unsigned char unrecovered000[0x28];
    BSRenderPass* next;

    void SetNext(BSRenderPass* pass);
};

class BSShader
{
public:
    BSRenderPass* MakeRenderPass(
        BSShaderProperty* property,
        BSGeometry* geometry,
        unsigned int passEnum,
        unsigned char numLights,
        BSLight** lights);
};

class BSShaderProperty
{
public:
    struct RenderPassArray
    {
        BSRenderPass* head;

        BSRenderPass* AppendNew(
            BSShader* shader,
            BSShaderProperty* property,
            BSGeometry* geometry,
            unsigned int passEnum,
            unsigned char numLights,
            BSLight* light0,
            BSLight* light1,
            BSLight* light2,
            BSLight* light3);
    };
};

extern __declspec(thread) unsigned int g_memoryContext_tls_0x768;
