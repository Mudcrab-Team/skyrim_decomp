// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// ActiveEffect::ShouldDispelOnDeath: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:238
// ActiveEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/A/ActiveEffect.h and include/RE/A/ActiveEffectReferenceEffectController.h, include/RE/E/Effect.h, include/RE/E/EffectSetting.h, include/RE/T/TESForm.h, include/RE/T/TESFullName.h, include/RE/B/BGSMenuDisplayObject.h and include/RE/B/BGSKeywordForm.h.
// names: GUESS(low); original source names are uncertain.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5bcb70 ActiveEffect::ShouldDispelOnDeath
#include "ActiveEffect.h"
bool ActiveEffect::ShouldDispelOnDeath() const { return !(effect->baseEffect->flags & 0x10000000); }
