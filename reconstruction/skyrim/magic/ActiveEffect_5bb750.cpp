// Source exposure: mixed (community headers; the pinned image listing; private sibling shape).
// Code origin: adapted from the private sibling; adapted bodies: ActiveEffect::ShouldUpdate, TestBit.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:216
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// 0x5bb750 ActiveEffect::ShouldUpdate
#include "ActiveEffect_5bb750.h"

namespace
{
    // TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
    inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
    {
        return ((a_flags >> a_bit) & 1) != 0;
    }
}

// An effect updates only while it is live, its spell type is one of the persistent kinds and its base
// effect recovers; then it needs a condition, a displacement spell or a dispel flag to keep running.
bool ActiveEffect::ShouldUpdate() const
{
    bool live = !TestBit(flags, 31);
    if (!live || !spell)
    {
        return live;
    }
    MagicSystem::SpellType spellType = spell->GetSpellType();
    if (spellType != MagicSystem::SpellType::kDisease && spellType != MagicSystem::SpellType::kAbility &&
        spellType != MagicSystem::SpellType::kAddiction)
    {
        return live;
    }
    if (!TestBit(effect->baseEffect->data.flags, 1))
    {
        return live;
    }
    std::uint32_t current = flags;
    if (!TestBit(current, 16))
    {
        return live;
    }
    return TestBit(current, 7) || displacementSpell || TestBit(current, 18);
}
