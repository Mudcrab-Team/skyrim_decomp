// Source exposure: mixed
// Origin: authorized sibling and community declarations
// ValueModifierEffect::IsCausingHealthDamage: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ValueModifierEffect.cpp:71
// ActiveEffect, ValueModifierEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/A/ActiveEffect.h and include/RE/V/ValueModifierEffect.h, include/RE/A/ActorValues.h, include/RE/A/ActiveEffectReferenceEffectController.h, include/RE/B/BSSoundHandle.h
// names: GUESS(low); signatures remain provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5e7000 ValueModifierEffect::IsCausingHealthDamage
#include "ValueModifierEffect.h"
bool ValueModifierEffect::IsCausingHealthDamage() {
    if (GetMagnitude() >= 0.0f) return false;
    return actorValue == 24 && ShouldModifyOnUpdate();
}
