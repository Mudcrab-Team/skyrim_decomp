// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. QShader is synthesized from the bounded leaf template; the other bodies are written from the local listing.
// BSLightingShaderProperty: EXE_RTTI
// QShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// pad08, pad40: GUESS(low); storage names invented for the measured offsets
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14e8350 BSLightingShaderProperty::Function14e8350
// 0x1518d60 BSLightingShaderProperty::IsEqual
// 0x1519130 BSLightingShaderProperty::QShader
// 0x151d550 BSLightingShaderProperty::QMaterialAlpha
// QMaterialAlpha: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#include "BSLightingShaderProperty.h"
// QShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t BSLightingShaderProperty::QShader() const
{
    return 0xb;
}

bool BSLightingShaderProperty::IsEqual(void*)
{
    return false;
}

bool BSLightingShaderProperty::Function14e8350(const PropertyFlagHolder* a_other) const
{
    if (!a_other->unk61) {
        const std::uint64_t current = flags;
        if ((current & 0x4000) > 0) {
            return false;
        }
        if ((0x400000000000 & current) > 0) {
            return false;
        }
    }
    return true;
}

float BSLightingShaderProperty::QMaterialAlpha()
{
    return material->materialAlpha;
}
