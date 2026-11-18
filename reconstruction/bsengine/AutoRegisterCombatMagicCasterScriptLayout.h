// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterScript: EXE_RTTI
// AutoRegisterCombatMagicCasterScriptLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterScript;
class AutoRegisterCombatMagicCasterScriptLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterScript>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterScript>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterScript>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterScript>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterScript>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterScript>> {
public:
    AutoRegisterCombatMagicCasterScriptLayout();
    ~AutoRegisterCombatMagicCasterScriptLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterScriptLayout) == 48, "reconciled registration owner size");
}
