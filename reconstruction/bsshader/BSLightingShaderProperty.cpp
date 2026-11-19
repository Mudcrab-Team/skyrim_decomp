// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. QShader is synthesized from the bounded leaf template; IsEqual is a one-statement body written from the local listing.
// BSLightingShaderProperty: EXE_RTTI
// QShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1518d60 BSLightingShaderProperty::IsEqual
// 0x1519130 BSLightingShaderProperty::QShader
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
