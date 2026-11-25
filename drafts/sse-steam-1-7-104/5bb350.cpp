// Near miss: 0.0 alignment distance | callee-missing
// Source exposure: mixed
// 0x5bb350 ActiveEffect::CheckDisplacementSpellOnTarget
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActiveEffect, MagicItem, MagicTarget, ForEachActiveEffectVisitor, VisitEffects, Accept, spell, target, displacementSpell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CheckDisplacementSpellOnTarget: SYMBOLS(tesv-2013-map); candidate identity inferred from visited spells.
// DisplacementSpellVisitor, found: GUESS(low); visitor role inferred from construction.
#include "ActiveEffect_5bb350.h"

bool ActiveEffect::CheckDisplacementSpellOnTarget()
{
    if (target) {
        DisplacementSpellVisitor visitor(displacementSpell, spell);
        target->VisitEffects(visitor);
        return visitor.found;
    }
    return false;
}
