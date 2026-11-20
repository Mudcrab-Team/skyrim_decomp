// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// CalcCastMagicChance: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:46
// CalcMagicHoldTime: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:52
// CombatMagicCaster, CombatMagicCaster::CalcCastMagicChance, CombatMagicCaster::CalcMagicHoldTime: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class CombatMagicCaster
{
public:
    float CalcCastMagicChance(const CombatController*) const;
    float CalcMagicHoldTime(const CombatController*) const;
};
