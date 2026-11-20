// Source exposure: mixed (community declarations and local RTTI analysis).
// Declaration source: include/RE/B/BSImagespaceShader.h
// BSImagespaceShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImagespaceShaderLayout: GUESS(medium) STANDIN
// Original declarations derived from the pinned community sources. No implementation bodies copied. Omitted methods are not reconstructed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "ShaderBaseLayout.h"
#include "ImageEffectLayout.h"
namespace ResearchLayouts {
class ImagespaceShaderLayout : public ShaderBaseLayout, public ImageEffectLayout {
public:
    ImagespaceShaderLayout();
    ~ImagespaceShaderLayout() override;
    std::uint64_t unknown120;
    std::uint64_t unknown128;
    std::uint64_t unknown130;
    std::uint64_t unknown138;
    std::uint64_t unknown140;
    std::uint64_t unknown148;
    std::uint64_t unknown150;
    std::uint64_t unknown158;
    std::uint64_t unknown160;
    std::uint64_t unknown168;
    std::uint64_t unknown170;
    std::uint64_t unknown178;
    std::uint64_t unknown180;
    std::uint64_t unknown188;
    std::uint64_t unknown190;
    std::uint64_t unknown198;
    std::uint64_t unknown1A0;
};
static_assert(sizeof(ImagespaceShaderLayout) == 0x1A8, "imagespace shader represented size");
static_assert(offsetof(ImagespaceShaderLayout, unknown120) == 0x120, "imagespace data offset");
}
