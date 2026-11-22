// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the ModifyWeaponValue body is written from the pinned image listing
// 0x420c40 EnchantmentItem::ModifyWeaponValue
// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// EnchantmentItem: EXE_RTTI
// GetAssociatedSkill: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#include "EnchantmentItem.h"

// Scale and bias the weapon value; a zero base contributes nothing.
float EnchantmentItem::ModifyWeaponValue(float a_value, float a_scale, float a_bias)
{
    if (a_value == 0.0f)
        return 0.0f;
    return a_value + kWeaponValueScale * a_scale + kWeaponValueBias * a_bias;
}

// GetAssociatedSkill: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t EnchantmentItem::GetAssociatedSkill() const
{
    return 0x17;
}
