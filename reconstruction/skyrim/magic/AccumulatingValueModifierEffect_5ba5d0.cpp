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
// 0x5e7410 ValueModifierEffect::ShouldModifyOnFinish
// 0x5ba590 AccumulatingValueModifierEffect::ShouldModifyOnStart
// 0x5ba5d0 AccumulatingValueModifierEffect::ShouldModifyOnUpdate
#include "AccumulatingValueModifierEffect_5ba5d0.h"
bool AccumulatingValueModifierEffect::ShouldModifyOnUpdate() const { if (ValueModifierEffect::ShouldModifyOnUpdate()) return true; if ((unsigned char)(GetBaseObject()->data.flags >> 30) & 1) return true; return false; }
