// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original; the Ctor body is written from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialGlowmap and its virtuals: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSLightingShaderMaterialBase: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// Feature, unknownA0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSLightingShaderMaterialBase
{
public:
    BSLightingShaderMaterialBase();
    virtual ~BSLightingShaderMaterialBase();
    std::uint8_t data[0x98];  // 08
};
static_assert(sizeof(BSLightingShaderMaterialBase) == 0xA0, "base size");

class BSShaderMaterial;
class BSTextureSet;

struct Feature { std::uint32_t value; };

// ZeroedU64: GUESS(low); the member at A0 is zero-initialized by its own inline constructor.
struct ZeroedU64 { std::uint64_t value; ZeroedU64() : value(0) {} };

class BSLightingShaderMaterialGlowmap : public BSLightingShaderMaterialBase
{
public:
    BSLightingShaderMaterialGlowmap();
    ~BSLightingShaderMaterialGlowmap() override;
    virtual BSShaderMaterial* Create();
    virtual void CopyMembers(BSShaderMaterial* a_other);
    virtual std::uint32_t ComputeCRC32(void);
    virtual Feature GetFeature() const;
    virtual void OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet);
    virtual void ClearTextures();
    virtual void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN);
    virtual void GetTextures(void);

    ZeroedU64 unknownA0;  // A0
};
static_assert(sizeof(BSLightingShaderMaterialGlowmap) == 0xA8, "size");
