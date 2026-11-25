// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShader virtual interface and NiRefObject base: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RenderPassImmediately_Custom, BSRenderPass, shader, shaderProperty, GetNiProperty: CRASHLOGGER_PDB(59818@2026.10.24)
// BSShader::SetAlphaTestRef, ApplyAlphaState, DrawPass, flags: GUESS(low)
#pragma once

class BSShader;
class NiAlphaProperty;
struct BSShaderProperty;
class BSGeometry;

struct BSRenderPass
{
    BSShader* shader;
    BSShaderProperty* shaderProperty;
    BSGeometry* geometry;
    unsigned int passEnum;
    unsigned char accumulationHint;
    unsigned char extraParam;
    unsigned char lodMode;
    NiAlphaProperty* GetNiProperty();
    void DrawPass();
    void DrawStandardGeometry(bool alpha, unsigned int flags);
    void DrawCustomGeometry(unsigned int flags);
};

void RenderPassImmediately_Custom(BSRenderPass* pass, bool alpha, unsigned int flags);
