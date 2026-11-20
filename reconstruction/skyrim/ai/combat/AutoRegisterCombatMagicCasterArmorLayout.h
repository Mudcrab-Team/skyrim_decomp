// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterArmor: EXE_RTTI
// AutoRegisterCombatMagicCasterArmorLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterArmor;
class AutoRegisterCombatMagicCasterArmorLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterArmor>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterArmor>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterArmor>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterArmor>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterArmor>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterArmor>> {
public:
    AutoRegisterCombatMagicCasterArmorLayout();
    ~AutoRegisterCombatMagicCasterArmorLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterArmorLayout) == 48, "reconciled registration owner size");
}
