// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterSummon: EXE_RTTI
// AutoRegisterCombatMagicCasterSummonLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterSummon;
class AutoRegisterCombatMagicCasterSummonLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterSummon>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterSummon>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterSummon>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterSummon>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterSummon>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterSummon>> {
public:
    AutoRegisterCombatMagicCasterSummonLayout();
    ~AutoRegisterCombatMagicCasterSummonLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterSummonLayout) == 48, "reconciled registration owner size");
}
