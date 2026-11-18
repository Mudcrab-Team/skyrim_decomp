// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSEffectShaderProperty: EXE_RTTI
// QShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// QShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiRTTI;
// NiRTTI_BSEffectShaderProperty: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the RTTI object at RVA 0x33d4dc0 that GetRTTI addresses, bound by hint
extern const NiRTTI NiRTTI_BSEffectShaderProperty;
// QShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BSEffectShaderProperty
{
public:
    virtual std::uint32_t QShader() const;
    // Unk_3C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the slot's listing returns true
    virtual bool Unk_3C() const;
    // GetMaterialType, GetRTTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual std::uint32_t GetMaterialType() const;
    virtual const NiRTTI* GetRTTI() const;
};
