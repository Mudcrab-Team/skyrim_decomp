// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActiveEffect, MagicItem, MagicTarget, ForEachActiveEffectVisitor, VisitEffects, Accept, spell, target, displacementSpell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CheckDisplacementSpellOnTarget: SYMBOLS(tesv-2013-map); candidate identity inferred from visited spells.
// DisplacementSpellVisitor, found: GUESS(low); visitor role inferred from construction.
// Minimal stand-ins retain only the visited spell inputs and result.

#pragma once
#include <cstddef>
class ActiveEffect;
class MagicItem;
class MagicTarget {
public:
    class ForEachActiveEffectVisitor {
    public:
        virtual ~ForEachActiveEffectVisitor() = default;
        virtual int Accept(ActiveEffect*) = 0;
    };
    void VisitEffects(ForEachActiveEffectVisitor& visitor);
};
class DisplacementSpellVisitor : public MagicTarget::ForEachActiveEffectVisitor {
public:
    DisplacementSpellVisitor(MagicItem* displacement, MagicItem* current)
        : displacementSpell(displacement), spell(current), found(false) {}
    ~DisplacementSpellVisitor() override {}
    int Accept(ActiveEffect*) override;
    MagicItem* displacementSpell;
    MagicItem* spell;
    bool found;
};
class ActiveEffect {
public:
    bool CheckDisplacementSpellOnTarget();
    unsigned char unknown00[0x40];
    MagicItem* spell;
    unsigned char unknown48[8];
    MagicTarget* target;
    unsigned char unknown58[0x10];
    MagicItem* displacementSpell;
};
static_assert(offsetof(ActiveEffect, spell) == 0x40, "accessed field offset");
static_assert(offsetof(ActiveEffect, target) == 0x50, "accessed field offset");
static_assert(offsetof(ActiveEffect, displacementSpell) == 0x68, "accessed field offset");
