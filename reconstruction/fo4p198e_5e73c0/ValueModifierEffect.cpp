// Source exposure: mixed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// ValueModifierEffect::Update: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ValueModifierEffect.cpp:157
// ValueModifierEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/V/ValueModifierEffect.h.
// names: GUESS(low); method signatures and local names are inferred.
// 0x5e73c0 ValueModifierEffect::Update
#include "ValueModifierEffect.h"
void ValueModifierEffect::Update(float seconds) { if (ShouldModifyOnUpdate()) ModifyOnUpdate(seconds); ResearchLayouts::ActiveEffectLayout::DoStandardCustomSkillUsage(seconds); }
