// Source exposure: mixed (local binary analysis and public names).
// Code origin: Written for this reconstruction from the listing; names from the existing header and the public CommonLibSSE-NG layout.
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSLightingShaderProperty: EXE_RTTI
// QShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; offset measured
// pad08, pad40: GUESS(low); storage names invented for the measured member offsets
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// QMaterialAlpha, material, unk80, materialAlpha: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// baseTexture: GUESS(low); offset 0x48 measured from the getter listing
#pragma once
#include <cstdint>

// PropertyFlagHolder: STANDIN GUESS(low); the argument of Function14e8350 has a byte at 0x61
struct PropertyFlagHolder
{
    std::uint8_t unk00[0x61];
    std::uint8_t unk61;
};

// BSLightingShaderMaterialBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to baseTexture at 0x48 and materialAlpha at 0x80
class BSLightingShaderMaterialBase
{
public:
    std::uint8_t pad00[0x48];  // 00
    void* baseTexture;         // 48
    std::uint8_t pad50[0x30];  // 50
    float materialAlpha;       // 80
};

class BSLightingShaderProperty
{
public:
    virtual std::uint32_t QShader() const;
    // IsEqual: GUESS(low); parameter type unrecovered
    virtual bool IsEqual(void* a_object);  // compared: 0x1518d60
    // Function14e8350: GUESS(low); purpose unrecovered
    bool Function14e8350(const PropertyFlagHolder* a_other) const;
    virtual float QMaterialAlpha();  // NG slot 32

    std::uint8_t    pad08[0x30];  // 08
    std::uint64_t   flags;        // 38
    std::uint8_t    pad40[0x38];  // 40
    BSLightingShaderMaterialBase* material;  // 78
    std::uint64_t   unk80;        // 80
public:
    // compared: 0x151d520
    void* GetBaseTexture() const;
public:
    void SetMaterialAlpha(float a_alpha);
};
