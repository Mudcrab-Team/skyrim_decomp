// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// CureEffect::Start: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/CureEffect.cpp:58
// ActiveEffect, CureEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/A/ActiveEffect.h and include/RE/A/ActiveEffectReferenceEffectController.h and include/RE/C/CureEffect.h.
// names: GUESS(low); original source names are uncertain.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5c5580 CureEffect::Start
#include "CureEffect.h"
void CureEffect::Start() { if (archetypeID == -1) target->Dispel(spellType); else target->Dispel(archetypeID, false); }
