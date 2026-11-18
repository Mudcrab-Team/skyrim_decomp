// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterParalyze: EXE_RTTI
// AutoRegisterCombatMagicCasterParalyzeLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterParalyze;
class AutoRegisterCombatMagicCasterParalyzeLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterParalyze>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterParalyze>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterParalyze>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterParalyze>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterParalyze>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterParalyze>> {
public:
    AutoRegisterCombatMagicCasterParalyzeLayout();
    ~AutoRegisterCombatMagicCasterParalyzeLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterParalyzeLayout) == 48, "reconciled registration owner size");
}
