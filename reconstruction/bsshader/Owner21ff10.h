// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original; the Ctor body is written from the pinned image listing Stamped as a twin of matched 0x1525870 (bsshader/BSLightingShaderMaterialGlowmap): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Feature: GUESS(low)
// Owner21ff10: GUESS(low) STANDIN
// BSLightingShaderMaterialBase, unknownA0: GUESS(low) STANDIN
#pragma once
#include "BSLightingShaderMaterialGlowmap.h"

class Owner21ff10 : public BSLightingShaderMaterialBase
{
public:
    Owner21ff10();
    ~Owner21ff10() override;
    virtual BSShaderMaterial* Create();
    virtual void CopyMembers(BSShaderMaterial* a_other);
    virtual std::uint32_t ComputeCRC32(void);
    virtual Feature GetFeature() const;
    virtual void OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet);
    virtual void ClearTextures();
    virtual void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN);
    virtual void GetTextures(void);

    unsigned char padTwinA0[24];
    ZeroedU64 unknownA0;  // A0
};
static_assert(sizeof(Owner21ff10) == 0xc0, "size");
