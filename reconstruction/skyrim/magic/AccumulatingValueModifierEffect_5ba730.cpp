// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// AccumulatingValueModifierEffect::ModifyOnFinish: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp:123
// AccumulatingValueModifierEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/A/AccumulatingValueModifierEffect.h, include/RE/V/ValueModifierEffect.h and include/RE/A/ActiveEffect.h.
// names: GUESS(low); method signature and argument names are inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5ba730 AccumulatingValueModifierEffect::ModifyOnFinish
#include "AccumulatingValueModifierEffect_5ba730.h"
void AccumulatingValueModifierEffect::ModifyOnFinish(Actor* caster, Actor* target, float) { magnitude = accumulatedMagnitude; ValueModifierEffect::ModifyOnFinish(caster, target, GetMagnitude()); }
