// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialEnvmap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialEnvmap::Ctor, BSLightingShaderMaterialEnvmap::SaveBinary, BSLightingShaderMaterialEnvmap::LoadBinary, BSLightingShaderMaterialEnvmap::ReceiveValuesFromRootMaterial, BSLightingShaderMaterialEnvmap::GetTextures, BSLightingShaderMaterialEnvmap::ComputeCRC32: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unkA0Texture, unkA8Texture, unkB0, pad_B4: GUESS(low)
// ComputeFlagHash: GUESS(low)
// Code origin: declarations follow CommonLibSSE-NG names; offsets, sizes and the compared bodies are read from the local listings.
#pragma once

#include <cstdint>
#include <cstddef>
#include "BSLightingShaderMaterialBase.h"

// BSTextureSet: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slots 00 to 24 are placeholders that keep the index of the call at 0x128
// Unk_XX: GUESS(low)
class BSTextureSet
{
public:
    virtual void Unk_00();  // 00
    virtual void Unk_01();  // 08
    virtual void Unk_02();  // 10
    virtual void Unk_03();  // 18
    virtual void Unk_04();  // 20
    virtual void Unk_05();  // 28
    virtual void Unk_06();  // 30
    virtual void Unk_07();  // 38
    virtual void Unk_08();  // 40
    virtual void Unk_09();  // 48
    virtual void Unk_0A();  // 50
    virtual void Unk_0B();  // 58
    virtual void Unk_0C();  // 60
    virtual void Unk_0D();  // 68
    virtual void Unk_0E();  // 70
    virtual void Unk_0F();  // 78
    virtual void Unk_10();  // 80
    virtual void Unk_11();  // 88
    virtual void Unk_12();  // 90
    virtual void Unk_13();  // 98
    virtual void Unk_14();  // A0
    virtual void Unk_15();  // A8
    virtual void Unk_16();  // B0
    virtual void Unk_17();  // B8
    virtual void Unk_18();  // C0
    virtual void Unk_19();  // C8
    virtual void Unk_1A();  // D0
    virtual void Unk_1B();  // D8
    virtual void Unk_1C();  // E0
    virtual void Unk_1D();  // E8
    virtual void Unk_1E();  // F0
    virtual void Unk_1F();  // F8
    virtual void Unk_20();  // 100
    virtual void Unk_21();  // 108
    virtual void Unk_22();  // 110
    virtual void Unk_23();  // 118
    virtual void Unk_24();  // 120
    virtual std::uint64_t Unk_25(std::uint32_t a_index);  // 128
};

// CRC32Calculator: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SizeOfSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SizeOf32: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the call address 0xce2240 is not checked against NG's relocation id
class CRC32Calculator
{
public:
    static void SizeOf32(std::uint32_t* a_out, std::uint64_t a_value, std::uint32_t a_seed);  // 0xce2240
    static void SizeOfSize(std::uint32_t* a_out, const void* a_data, std::uint32_t a_size);  // 0xce2510
};

// g_defaultEnvmapTexture: GUESS(low); default texture pointer at 0x3336430
extern NiPointer<NiSourceTexture> g_defaultEnvmapTexture;

class BSLightingShaderMaterialEnvmap : public BSLightingShaderMaterialBase
{
public:
    // GetFeature: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
    Feature GetFeature() const override;
    BSLightingShaderMaterialEnvmap();
    BSLightingShaderMaterialEnvmap* Ctor();  // compared: 0x1524a60
    void CopyMembers(BSShaderMaterial* a_other) override;  // compared: 0x1524c20
    void ClearTextures() override;  // compared: 0x1524e90
    virtual void SaveBinary(NiStream& a_stream);  // compared: 0x1525020
    virtual void LoadBinary(NiStream& a_stream);  // compared: 0x1525080
    // the image passes two extra pointer arguments that the base ignores; NG declares five parameters
    virtual void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN, void* a_unk6, void* a_unk7);  // compared: 0x1524f10
    // NG declares GetTextures() returning void; the image returns the count of filled slots and takes the output array in RDX
    std::uint32_t GetTextures(NiSourceTexture** a_textures);  // compared: 0x1524f80
    // compared: 0x1524ce0; NG declares no parameter, but the image reads a flag word from EDX
    std::uint32_t ComputeCRC32(std::uint32_t a_flags);
    std::uint32_t ComputeFlagHash(std::uint32_t a_flags);

    NiPointer<NiSourceTexture> unkA0Texture;  // A0
    NiPointer<NiSourceTexture> unkA8Texture;  // A8
    float                      unkB0;         // B0
    std::uint32_t              pad_B4;        // B4
};
static_assert(sizeof(BSLightingShaderMaterialEnvmap) == 0xB8, "BSLightingShaderMaterialEnvmap size");
