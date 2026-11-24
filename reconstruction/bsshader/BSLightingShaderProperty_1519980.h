// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderProperty, BSLightingShaderMaterialBase, flags, material, OnLoadTextureSet: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTextureSet: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class BSTextureSet;

// BSLightingShaderMaterialBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the slot used here
class BSLightingShaderMaterialBase
{
public:
    // Unk_00, Unk_01, Unk_02, Unk_03, Unk_04, Unk_05, Unk_06, Unk_07: GUESS(low); placeholders for earlier slots
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    // a_modelSpaceNormals: GUESS(low); the image passes a third argument NG does not declare
    virtual void OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet, bool a_modelSpaceNormals);  // 08
};

class BSLightingShaderProperty
{
public:
    void OnLoadTextureSet(std::uint64_t a_arg1);  // compared: 0x1519980

    std::uint8_t                  pad00[0x38];  // 00
    std::int64_t                  flags;        // 38; NG declares an unsigned enumeration, the image compares the masked value as signed
    std::uint8_t                  pad40[0x38];  // 40
    BSLightingShaderMaterialBase* material;     // 78
};
static_assert(offsetof(BSLightingShaderProperty, material) == 0x78, "material offset");
