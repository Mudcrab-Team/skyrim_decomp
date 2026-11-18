// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// BSParticleShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSParticleShaderProperty::GetBaseTexture, BSParticleShaderProperty::SetupGeometry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSParticleShaderProperty::particleShaderTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG declares NiPointer<NiSourceTexture>, a raw pointer here, same size
// BSParticleShaderProperty::particleShaderGeometry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG declares NiPointer<BSParticleShaderGeometry>, the compared code stores the BSGeometry* parameter as given
// BSGeometry: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declaration only
// unknown88, unknown148, unknown170: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "BSShaderProperty.h"

class BSGeometry;

class BSParticleShaderProperty : public BSShaderProperty
{
public:
    virtual std::uint32_t QShader() const;
    virtual NiSourceTexture* GetBaseTexture();  // compared: 0x1533bd0
    virtual bool SetupGeometry(BSGeometry* a_geometry);  // compared: 0x1532ca0

    std::uint8_t     unknown88[0xB8];       // 88
    NiSourceTexture* particleShaderTexture;  // 140
    std::uint8_t     unknown148[0x20];      // 148
    BSGeometry*      particleShaderGeometry;  // 168
    std::uint8_t     unknown170[0x28];      // 170
};
static_assert(sizeof(BSParticleShaderProperty) == 0x198, "BSParticleShaderProperty size");
