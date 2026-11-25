// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x152aa40 (bsshader/BSEffectShaderProperty): source copied, names replaced by placeholders.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBinaryStream, NiSourceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the code reads are modelled
// EffectMaterial: GUESS(low); names invented for the measured member offsets
// Function108c7b0, Owner108c7b0: GUESS(low) STANDIN
// QShader, Unk_3C, GetMaterialType, GetRTTI, GetBaseTexture, SetMaterialAlpha, QMaterialAlpha, pad08, pad30, pad38, material, pad80, readStream, writeStream: GUESS(low) STANDIN
#pragma once
#include "BSEffectShaderProperty.h"

class Owner108c7b0
{
public:
    virtual std::uint32_t QShader() const;
    // Unk_3C: the slot's listing returns true
    virtual bool Unk_3C() const;
    virtual std::uint32_t GetMaterialType() const;
    virtual const NiRTTI* GetRTTI() const;
    virtual NiSourceTexture* GetBaseTexture();
    virtual void SetMaterialAlpha(float alpha);
    virtual float QMaterialAlpha();
    void Function152aa00(void* buffer);
    void Function108c7b0(const void* buffer);
    std::uint8_t pad08[0x28];
    std::uint8_t pad30[8];
    std::uint8_t pad38[0x40];
    EffectMaterial* material;
    std::uint8_t pad80[0x218];
    NiBinaryStream* readStream;
    NiBinaryStream* writeStream;
};

