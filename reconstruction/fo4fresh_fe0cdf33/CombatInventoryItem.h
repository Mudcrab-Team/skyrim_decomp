// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetMinRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:88
// GetMaxRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:90
// GetOptimalRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:92
// GetEquipRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:94
// CombatInventoryItem, CombatInventoryItem::GetMinRange, CombatInventoryItem::GetMaxRange, CombatInventoryItem::GetOptimalRange, CombatInventoryItem::GetEquipRange: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, health, lookFor, inheritRotation, minRange, maxRange, score, artObject: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class CombatController;
class EffectItem;
class NiAVObject;
class CombatInventoryItem
{
public:
    float GetMinRange() const;
    float GetMaxRange() const;
    float GetOptimalRange() const;
    float GetEquipRange() const;
};
