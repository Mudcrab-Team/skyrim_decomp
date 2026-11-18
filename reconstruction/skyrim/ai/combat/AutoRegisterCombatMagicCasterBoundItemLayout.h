// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterBoundItem: EXE_RTTI
// AutoRegisterCombatMagicCasterBoundItemLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterBoundItem;
class AutoRegisterCombatMagicCasterBoundItemLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterBoundItem>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterBoundItem>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterBoundItem>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterBoundItem>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterBoundItem>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterBoundItem>> {
public:
    AutoRegisterCombatMagicCasterBoundItemLayout();
    ~AutoRegisterCombatMagicCasterBoundItemLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterBoundItemLayout) == 48, "reconciled registration owner size");
}
