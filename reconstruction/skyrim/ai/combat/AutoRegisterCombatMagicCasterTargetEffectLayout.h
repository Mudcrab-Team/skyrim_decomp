// Source exposure: binary-analysis (RTTI inheritance and measured deletion sizes).
// Original declarations inferred from local RTTI; no external implementation copied.
// AutoRegisterCombatMagicCaster, CombatMagicCasterTargetEffect: EXE_RTTI
// AutoRegisterCombatMagicCasterTargetEffectLayout: GUESS(medium) STANDIN; layout-only spelling for the RTTI specialization
#pragma once
#include "AutoRegisterCombatObjectLayout.h"
namespace ResearchLayouts {
class CombatMagicCasterTargetEffect;
class AutoRegisterCombatMagicCasterTargetEffectLayout :
    public AutoRegisterCombatObjectLayout<CombatMagicCasterTargetEffect>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemMagic, CombatMagicCasterTargetEffect>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemShout, CombatMagicCasterTargetEffect>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemStaff, CombatMagicCasterTargetEffect>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemPotion, CombatMagicCasterTargetEffect>>,
    public AutoRegisterCombatObjectLayout<CombatInventoryItemMagicT<CombatInventoryItemScroll, CombatMagicCasterTargetEffect>> {
public:
    AutoRegisterCombatMagicCasterTargetEffectLayout();
    ~AutoRegisterCombatMagicCasterTargetEffectLayout() override;
};
static_assert(sizeof(AutoRegisterCombatMagicCasterTargetEffectLayout) == 48, "reconciled registration owner size");
}
