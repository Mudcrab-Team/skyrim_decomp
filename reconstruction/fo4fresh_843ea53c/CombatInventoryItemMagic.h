// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetMinRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:383
// GetMaxRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:385
// CombatInventoryItemMagic, CombatInventoryItemMagic::GetMinRange, CombatInventoryItemMagic::GetMaxRange: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class CombatInventoryItemMagic
{
public:
    float GetMinRange() const;
    float GetMaxRange() const;
private:
    std::uint64_t unknown00[6];
    float minRange;
    float maxRange;
};
