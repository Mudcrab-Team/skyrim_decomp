// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterDisarm: EXE_RTTI
// AutoRegisterCombatMagicCasterDisarmLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterDisarm;
class AutoRegisterCombatMagicCasterDisarmLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterDisarm>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterDisarm>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterDisarm>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterDisarm>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterDisarm>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterDisarm>> {
public:
    AutoRegisterCombatMagicCasterDisarmLayout();
    ~AutoRegisterCombatMagicCasterDisarmLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterDisarmLayout) == 48, "reconciled registration owner size");
}
