// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// ActiveEffect::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:197
// ActiveEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/A/ActiveEffect.h and include/RE/A/ActiveEffectReferenceEffectController.h.
// names: GUESS(low); original source names are uncertain.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5bc0b0 ActiveEffect::Revert
#include "ActiveEffect.h"
void ActiveEffect::Revert(void*) { castingSource = 4; }
