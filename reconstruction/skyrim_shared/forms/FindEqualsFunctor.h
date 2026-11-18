// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// MatchCondition: Sibling source: fo4-private@1b765c70 src/Shared/Magic/MagicItem.cpp:161
// FindEqualsFunctor, FindEqualsFunctor::MatchCondition: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class FindEqualsFunctor
{
public:
    bool MatchCondition(EffectItem* item);
private:
    std::uint64_t unknown00[3];
    EffectItem* lookFor;
};
