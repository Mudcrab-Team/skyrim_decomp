// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterLight: EXE_RTTI
// AutoRegisterCombatMagicCasterLightLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterLight;
class AutoRegisterCombatMagicCasterLightLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterLight>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterLight>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterLight>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterLight>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterLight>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterLight>> {
public:
    AutoRegisterCombatMagicCasterLightLayout();
    ~AutoRegisterCombatMagicCasterLightLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterLightLayout) == 48, "reconciled registration owner size");
}
