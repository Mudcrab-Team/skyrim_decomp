// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShader::RestoreGeometry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSRenderPass, RenderPassImmediately_Skinned, BSShader, shader, AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24)
// PrepareGeometrySkinned, DrawPass, forceSkinning, g_memoryContext_tls_0x768, renderMemoryContext: GUESS(low)
#pragma once

class BSShader
{
public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void RestoreGeometry(struct BSRenderPass* pass, unsigned int flags);
};

struct BSRenderPass
{
    BSShader* shader;

    void DrawPass();
    void RenderPassImmediately_Skinned(bool alpha, unsigned int flags);
};

void PrepareGeometrySkinned(BSRenderPass* pass, BSShader* shader, bool alpha, unsigned int flags);
extern bool forceSkinning;
extern __declspec(thread) unsigned int g_memoryContext_tls_0x768;
