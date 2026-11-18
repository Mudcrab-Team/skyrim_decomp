// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterInvisibility: EXE_RTTI
// AutoRegisterCombatMagicCasterInvisibilityLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterInvisibility;
class AutoRegisterCombatMagicCasterInvisibilityLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterInvisibility>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterInvisibility>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterInvisibility>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterInvisibility>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterInvisibility>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterInvisibility>> {
public:
    AutoRegisterCombatMagicCasterInvisibilityLayout();
    ~AutoRegisterCombatMagicCasterInvisibilityLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterInvisibilityLayout) == 48, "reconciled registration owner size");
}
