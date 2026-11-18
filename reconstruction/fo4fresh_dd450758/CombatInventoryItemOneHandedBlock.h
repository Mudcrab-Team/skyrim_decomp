// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// CalculateScore: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:409
// CombatInventoryItemOneHandedBlock, CombatInventoryItemOneHandedBlock::CalculateScore: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class CombatInventoryItemOneHandedBlock
{
public:
    float CalculateScore(CombatController*) const;
private:
    std::uint64_t unknown00[3];
    float score;
};
