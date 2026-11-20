// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetMaxRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:370
// CombatInventoryItemTorch, CombatInventoryItemTorch::GetMaxRange: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class CombatInventoryItemTorch
{
public:
    float GetMaxRange() const;
private:
    std::uint64_t unknown00[6];
    float maxRange;
};
