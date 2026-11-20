// Code origin: original; the listing and community declarations only
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSEffectShaderProperty: EXE_RTTI
// QShader, Unk_3C, GetMaterialType, GetRTTI, GetBaseTexture, SetMaterialAlpha, QMaterialAlpha: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBinaryStream, NiSourceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the code reads are modelled
// EffectMaterial, pad08, pad30, pad38, material, pad80, readStream, writeStream: GUESS(low); names invented for the measured member offsets
#pragma once
#include <cstdint>
class NiRTTI;
class NiSourceTexture;
// NiRTTI_BSEffectShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the RTTI object at RVA 0x33d4dc0 that GetRTTI addresses, bound by hint
extern const NiRTTI NiRTTI_BSEffectShaderProperty;
class NiBinaryStream {
public:
    virtual ~NiBinaryStream();
    using ReadFn = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    using WriteFn = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    std::uint32_t _absoluteCurrentPos;
    std::uint32_t _pad0C;
    ReadFn* _readFn;
    WriteFn* _writeFn;
};
class EffectMaterial {
public:
    std::uint8_t pad00[0x54];
    float alpha;
    NiSourceTexture* sourceTexture;
};
class BSEffectShaderProperty
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
    void Function152aa40(const void* buffer);
    std::uint8_t pad08[0x28];
    std::uint8_t pad30[8];
    std::uint8_t pad38[0x40];
    EffectMaterial* material;
    std::uint8_t pad80[0x218];
    NiBinaryStream* readStream;
    NiBinaryStream* writeStream;
};
