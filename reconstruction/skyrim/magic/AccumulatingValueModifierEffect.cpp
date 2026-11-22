// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// 0x5ba3d0 AccumulatingValueModifierEffect::Function5ba3d0
// Adapted bodies: none
// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// ValueModifierEffect::ShouldModifyOnFinish, AccumulatingValueModifierEffect::ShouldModifyOnStart, AccumulatingValueModifierEffect::ShouldModifyOnUpdate: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ValueModifierEffect.cpp:165
// Sibling source: fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp:75
// Sibling source: fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp:81
// EffectSetting, ActiveEffect, ValueModifierEffect, AccumulatingValueModifierEffect: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/E/EffectSetting.h, include/RE/A/ActiveEffect.h, include/RE/V/ValueModifierEffect.h and include/RE/A/AccumulatingValueModifierEffect.h.
// TESForm: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#include "AccumulatingValueModifierEffect.h"

void AccumulatingValueModifierEffect::Function5ba3d0()
{
    valueA0 = g_defaultAccumulateValue;
}

bool ValueModifierEffect::ShouldModifyOnFinish() const { return (GetBaseObject()->data.flags & 2u) != 0; }
bool AccumulatingValueModifierEffect::ShouldModifyOnStart() { return ValueModifierEffect::ShouldModifyOnStart() && (GetBaseObject()->data.flags & 0x40000000u) == 0; }
bool AccumulatingValueModifierEffect::ShouldModifyOnUpdate() const { return ValueModifierEffect::ShouldModifyOnUpdate() || (GetBaseObject()->data.flags & 0x40000000u) != 0; }
