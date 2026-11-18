// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterOffensive: EXE_RTTI
// AutoRegisterCombatMagicCasterOffensiveLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterOffensive;
class AutoRegisterCombatMagicCasterOffensiveLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterOffensive>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterOffensive>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterOffensive>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterOffensive>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterOffensive>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterOffensive>> {
public:
    AutoRegisterCombatMagicCasterOffensiveLayout();
    ~AutoRegisterCombatMagicCasterOffensiveLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterOffensiveLayout) == 48, "reconciled registration owner size");
}
