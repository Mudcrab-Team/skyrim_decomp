// Source exposure: mixed (community declarations and local RTTI analysis).
// Declaration source: include/RE/B/BSShader.h
// BSShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ShaderBaseLayout: GUESS(medium) STANDIN
// Original declarations derived from the pinned community sources. No implementation bodies copied. Omitted methods are not reconstructed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "ShaderRefLayout.h"
#include "gamebryo/nimain/NiBoneMatrixSetterLayout.h"
#include "ReloadShaderLayout.h"
#include "ShaderTableLayout.h"
namespace ResearchLayouts {
class ShaderBaseLayout : public ShaderRefLayout, public NiBoneMatrixSetterLayout, public ReloadShaderLayout {
public:
    ShaderBaseLayout();
    ~ShaderBaseLayout() override;
    std::int32_t shaderType;
    ShaderTableLayout vertexShaders;
    ShaderTableLayout pixelShaders;
    const char* fxpFilename;
};
static_assert(sizeof(ShaderBaseLayout) == 0x90, "shader represented size");
static_assert(offsetof(ShaderBaseLayout, shaderType) == 0x20, "shader type offset");
static_assert(offsetof(ShaderBaseLayout, vertexShaders) == 0x28, "vertex table offset");
static_assert(offsetof(ShaderBaseLayout, pixelShaders) == 0x58, "pixel table offset");
static_assert(offsetof(ShaderBaseLayout, fxpFilename) == 0x88, "filename offset");
}
