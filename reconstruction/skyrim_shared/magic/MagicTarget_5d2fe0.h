// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/MagicTarget.cpp:487 (MagicTarget::CheckResistance)
// MagicTarget, CheckResistance: GUESS(low)
#pragma once

// MagicItem, EffectItem, TESBoundObject: GUESS(low)
class MagicItem;
class EffectItem;
class TESBoundObject;

class MagicTarget
{
public:
    float CheckResistance(const MagicItem*, EffectItem*, TESBoundObject*) const;
};
